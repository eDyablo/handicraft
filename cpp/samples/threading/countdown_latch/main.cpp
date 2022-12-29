#include <chrono>
#include <condition_variable>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <random>
#include <string>
#include <thread>
#include <vector>

struct latch_t {
  explicit latch_t(std::size_t parties) : parties(parties) {}

  void pass() {
    std::unique_lock<std::mutex> lock(mutex);
    if ((0 != parties) and (0 == --parties)) {
      condition.notify_all();
    }
  }

  void wait() {
    std::unique_lock<std::mutex> lock(mutex);
    if (parties) {
      condition.wait(lock);
    }
  }

  void arrive_and_wait() {
    pass();
    wait();
  }

private:
  std::size_t parties;
  std::mutex mutex;
  std::condition_variable condition;
};

struct randomizer_t {
  std::random_device device{};
  std::default_random_engine engine{device()};
  float operator()() { return std::generate_canonical<float, 10>(engine); }
};

thread_local std::string thread_name = "MainThread";

void log(std::string const &message) {
  std::cout << std::setw(10) << thread_name << " " << message << std::endl;
}

struct work_t {
  std::string id;
  latch_t &latch;
  randomizer_t &randomizer;
  void operator()() {
    thread_name = id;
    log("started");
    std::this_thread::sleep_for(std::chrono::duration<float>(randomizer()) * 2);
    latch.pass();
    log("done");
  }
};

int main() {
  log("started");
  auto const parties = {"Thread-1", "Thread-2", "Thread-3", "Thread-4",
                        "Thread-5"};
  randomizer_t randomizer{};
  latch_t latch{parties.size()};
  std::vector<std::thread> workers;
  for (auto const &id : parties) {
    workers.emplace_back(work_t{
        .id = id,
        .latch = latch,
        .randomizer = randomizer,
    });
  }
  log("waiting on latch...");
  latch.wait();
  for (auto &worker : workers) {
    worker.join();
  }
  log("done");
}
