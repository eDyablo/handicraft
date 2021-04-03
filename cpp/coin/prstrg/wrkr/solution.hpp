#include <algorithm>
#include <functional>
#include <vector>

namespace coin {
  namespace prstrg {
    using work_t = std::function<void()>;
    using completion_t = std::function<void()>;

    struct worker_t {
      worker_t(work_t work) : work(work) {}

      void start(completion_t completion) {
        work();
        completion();
      }

     private:
      work_t work;
    };

    struct multiworker_t {
      void add(work_t work) { workers.emplace_back(work); }

      void start(completion_t when_done) {
        using namespace std;
        completion = when_done;
        in_progress_count = size(workers);
        for (auto& worker : workers) {
          worker.start([this]() { all_completed(); });
        }
      }

     private:
      void all_completed() {
        if (--in_progress_count == 0) {
          completion();
        }
      }

     private:
      std::vector<worker_t> workers;
      completion_t completion;
      size_t in_progress_count;
    };
  }  // namespace prstrg
}  // namespace coin
