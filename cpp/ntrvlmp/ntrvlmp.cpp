#include "CppUnitTest.h"

#include <map>
#include <limits>

template<class K, class V>
class interval_map
{
  friend class interval_map_test;

private:
  std::map<K, V> m_map;

public:
  // constructor associates whole range of K with val by inserting (K_min, val)
  // into the map
  interval_map(V const& val)
  {
    m_map.insert(m_map.begin(), std::make_pair(std::numeric_limits<K>::lowest(), val));
  }

  // Assign value val to interval [keyBegin, keyEnd). 
  // Overwrite previous values in this interval. 
  // Do not change values outside this interval.
  // Conforming to the C++ Standard Library conventions, the interval 
  // includes keyBegin, but excludes keyEnd.
  // If !( keyBegin < keyEnd ), this designates an empty interval, 
  // and assign must do nothing.
  void assign(K const& keyBegin, K const& keyEnd, V const& val)
  {
    using namespace std;
    if (!(keyBegin < keyEnd))
      return;
    auto const begin = m_map.lower_bound(keyBegin);
    auto end = m_map.upper_bound(keyEnd);
    auto const endValue = (--end)->second;
    if (endValue == val)
      return;
    auto const afterErased = m_map.erase(begin, ++end);
    auto inserted = m_map.insert(afterErased, move(make_pair(keyBegin, val)));
    m_map.insert(++inserted, move(make_pair(keyEnd, endValue)));
  }

  // look-up of the value associated with key
  V const& operator[](K const& key) const
  {
    return (--m_map.upper_bound(key))->second;
  }
};

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

