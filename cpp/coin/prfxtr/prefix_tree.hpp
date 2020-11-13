#include <cstddef>
#include <string>
#include <unordered_map>

namespace coin {
  namespace prfxtr {
    template<typename E>
    struct tree_t {
      using element_t = E;
      using word_t = std::basic_string<element_t>;
      using location_t = size_t;
      using partner_set_t = std::unordered_map<element_t, location_t>;

      struct node_t {
        bool has(element_t element) const {
          return partners.find(element) != partners.end();
        }

        void link(element_t element, location_t location) {
          partners.emplace(element, location);
        }

        location_t locate(element_t element) const {
          auto const entry = partners.find(element);
          return entry != partners.end() ? entry->second : false;
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
            node_iter->link(letter, nodes.size());
            nodes.push_back(node_t());
            node_iter = nodes.begin() + nodes.size() - 1;
          } else {
            auto const location = node_iter->locate(letter);
            node_iter = nodes.begin() + location;
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
