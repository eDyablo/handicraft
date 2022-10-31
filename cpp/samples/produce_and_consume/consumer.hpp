#pragma once

#include "line.hpp"
#include "thread.hpp"

struct consumer_t {
  consumer_t(line_t& line) : line(line) {}
  void operator()() {}
  line_t& line;
};

thread_t make_consumer(line_t& line) { return thread_t(consumer_t(line)); }
