/*
https://superfastpython.com/thread-spinlock-in-python/
*/
#include <chrono>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

struct task_t {
  std::string name;
  std::timed_mutex &monitor;
  void operator()() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::unique_lock<std::timed_mutex> lock(monitor, std::defer_lock);
    while (true) {
      std::cout << std::setw(10) << name << " trying to acquire lock"
                << std::endl;
      if (lock.try_lock_for(std::chrono::milliseconds(500))) {
        std::cout << std::setw(10) << name << " got the lock" << std::endl;
        break;
      }
    }
  }
};

int main() {
  std::timed_mutex mutex;
  std::vector<std::thread> workers;
  workers.emplace_back(task_t{.name = "Thread-1", .monitor = mutex});
  workers.emplace_back(task_t{.name = "Thread-2", .monitor = mutex});
  std::cout << "MainThread acquiring lock" << std::endl;
  {
    std::unique_lock<std::timed_mutex> lock(mutex);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "MainThread all done" << std::endl;
  }
  for (auto &worker : workers) {
    worker.join();
  }
}
