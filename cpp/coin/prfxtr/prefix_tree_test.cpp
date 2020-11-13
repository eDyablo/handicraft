#include "prefix_tree.hpp"

#include <gmock/gmock.h>

using namespace ::coin::prfxtr;
using namespace ::testing;

TEST(tree, has_two_nodes_when_first_letter_inserted) {
  tree_t<char> tree;
  tree.insert("a");
  EXPECT_THAT(tree.node_count(), Eq(2));
}

TEST(tree, has_two_nodes_when_first_two_equal_letters_inserted) {
  tree_t<char> tree;
  tree.insert("a");
  tree.insert("a");
  EXPECT_THAT(tree.node_count(), Eq(2));
}

TEST(tree, has_three_nodes_when_two_different_one_letter_words_inserted_two_times_each) {
  tree_t<char> tree;
  tree.insert("b");
  tree.insert("a");
  tree.insert("a");
  tree.insert("b");
  EXPECT_THAT(tree.node_count(), Eq(3));
}

TEST(tree, has_five_nodes_when_one_word_with_four_unique_letters_inserted) {
  tree_t<char> tree;
  tree.insert("abcd");
  EXPECT_THAT(tree.node_count(), Eq(5));
}

TEST(tree, has_three_nodes_when_two_identical_two_letters_words_inserted) {
  tree_t<char> tree;
  tree.insert("ab");
  tree.insert("ab");
  EXPECT_THAT(tree.node_count(), Eq(3));
}
