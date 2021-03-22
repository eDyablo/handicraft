#include <ostream>
#include <stack>

namespace coin {
  namespace tr {
    template <typename V>
    struct binary_tree {
      using value_t = V;

      struct node_t {
        value_t value;
        node_t* left;
        node_t* right;
      };

      node_t* root;

      template <typename Action>
      void in_depth(Action action) const {
        auto stack = std::stack<node_t const*>();
        if (root) {
          stack.push(root);
        }
        while (not(empty(stack))) {
          auto node_ref = stack.top();
          stack.pop();
          action(*node_ref);
          if (node_ref->right) {
            stack.push(node_ref->right);
          }
          if (node_ref->left) {
            stack.push(node_ref->left);
          }
        }
      }

      void dump(std::ostream& stream) const {
        in_depth([&stream](node_t const& node) { stream << node.value << " "; });
      }
    };
  }  // namespace tr
}  // namespace coin
