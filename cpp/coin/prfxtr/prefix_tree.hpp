#include <cstddef>
#include <string>
#include <unordered_set>

namespace coin {
  namespace prfxtr {
    template<typename E>
    struct tree_t {
      using element_t = E;
      using word_t = std::basic_string<element_t>;
      using partner_set_t = std::unordered_set<element_t>;

      struct node_t {
        bool has(element_t element) const {
          return partners.find(element) != partners.end();
        }

        void link(element_t element) {
          partners.insert(element);
        }

      private:
        partner_set_t partners;
      };

      using node_set_t = std::vector<node_t>;

      tree_t(): nodes(1) {
      }

      void insert(word_t const& word) {
        auto node_iter = nodes.begin();
        for (auto const letter: word) {
          if (node_iter->has(letter) == false) {
            node_iter->link(letter);
            nodes.push_back(node_t());
            node_iter = nodes.begin() + nodes.size() - 1;
          }
        }
      }

      size_t node_count() const {
        return nodes.size();
      }

    private:
      node_set_t nodes;
    };
  }
}
