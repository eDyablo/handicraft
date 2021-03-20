#include <algorithm>
#include <ostream>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

namespace coin {
  namespace mcrsft {
    struct node_t {
      using name_t = std::string;
      using chain_t = std::vector<node_t const*>;
      using slice_t =
          std::pair<chain_t::const_iterator, chain_t::const_iterator>;

      name_t name;
      chain_t children;

      template <typename Action>
      void recurse(Action action) const {
        action(*this);
        for (auto child : children) {
          child->recurse(action);
        }
      }

      template <typename Action>
      void in_depth(Action action) const {
        auto stack = std::stack<node_t const*>();
        stack.push(this);
        while (not(empty(stack))) {
          auto node = stack.top();
          stack.pop();
          action(*node);
          for (auto child : node->children) {
            stack.emplace(child);
          }
        }
      }

      template <typename Action>
      void in_depth2(Action action) const {
        action(*this);
        auto stack = std::stack<slice_t>();
        stack.emplace(children.cbegin(), children.cend());
        while (not(empty(stack))) {
          auto& slice = stack.top();
          if (slice.first != slice.second) {
            auto node = *slice.first;
            action(*node);
            ++slice.first;
            stack.emplace(node->children.cbegin(), node->children.cend());
          } else {
            stack.pop();
          }
        }
      }

      template <typename Action>
      void in_breadth(Action action) const {
        auto queue = std::queue<node_t const*>();
        queue.push(this);
        while (not(empty(queue))) {
          auto node = queue.front();
          queue.pop();
          action(*node);
          for (auto child : node->children) {
            queue.emplace(child);
          }
        }
      }

      void dump_recurse(std::ostream& stream) const {
        recurse([&stream](node_t const& n) { stream << n.name << " "; });
      }

      void dump_depth(std::ostream& stream) const {
        in_depth([&stream](node_t const& n) { stream << n.name << " "; });
      }

      void dump_depth2(std::ostream& stream) const {
        in_depth2([&stream](node_t const& n) { stream << n.name << " "; });
      }

      void dump_breadth(std::ostream& stream) const {
        in_breadth([&stream](node_t const& n) { stream << n.name << " "; });
      }

      bool has_child(name_t const& target) const {
        for (auto child : children) {
          if (child->name == target or child->has_child(target)) {
            return true;
          }
        }
        return false;
      }

      chain_t path_to(name_t const& destination) const {
        auto path = chain_t{this};
        auto stack = std::stack<slice_t>();
        stack.emplace(children.cbegin(), children.cend());
        while (not(empty(stack))) {
          auto& slice = stack.top();
          if (slice.first != slice.second) {
            auto node = *slice.first;
            if (node->name == destination) {
              break;
            }
            path.push_back(node);
            ++slice.first;
            stack.emplace(node->children.cbegin(), node->children.cend());
          } else {
            stack.pop();
            path.pop_back();
          }
        }
        return path;
      }

      name_t find_common(name_t const& first, name_t const& second) const {
        using namespace std;
        auto first_path = path_to(first);
        auto second_path = path_to(second);
        auto length = min(size(first_path), size(second_path));
        auto i = size_t(0);
        for (; i < length; ++i) {
          if (first_path[i] != second_path[i]) {
            break;
          }
        }
        return i > 0 ? first_path[i - 1]->name : "";
      }
    };

    std::ostream& operator<<(std::ostream& stream, node_t const& node) {
      node.dump_recurse(stream);
      return stream;
    }

    std::ostream& operator<<(std::ostream& stream,
                             node_t::chain_t const& chain) {
      for (auto link : chain) {
        stream << link->name << " ";
      }
      return stream;
    }
  }  // namespace mcrsft
}  // namespace coin
