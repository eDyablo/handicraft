#pragma once

#include <algorithm>
#include <condition_variable>
#include <mutex>
#include <queue>

#include "product.hpp"

using product_queue_t = ::std::queue<product_t>;
using condition_t = ::std::condition_variable;
using mutex_t = ::std::mutex;

struct line_t {
  line_t(size_t capacity) : capacity(capacity) {}

  bool full() const { return products.size() == capacity; }

  void add(product_t product) {
    if (!full()) {
      ::std::unique_lock lock(mutex);
      products.push(product);
      condition.notify_one();
    }
  }

  product_queue_t products;
  size_t capacity;
  condition_t condition;
  mutex_t mutex;
};
