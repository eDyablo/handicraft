#include "prefix_tree.hpp"

#include <gmock/gmock.h>

using namespace ::coin::prfxtr;
using namespace ::testing;

struct char_tree: public Test {
  tree_t<char> tree;
};

TEST_F(char_tree, has_two_nodes_when_first_letter_inserted) {
  tree.insert("a");
  EXPECT_THAT(tree.node_count(), Eq(2));
}

TEST_F(char_tree, has_two_nodes_when_first_two_equal_letters_inserted) {
  tree.insert("a");
  tree.insert("a");
  EXPECT_THAT(tree.node_count(), Eq(2));
}

TEST_F(char_tree, has_three_nodes_when_two_different_one_letter_words_inserted_two_times_each) {
  tree.insert("b");
  tree.insert("a");
  tree.insert("a");
  tree.insert("b");
  EXPECT_THAT(tree.node_count(), Eq(3));
}

TEST_F(char_tree, has_five_nodes_when_one_word_with_four_unique_letters_inserted) {
  tree.insert("abcd");
  EXPECT_THAT(tree.node_count(), Eq(5));
}

TEST_F(char_tree, has_three_nodes_when_two_identical_two_letters_words_inserted) {
  tree.insert("ab");
  tree.insert("ab");
  EXPECT_THAT(tree.node_count(), Eq(3));
}
