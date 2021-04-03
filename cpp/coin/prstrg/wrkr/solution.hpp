#include <algorithm>
#include <functional>
#include <thread>
#include <vector>

namespace coin {
  namespace prstrg {
    using work_t = std::function<void()>;
    using completion_t = std::function<void(size_t)>;
    using thread_t = std::thread;

    struct worker_t {
      worker_t(work_t work, size_t id = 0) : work(work), id(id) {}

      void start(completion_t completion) {
        auto id = this->id;
        auto action = work;
        auto thread = thread_t([id, action, completion]() {
          for (size_t i = 0; i < 5; ++i) {
            action();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
          }
          completion(id);
        });
        thread.detach();
      }

     private:
      work_t work;
      size_t id;
    };

    struct multiworker_t {
      void add(work_t work) { workers.emplace_back(work, size(workers) + 1); }

      void start(completion_t when_done) {
        using namespace std;
        completion = when_done;
        in_progress_count = size(workers);
        for (auto& worker : workers) {
          worker.start([this](size_t id) { all_completed(id); });
        }
      }

     private:
      void all_completed(size_t id) {
        if (--in_progress_count == 0) {
          completion(id);
        }
      }

     private:
      std::vector<worker_t> workers;
      completion_t completion;
      size_t in_progress_count;
    };
  }  // namespace prstrg
}  // namespace coin
