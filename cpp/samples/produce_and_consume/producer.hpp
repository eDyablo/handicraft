#pragma once

#include "line.hpp"
#include "thread.hpp"

struct producer_t {
  producer_t(line_t& line) : line(line) {}
  void operator()() {
    while (line.full()) ::std::this_thread::yield();
    line.add(product_t{.name="d"});
  }
  line_t& line;
};

thread_t make_producer(line_t& line) { return thread_t(producer_t(line)); }
