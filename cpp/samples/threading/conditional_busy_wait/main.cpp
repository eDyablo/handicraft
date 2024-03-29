/*
https://superfastpython.com/thread-busy-waiting-in-python/
*/
#include <algorithm>
#include <chrono>
#include <condition_variable>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <mutex>
#include <random>
#include <string>
#include <thread>
#include <vector>

struct randomizer_t {
  std::random_device device{};
  std::default_random_engine engine{device()};
  float operator()() { return std::generate_canonical<float, 10>(engine); }
};

struct task_t {
  std::string name;
  randomizer_t &randomizer;
  std::condition_variable &condition;
  std::mutex &mutex;
  std::vector<std::string> &data;
  void operator()() {
    std::this_thread::sleep_for(std::chrono::duration<float>(randomizer()));
    {
      {
        std::unique_lock<std::mutex> lock(mutex);
        std::cout << std::setw(10) << name << " is waiting for condition..."
                  << std::endl;
        condition.wait(lock, [this]() { return !data.empty(); });
      }
      {
        std::cout << std::setw(10) << name << " got data [";
        std::copy(begin(data), end(data),
                  std::ostream_iterator<std::string>(std::cout, ", "));
        std::cout << "]" << std::endl;
      }
    }
  }
};

int main() {
  randomizer_t randomizer{};
  std::condition_variable condition;
  std::mutex mutex;
  std::vector<std::string> data;
  std::vector<std::thread> workers;
  for (auto const &name :
       {"Thread-1", "Thread-2", "Thread-3", "Thread-4", "Thread-5"}) {
    workers.emplace_back(task_t{name, randomizer, condition, mutex, data});
  }
  std::this_thread::sleep_for(std::chrono::duration<float>(randomizer()));
  {
    std::unique_lock<std::mutex> lock(mutex);
    data.push_back("hello");
    std::cout << "MainThread is notifying" << std::endl;
    condition.notify_all();
  }
  for (auto &worker : workers) {
    worker.join();
  }
}