TEST_CLASS(interval_map_test) {
  TEST_METHOD(newly_created_map_returns_the_value_for_minimal_value_of_key)
  {
    auto map = interval_map<size_t, char>('a');
    Assert::AreEqual('a', map[numeric_limits<size_t>::lowest()]);
    Assert::AreEqual(size_t(1), map.m_map.size());
  }

  TEST_METHOD(newly_created_map_returns_the_value_for_maximal_value_of_key)
  {
    auto map = interval_map<size_t, char>('a');
    Assert::AreEqual('a', map[numeric_limits<size_t>::max()]);
    Assert::AreEqual(size_t(1), map.m_map.size());
  }

  TEST_METHOD(assign_left_part_of_one_value_iterval)
  {
    auto map = interval_map<size_t, char>('a');
    map.assign(0, 1, 'b');
    Assert::AreEqual('b', map[0]);
    Assert::AreEqual('a', map[1]);
    Assert::AreEqual(size_t(2), map.m_map.size());
  }

  TEST_METHOD(assign_right_part_of_one_value_iterval)
  {
    auto map = interval_map<size_t, char>('a');
    map.assign(1, numeric_limits<size_t>::max(), 'b');
    Assert::AreEqual(size_t(3), map.m_map.size());
    Assert::AreEqual('a', map[0]);
    Assert::AreEqual('b', map[1]);
    Assert::AreEqual('b', map[numeric_limits<size_t>::max() - 1]);
    Assert::AreEqual('a', map[numeric_limits<size_t>::max()]);
  }

  TEST_METHOD(assign_middle_part_of_one_value_iterval)
  {
    auto map = interval_map<size_t, char>('a');
    map.assign(1000, 2000, 'b');
    Assert::AreEqual('a', map[0]);
    Assert::AreEqual('a', map[999]);
    Assert::AreEqual('b', map[1000]);
    Assert::AreEqual('a', map[numeric_limits<size_t>::max()]);
    Assert::AreEqual(size_t(3), map.m_map.size());
  }

  TEST_METHOD(assign_middle_part_of_two_values_interval)
  {
    auto map = interval_map<size_t, char>('a');
    map.assign(1000, numeric_limits<size_t>::max(), 'b');
    map.assign(500, 1500, 'c');
    Assert::AreEqual('a', map[0]);
    Assert::AreEqual('a', map[499]);
    Assert::AreEqual('c', map[500]);
    Assert::AreEqual('c', map[1499]);
    Assert::AreEqual('b', map[1500]);
    Assert::AreEqual('b', map[numeric_limits<size_t>::max() - 1]);
    Assert::AreEqual('a', map[numeric_limits<size_t>::max()]);
  }

  TEST_METHOD(assign_maximum_possible_interval)
  {
    auto map = interval_map<size_t, char>('a');
    map.assign(numeric_limits<size_t>::min(), numeric_limits<size_t>::max(), 'b');
    Assert::AreEqual(size_t(2), map.m_map.size());
    Assert::AreEqual('b', map[0]);
    Assert::AreEqual('b', map[numeric_limits<size_t>::max() / 2]);
    Assert::AreEqual('b', map[numeric_limits<size_t>::max() - 1]);
    Assert::AreEqual('a', map[numeric_limits<size_t>::max()]);
  }

  TEST_METHOD(reassign_value_for_part_of_interval)
  {
    auto map = interval_map<size_t, char>('a');
    map.assign(100, 200, 'b');
    map.assign(100, 200, 'c');
    Assert::AreNotEqual('b', map[100]);
    Assert::AreNotEqual('b', map[150]);
    Assert::AreNotEqual('b', map[199]);
    Assert::AreEqual(size_t(3), map.m_map.size());
  }

  TEST_METHOD(assign_adjacent_intervals)
  {
    auto map = interval_map<size_t, char>('c');
    map.assign(  0, 100, 't');
    map.assign(100, 200, 'h');
    map.assign(200, 300, 'i');
    map.assign(300, 400, 'n');
    map.assign(400, numeric_limits<size_t>::max(), 'k');
    Assert::AreEqual(sizeof("think"), map.m_map.size());
    Assert::AreEqual('t', map[0]);
    Assert::AreEqual('t', map[99]);
    Assert::AreEqual('h', map[100]);
    Assert::AreEqual('h', map[199]);
    Assert::AreEqual('i', map[200]);
    Assert::AreEqual('i', map[299]);
    Assert::AreEqual('n', map[300]);
    Assert::AreEqual('n', map[399]);
    Assert::AreEqual('k', map[400]);
    Assert::AreEqual('c', map[numeric_limits<size_t>::max()]);
  }

  TEST_METHOD(stress_by_adding_1000_adjacent_intervals)
  {
    auto map = interval_map<size_t, size_t>(0);
    size_t constexpr count = 1'000;
    for (size_t i = 0; i < count; ++i)
    {
      map.assign(i, numeric_limits<size_t>::max(), i);
    }
    Assert::AreEqual(count + 1, map.m_map.size());
  }

  TEST_METHOD(stress_by_adding_2000_adjacent_intervals)
  {
    auto map = interval_map<size_t, size_t>(0);
    size_t constexpr count = 2'000;
    for (size_t i = 0; i < count; ++i)
    {
      map.assign(i, numeric_limits<size_t>::max(), i);
    }
    Assert::AreEqual(count + 1, map.m_map.size());
  }

  TEST_METHOD(stress_by_adding_3000_adjacent_intervals)
  {
    auto map = interval_map<size_t, size_t>(0);
    size_t constexpr count = 3'000;
    for (size_t i = 0; i < count; ++i)
    {
      map.assign(i, numeric_limits<size_t>::max(), i);
    }
    Assert::AreEqual(count + 1, map.m_map.size());
  }

  TEST_METHOD(stress_by_adding_4000_adjacent_intervals)
  {
    auto map = interval_map<size_t, size_t>(0);
    size_t constexpr count = 4'000;
    for (size_t i = 0; i < count; ++i)
    {
      map.assign(i, numeric_limits<size_t>::max(), i);
    }
    Assert::AreEqual(count + 1, map.m_map.size());
  }

  TEST_METHOD(stress_by_adding_5000_adjacent_intervals)
  {
    auto map = interval_map<size_t, size_t>(0);
    size_t constexpr count = 5'000;
    for (size_t i = 0; i < count; ++i)
    {
      map.assign(i, numeric_limits<size_t>::max(), i);
    }
    Assert::AreEqual(count + 1, map.m_map.size());
  }

  TEST_METHOD(stress_by_adding_6000_adjacent_intervals)
  {
    auto map = interval_map<size_t, size_t>(0);
    size_t constexpr count = 6'000;
    for (size_t i = 0; i < count; ++i)
    {
      map.assign(i, numeric_limits<size_t>::max(), i);
    }
    Assert::AreEqual(count + 1, map.m_map.size());
  }

  TEST_METHOD(stress_by_adding_7000_adjacent_intervals)
  {
    auto map = interval_map<size_t, size_t>(0);
    size_t constexpr count = 7'000;
    for (size_t i = 0; i < count; ++i)
    {
      map.assign(i, numeric_limits<size_t>::max(), i);
    }
    Assert::AreEqual(count + 1, map.m_map.size());
  }

  TEST_METHOD(stress_by_adding_8000_adjacent_intervals)
  {
    auto map = interval_map<size_t, size_t>(0);
    size_t constexpr count = 8'000;
    for (size_t i = 0; i < count; ++i)
    {
      map.assign(i, numeric_limits<size_t>::max(), i);
    }
    Assert::AreEqual(count + 1, map.m_map.size());
  }

  TEST_METHOD(stress_by_adding_9000_adjacent_intervals)
  {
    auto map = interval_map<size_t, size_t>(0);
    size_t constexpr count = 9'000;
    for (size_t i = 0; i < count; ++i)
    {
      map.assign(i, numeric_limits<size_t>::max(), i);
    }
    Assert::AreEqual(count + 1, map.m_map.size());
  }

  TEST_METHOD(stress_by_adding_10000_adjacent_intervals)
  {
    auto map = interval_map<size_t, size_t>(0);
    size_t constexpr count = 10'000;
    for (size_t i = 0; i < count; ++i)
    {
      map.assign(i, numeric_limits<size_t>::max(), i);
    }
    Assert::AreEqual(count + 1, map.m_map.size());
  }

  TEST_METHOD(stress_by_adding_20000_adjacent_intervals)
  {
    auto map = interval_map<size_t, size_t>(0);
    size_t constexpr count = 20'000;
    for (size_t i = 0; i < count; ++i)
    {
      map.assign(i, numeric_limits<size_t>::max(), i);
    }
    Assert::AreEqual(count + 1, map.m_map.size());
  }

  TEST_METHOD(stress_by_adding_30000_adjacent_intervals)
  {
    auto map = interval_map<size_t, size_t>(0);
    size_t constexpr count = 30'000;
    for (size_t i = 0; i < count; ++i)
    {
      map.assign(i, numeric_limits<size_t>::max(), i);
    }
    Assert::AreEqual(count + 1, map.m_map.size());
  }

  TEST_METHOD(stress_by_adding_40000_adjacent_intervals)
  {
    auto map = interval_map<size_t, size_t>(0);
    size_t constexpr count = 40'000;
    for (size_t i = 0; i < count; ++i)
    {
      map.assign(i, numeric_limits<size_t>::max(), i);
    }
    Assert::AreEqual(count + 1, map.m_map.size());
  }

  TEST_METHOD(stress_by_adding_50000_adjacent_intervals)
  {
    auto map = interval_map<size_t, size_t>(0);
    size_t constexpr count = 50'000;
    for (size_t i = 0; i < count; ++i)
    {
      map.assign(i, numeric_limits<size_t>::max(), i);
    }
    Assert::AreEqual(count + 1, map.m_map.size());
  }

  TEST_METHOD(do_not_change_the_map_when_interval_is_empty)
  {
    auto map = interval_map<size_t, char>('a');
    map.assign(10, 10, ' ');
    Assert::AreEqual(size_t(1), map.m_map.size());
    Assert::AreEqual('a', map[0]);
    Assert::AreEqual('a', map[numeric_limits<size_t>::max()]);
  }

  TEST_METHOD(do_not_change_the_map_when_interval_is_reversed)
  {
    auto map = interval_map<size_t, char>('a');
    map.assign(10, 1, ' ');
    Assert::AreEqual(size_t(1), map.m_map.size());
    Assert::AreEqual('a', map[0]);
    Assert::AreEqual('a', map[5]);
    Assert::AreEqual('a', map[numeric_limits<size_t>::max()]);
  }

  TEST_METHOD(assign_divergent_intervals_at_the_middle)
  {
    auto map = interval_map<size_t, char>('a');
    map.assign(30, 31, 'b');
    map.assign(20, 41, 'c');
    map.assign(10, 51, 'd');
    Assert::AreEqual('a', map[0]);
    Assert::AreEqual('d', map[20]);
    Assert::AreEqual('d', map[30]);
    Assert::AreEqual(size_t(3), map.m_map.size());
  }

  TEST_METHOD(assign_convergent_intervals_at_the_middle)
  {
    auto map = interval_map<size_t, char>('a');
    map.assign(10, 51, 'b');
    map.assign(20, 41, 'c');
    map.assign(30, 31, 'd');
    Assert::AreEqual('a', map[0]);
    Assert::AreEqual('b', map[10]);
    Assert::AreEqual('c', map[20]);
    Assert::AreEqual('d', map[30]);
    Assert::AreEqual(size_t(7), map.m_map.size());
  }

  TEST_METHOD(assign_two_distant_interval_of_the_same_value)
  {
    auto map = interval_map<size_t, char>('a');
    map.assign(10, 21, 'b');
    map.assign(30, 41, 'b');
    Assert::AreEqual('a', map[5]);
    Assert::AreEqual('b', map[15]);
    Assert::AreEqual('a', map[25]);
    Assert::AreEqual('b', map[35]);
    Assert::AreEqual('a', map[45]);
    Assert::AreEqual(size_t(5), map.m_map.size());
  }

  TEST_METHOD(assign_of_initial_value_to_whole_range_has_no_effect) {
    auto map = interval_map<size_t, char>('a');
    map.assign(0, numeric_limits<size_t>::max(), 'a');
    Assert::AreEqual(size_t(1), map.m_map.size());
    Assert::AreEqual('a', map[0]);
    Assert::AreEqual('a', map[numeric_limits<size_t>::max()]);
  }

  TEST_METHOD(assign_of_initial_value_to_left_edge_has_no_effect) {
    auto map = interval_map<size_t, char>('a');
    auto const leftEdge = numeric_limits<size_t>::min();
    map.assign(leftEdge, leftEdge + 1, 'a');
    Assert::AreEqual(size_t(1), map.m_map.size());
    Assert::AreEqual('a', map[leftEdge]);
  }

  TEST_METHOD(assign_of_initial_value_to_right_edge_has_no_effect) {
    auto map = interval_map<size_t, char>('a');
    auto const rightEdge = numeric_limits<size_t>::max();
    map.assign(rightEdge - 1, rightEdge, 'a');
    Assert::AreEqual(size_t(1), map.m_map.size());
    Assert::AreEqual('a', map[rightEdge]);
  }

  TEST_METHOD(assign_of_initial_value_to_the_middle_has_no_effect) {
    auto map = interval_map<size_t, char>('a');
    auto constexpr leftEdge = numeric_limits<size_t>::min();
    auto constexpr rightEdge = numeric_limits<size_t>::max();
    auto constexpr gap = 10;
    map.assign(leftEdge + gap, rightEdge - gap, 'a');
    Assert::AreEqual(size_t(1), map.m_map.size());
    Assert::AreEqual('a', map[rightEdge]);
    Assert::AreEqual('a', map[leftEdge]);
  }

  /*TEST_METHOD(complex) {
    auto map = interval_map<size_t, char>('!');
    auto leftEdge = numeric_limits<size_t>::min();
    auto rightEdge = numeric_limits<size_t>::max();

    map.assign(leftEdge, rightEdge, 'a');
    Assert::AreEqual(size_t(1), map.m_map.size());
    Assert::AreEqual('a', map[rightEdge]);
    Assert::AreEqual('a', map[leftEdge]);

    map.assign(++leftEdge, rightEdge--, 'b');
    Assert::AreEqual(size_t(3), map.m_map.size());
    
    Assert::AreEqual('b', map[leftEdge]);
    Assert::AreEqual('b', map[rightEdge]);
  }*/
};
