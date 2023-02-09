#include <cstddef>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

template <typename T>
std::ostream& draw_document_unit(std::ostream& stream, T const& target,
                                 std::size_t indent) {
  return stream << std::setw(indent) << "" << target << std::endl;
}

template <typename T, typename U>
std::ostream& draw_document_unit(std::ostream& stream,
                                 std::pair<T, U> const& target,
                                 std::size_t indent) {
  return stream << std::setw(indent) << "" << target.first << ": "
                << target.second << std::endl;
}

struct document_unit_t {
  std::ostream& draw(std::ostream& stream, std::size_t indent = 0) const {
    return self->draw(stream, indent);
  }

  template <typename T>
  document_unit_t(T target)
      : self(std::make_shared<model_t<T>>(std::move(target))) {}

 private:
  struct concept_t {
    virtual std::ostream& draw(std::ostream& stream,
                               std::size_t indent) const = 0;
    virtual ~concept_t() = default;
  };

  template <typename T>
  struct model_t : public concept_t {
    T target;

    model_t(T target) : target(std::move(target)) {}

    std::ostream& draw(std::ostream& stream,
                       std::size_t indent) const override {
      return draw_document_unit(stream, target, indent);
    }
  };

 private:
  std::shared_ptr<concept_t> self;
};

template <typename T>
std::ostream& draw_document_unit(std::ostream& stream,
                                 std::vector<T> const& document,
                                 std::size_t indent) {
  for (auto const& unit : document) {
    unit.draw(std::cout, indent + 2);
  }
  return stream;
}

int main() {
  std::vector<document_unit_t> document;
  document.emplace_back("hello");
  document.emplace_back(std::make_pair(1, "one"));
  document.emplace_back(document);
  for (auto const& unit : document) {
    unit.draw(std::cout);
  }
  // draw_document_unit(std::cout, std::make_pair(1, 2), 0);
}
