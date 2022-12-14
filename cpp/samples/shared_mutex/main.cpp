/*
https://en.cppreference.com/w/cpp/thread/shared_mutex
*/

#include <iostream>
#include <shared_mutex>
#include <thread>
#include <vector>

class counter_t {
 public:
  using value_t = int;

  counter_t() = default;

  value_t get() const {
    std::shared_lock lock(mutex);
    return value;
  }

  value_t increment() {
    std::unique_lock lock(mutex);
    auto const current = value;
    std::this_thread::yield(); // simulate threads interleaving
    value = current + 1;
    return current;
  }

  value_t decrement() {
    std::unique_lock lock(mutex);
    auto const current = value;
    std::this_thread::yield(); // simulate threads interleaving
    value = current - 1;
    return current;
  }

 private:
  unsigned long value = value_t{0};
  mutable std::shared_mutex mutex;
};

int main() {
  counter_t counter;
  std::mutex cout_mutex;

  auto increment = [&counter, &cout_mutex]() {
    auto const value = counter.increment();
    std::unique_lock lock(cout_mutex);
    std::cout << std::this_thread::get_id() << ' ' << value << std::endl;
  };

  auto decrement = [&counter, &cout_mutex]() {
    auto const value = counter.decrement();
    std::unique_lock lock(cout_mutex);
    std::cout << std::this_thread::get_id() << ' ' << value << std::endl;
  };

  std::vector<std::thread> threads;
  for (int i = 0; i < 10; ++i) {
    threads.emplace_back(increment);
    threads.emplace_back(decrement);
  }

  for (auto &thread : threads) {
    thread.join();
  }

  if (counter.get() == 0) {
    std::cout << "OK\n";
    return 0;
  } else {
    std::cerr << "FAIL\n";
    return 1;
  }
}
