#include "node_pool.hpp"

#include <gmock/gmock.h>

#include <initializer_list>

using ::testing::Eq;
using ::testing::SizeIs;

namespace epc {
  TEST(NodePool, AllocateNodes) {
    node_pool_t<int> pool;

    auto const first = pool.allocate(1, pool.end());
    ASSERT_THAT(pool, SizeIs(1));
    ASSERT_THAT(pool.value(first), Eq(1));
    ASSERT_THAT(pool.next(first), Eq(pool.end()));

    auto const second = pool.allocate(2, pool.end());
    ASSERT_THAT(pool, SizeIs(2));
    ASSERT_THAT(pool.value(second), Eq(2));
    ASSERT_THAT(pool.next(second), Eq(pool.end()));
  }

  TEST(NodePool, AllocateLinkedNodes) {
    node_pool_t<int> pool;

    auto const first = pool.allocate(1, pool.end());
    auto const second = pool.allocate(2, first);

    ASSERT_THAT(pool, SizeIs(2));
    ASSERT_THAT(pool.value(first), Eq(1));
    ASSERT_THAT(pool.value(second), Eq(2));
    ASSERT_THAT(pool.next(first), Eq(pool.end()));
    ASSERT_THAT(pool.next(second), Eq(first));
  }

  TEST(NodePool, AllocateFreeAndReallocateOneNode) {
    node_pool_t<int> pool;

    auto node = pool.allocate(1, pool.end());
    auto const next = pool.free(node);

    ASSERT_THAT(pool, SizeIs(1));
    ASSERT_THAT(next, Eq(pool.end()));

    node = pool.allocate(2, pool.end());
    ASSERT_THAT(pool, SizeIs(1));
    ASSERT_THAT(pool.value(node), Eq(2));
    ASSERT_THAT(pool.next(node), Eq(pool.end()));
  }

  TEST(NodePool, AllocateAndFreeOneNodeThenAllocateTwoNodes) {
    node_pool_t<int> pool;

    auto const first = pool.allocate(1, pool.end());
    pool.free(first);

    auto const second = pool.allocate(2, pool.end());
    auto const third = pool.allocate(3, pool.end());
    ASSERT_THAT(pool, SizeIs(2));
    ASSERT_THAT(pool.value(second), Eq(2));
    ASSERT_THAT(pool.value(third), Eq(3));
  }

  template <typename T>
  auto allocate_list(node_pool_t<T>& pool,
                     std::initializer_list<T> const& values) {
    typename node_pool_t<T>::node_ref node = pool.end();
    for (const auto& value : values) {
      node = pool.allocate(value, node);
    }
    return node;
  }

  TEST(NodePool, AllocateList) {
    node_pool_t<int> pool;
    auto const items = {1, 2, 3, 4, 5};
    auto const head = allocate_list(pool, items);

    ASSERT_THAT(pool, SizeIs(items.size()));
    ASSERT_THAT(pool.value(head), Eq(5));
    ASSERT_THAT(pool.value(pool.next(head)), Eq(4));
  }
}  // namespace epc
