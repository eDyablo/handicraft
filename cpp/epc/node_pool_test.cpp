#include "node_pool.hpp"

#include <gmock/gmock.h>

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

  TEST(NodePool, AllocateLinkedList) {
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

  TEST(NodePool, AllocateAndFreeOneListThenAllocateTwoLists) {
    node_pool_t<int> pool;

    auto const first = pool.allocate(1, pool.end());
    pool.free(first);

    auto const second = pool.allocate(2, pool.end());
    auto const third = pool.allocate(3, pool.end());
    ASSERT_THAT(pool, SizeIs(2));
    ASSERT_THAT(pool.value(second), Eq(2));
    ASSERT_THAT(pool.value(third), Eq(3));
  }
}  // namespace epc
