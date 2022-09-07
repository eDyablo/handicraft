#include <algorithm>
#include <chrono>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <mutex>
#include <queue>
#include <sstream>
#include <string_view>
#include <thread>
#include <vector>

using ::std::atomic;
using ::std::condition_variable;
using ::std::cout;
using ::std::function;
using ::std::future;
using ::std::lock_guard;
using ::std::mutex;
using ::std::packaged_task;
using ::std::queue;
using ::std::size;
using ::std::string_view;
using ::std::stringstream;
using ::std::thread;
using ::std::unique_lock;
using ::std::vector;
using namespace ::std::chrono_literals;
using namespace ::std::this_thread;

struct thread_pool_executor_t {
  using function_t = function<void()>;
  using task_t = packaged_task<void()>;

  thread_pool_executor_t(size_t number) : stop_requested(false) {
    for (size_t i = 0; i < number; ++i) {
      threads.push_back(thread(&thread_pool_executor_t::worker, this));
    }
  }

  ~thread_pool_executor_t() {
    stop_requested.store(true);
    for (auto& worker_thread : threads) {
      if (worker_thread.joinable()) {
        worker_thread.join();
      }
    }
  }

  future<void> enque(function_t function) {
    task_t task(function);
    future<void> result = task.get_future();
    {
      lock_guard guard(tasks_mutex);
      tasks.push(move(task));
    }
    tasks_condition.notify_one();
    return result;
  }

 private:
  void log(string_view const& message) {
    stringstream stream;
    stream << "[" << get_id() << "] " << message << "\n";
    cout << stream.str();
  }

  void worker() {
    log("worker started");
    while (!stop_requested.load()) {
      task_t task;
      {
        unique_lock<mutex> lock(tasks_mutex);
        tasks_condition.wait(lock, [this] { return !this->tasks.empty() || this->stop_requested.load(); });
        if (stop_requested.load())
          continue;
        task = move(tasks.front());
        tasks.pop();
      }
      task();
      // sleep_for(1ms);
    }
    log("worker completed");
  }

  atomic<bool> stop_requested;
  condition_variable tasks_condition;
  mutex tasks_mutex;
  queue<task_t> tasks;
  vector<thread> threads;
};

int main() {
  thread_pool_executor_t pool(5);
  //sleep_for(1s);
  auto result = pool.enque([]() { cout << "hi\n"; });
  // sleep_for(1s);
  result.get();
  return 0;
}
