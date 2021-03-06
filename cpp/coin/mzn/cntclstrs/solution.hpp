#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

namespace coin {
  namespace mzn {
    using plan_t = std::vector<std::vector<int>>;
    using shape_t = std::pair<size_t, size_t>;
    using coord_t = std::pair<size_t, size_t>;

    shape_t get_shape(plan_t const& plan) {
      shape_t shape;
      shape.first = size(plan);
      if (shape.first) {
        shape.second = size(plan[0]);
      }
      return shape;
    }

    void plot(plan_t const& plan, std::ostream& stream) {
      using namespace std;
      auto const shape = get_shape(plan);
      for (auto row = 0; row < shape.first; ++row) {
        for (auto col = 0; col < shape.second; ++col) {
          stream << (plan[row][col] == 0 ? "░░" : "▓▓");
        }
        stream << endl;
      }
    }

    bool inside_plan(size_t row, size_t col, plan_t const& plan) {
      shape_t const shape = get_shape(plan);
      return row < shape.first && col < shape.second;
    }

    std::vector<coord_t> get_neighbours(size_t row, size_t col,
                                        plan_t const& plan) {
      using namespace std;
      vector<coord_t> neighbours;
      if (inside_plan(row - 1, col, plan) && plan[row - 1][col] == 1)
        neighbours.push_back(make_pair(row - 1, col));
      if (inside_plan(row + 1, col, plan) && plan[row + 1][col] == 1)
        neighbours.push_back(make_pair(row + 1, col));
      if (inside_plan(row, col - 1, plan) && plan[row][col - 1] == 1)
        neighbours.push_back(make_pair(row, col - 1));
      if (inside_plan(row, col + 1, plan) && plan[row][col + 1] == 1)
        neighbours.push_back(make_pair(row, col + 1));
      return neighbours;
    }

    void mark_cluster(int mark, size_t row, size_t col, plan_t& plan) {
      using namespace std;
      vector<coord_t> neighbours;
      neighbours.push_back(make_pair(row, col));
      while (!neighbours.empty()) {
        auto const& neighbour = neighbours.back();
        plan[neighbour.first][neighbour.second] = mark;
        auto new_neighbours =
            get_neighbours(neighbour.first, neighbour.second, plan);
        neighbours.pop_back();
        copy(begin(new_neighbours), end(new_neighbours),
             back_inserter(neighbours));
      }
    }

    size_t count_clusters(plan_t& plan) {
      auto const shape = get_shape(plan);
      size_t counter = 0;
      for (auto row = 0; row < shape.first; ++row) {
        for (auto col = 0; col < shape.second; ++col) {
          if (plan[row][col] == 1) {
            mark_cluster(2, row, col, plan);
            ++counter;
          }
        }
      }
      return counter;
    }
  }  // namespace mzn
}  // namespace coin
