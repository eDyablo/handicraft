#pragma once

#include <thread>
#include <vector>

using thread_t = ::std::thread;
using thread_vector_t = ::std::vector<thread_t>;

void join(thread_vector_t& threads) {
  for (auto& thread : threads) {
    if (thread.joinable()) {
      thread.join();
    }
  }
}
