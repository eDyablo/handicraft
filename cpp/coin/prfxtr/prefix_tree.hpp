#include <cstddef>
#include <string>

namespace coin {
  namespace prfxtr {
    template<typename E>
    struct tree_t {
      using element_t = E;
      using word_t = std::basic_string<element_t>;

      struct node_t {
      };

      using node_set_t = std::vector<node_t>;

      tree_t(): nodes(1) {
      }

      void insert(word_t const& word) {
        nodes.push_back(node_t());
      }

      size_t node_count() const {
        return nodes.size();
      }

    private:
      node_set_t nodes;
    };
  }
}
