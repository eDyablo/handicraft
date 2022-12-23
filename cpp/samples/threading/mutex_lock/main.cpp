/*
https://superfastpython.com/threading-in-python/#Example_of_Using_a_Mutex_Lock
*/
#include <algorithm>
#include <chrono>
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
  std::mutex& monitor;
  randomizer_t& randomizer;
  void operator()() {
    std::unique_lock lock(monitor);
    auto const interval = std::chrono::duration<float>(randomizer());
    std::cout << std::setw(10) << name << " got the lock and sleep for "
              << std::setprecision(2) << interval.count() << std::endl;
    std::this_thread::sleep_for(std::chrono::duration<float>(randomizer()));
  }
};

struct name_genetator_t {
  std::string const prefix;
  unsigned int count;
  std::string operator()() { return prefix + std::to_string(count++); }
};

int main() {
  std::vector<std::thread> workers;
  std::mutex monitor;
  randomizer_t randomizer{};
  std::vector<std::string> thread_names;
  std::generate_n(std::back_inserter(thread_names), 10,
                  name_genetator_t{.prefix = "Thread-", .count = 1});

  std::unique_lock<std::mutex> lock(monitor, std::defer_lock);
  lock.lock();
  for (auto const& name : thread_names) {
    workers.emplace_back(task_t{name, monitor, randomizer});
  }
  lock.unlock();
  
  for (auto& worker : workers) {
    worker.join();
  }
}
