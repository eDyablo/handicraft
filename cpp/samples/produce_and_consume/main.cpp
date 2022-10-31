#include "consumer.hpp"
#include "line.hpp"
#include "producer.hpp"

int main() {
  line_t line(10);
  thread_vector_t threads;
  threads.push_back(make_producer(line));
  threads.push_back(make_consumer(line));
  join(threads);
  return 0;
}
