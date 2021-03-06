#pragma once

#include <algorithm>
#include <array>
#include <limits>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

namespace coin {
  namespace two_pointers {
    template <typename Item>
    auto find_target_sum_pair(Item target_sum,
                              std::valarray<Item> const& array) {
      using namespace std;
      for (auto array_begin = begin(array), front_iterator = array_begin,
                back_iterator = end(array) - 1;
           front_iterator != back_iterator;) {
        auto sum = *front_iterator + *back_iterator;
        if (sum > target_sum) {
          --back_iterator;
        } else if (sum < target_sum) {
          ++front_iterator;
        } else {
          return make_pair(size_t(distance(array_begin, front_iterator)),
                           size_t(distance(array_begin, back_iterator)));
        }
      }
      return make_pair(numeric_limits<size_t>::max(),
                       numeric_limits<size_t>::max());
    }

    template <typename Item>
    auto remove_duplicates(std::vector<Item>& array) {
      using namespace std;
      auto const array_begin = begin(array);
      auto const array_end = end(array);
      auto subarray_end = array_begin + 1;
      for (auto iterator = array_begin; iterator != array_end; ++iterator) {
        if (*(subarray_end - 1) != *iterator) {
          *subarray_end = move(*iterator);
          ++subarray_end;
        }
      }
      return distance(array_begin, subarray_end);
    }

    template <typename Item>
    auto remove_all_inclusions(const Item& element, std::vector<Item>& array) {
      using namespace std;
      auto const array_begin = begin(array);
      auto const array_end = end(array);
      auto subarray_end = array_begin;
      for (auto iterator = array_begin; iterator != array_end; ++iterator) {
        if (*iterator != element) {
          *subarray_end = move(*iterator);
          ++subarray_end;
        }
      }
      return distance(array_begin, subarray_end);
    }

    template <typename Item>
    auto make_squares(std::vector<int> const& array) {
      using namespace std;
      vector<Item> squares(size(array));
      auto left_iterator = begin(array);
      auto right_iterator = rbegin(array);
      for (auto squares_iterator = rbegin(squares);
           squares_iterator != squares.rend(); ++squares_iterator) {
        auto const left_square = (*left_iterator) * (*left_iterator);
        auto const right_square = (*right_iterator) * (*right_iterator);
        if (left_square > right_square) {
          *squares_iterator = left_square;
          ++left_iterator;
        } else {
          *squares_iterator = right_square;
          ++right_iterator;
        }
      }
      return squares;
    }

    template <typename Item>
    auto find_triplets(std::vector<Item>& array) {
      using item_t = Item;
      using triplet_t = std::array<item_t, 3>;
      using namespace std;
      vector<triplet_t> triplets;
      auto const array_begin = begin(array);
      auto const array_end = end(array);
      sort(begin(array), end(array));
      for (auto array_iterator = array_begin; array_iterator != array_end;
           ++array_iterator) {
        auto left_iterator = array_iterator + 1;
        auto right_iterator = array_end - 1;
        auto const required_sum = -*array_iterator;
        while (left_iterator < right_iterator) {
          auto const sum = *left_iterator + *right_iterator;
          if (required_sum < sum) {
            --right_iterator;
          } else if (sum < required_sum) {
            ++left_iterator;
          } else {
            triplets.push_back(move(triplet_t{
                *array_iterator, *(left_iterator++), *(right_iterator--)}));
          }
        }
      }
      return triplets;
    }

    template <typename Item>
    Item find_triplet_sum_close_to_target(Item target_sum,
                                          std::vector<Item> array) {
      using item_t = Item;
      using namespace std;
      auto const array_begin = begin(array);
      auto const array_end = end(array);
      sort(array_begin, array_end);
      auto min_diff = numeric_limits<item_t>::max();
      for (auto array_iterator = array_begin; array_iterator != array_end;
           ++array_iterator) {
        auto left_iterator = array_iterator + 1;
        auto right_iterator = array_end - 1;
        while (left_iterator < right_iterator) {
          auto const diff =
              target_sum - *array_iterator - *left_iterator - *right_iterator;
          if (diff == 0) {
            return target_sum;
          }
          if (abs(diff) < abs(min_diff)) {
            min_diff = diff;
          }
          if (0 < diff) {
            ++left_iterator;
          } else {
            --right_iterator;
          }
        }
      }
      return target_sum - min_diff;
    }

    template <typename Item>
    auto count_triplets_with_smaller_sum(Item target_sum,
                                         std::vector<Item> array) {
      using item_t = Item;
      using namespace std;
      auto const array_begin = begin(array);
      auto const array_end = end(array);
      sort(array_begin, array_end);
      auto count = numeric_limits<size_t>::denorm_min();
      for (auto array_iterator = array_begin; array_iterator != array_end;
           ++array_iterator) {
        for (auto left_iterator = array_iterator + 1,
                  right_iterator = array_end - 1;
             left_iterator < right_iterator;) {
          auto const sum = *array_iterator + *left_iterator + *right_iterator;
          if (sum < target_sum) {
            count += distance(left_iterator, right_iterator);
            ++left_iterator;
          } else {
            --right_iterator;
          }
        }
      }
      return count;
    }

    template <typename Item>
    auto find_triplets_with_smaller_sum(Item target_sum,
                                        std::vector<Item> array) {
      using item_t = Item;
      using triplet_t = std::array<item_t, 3>;
      using namespace std;
      vector<triplet_t> triplets;
      auto const array_begin = begin(array);
      auto const array_end = end(array);
      sort(array_begin, array_end);
      for (auto array_iterator = array_begin; array_iterator != array_end;
           ++array_iterator) {
        for (auto left_iterator = array_iterator + 1,
                  right_iterator = array_end - 1;
             left_iterator < right_iterator;) {
          auto const sum = *array_iterator + *left_iterator + *right_iterator;
          if (sum < target_sum) {
            for (auto iter = left_iterator + 1; iter != right_iterator + 1;
                 ++iter) {
              triplets.push_back(
                  triplet_t{*array_iterator, *left_iterator, *iter});
            }
            ++left_iterator;
          } else {
            --right_iterator;
          }
        }
      }
      return triplets;
    }

    template <typename Item>
    auto find_subarrays_with_smaller_product(Item target_product,
                                             std::vector<Item> const& array) {
      using item_t = Item;
      using namespace std;
      vector<vector<item_t>> subarrays;
      item_t product = 1;
      for (auto array_begin = begin(array), array_end = end(array),
                right_iterator = array_begin, left_iterator = array_begin;
           right_iterator != array_end; ++right_iterator) {
        product *= *right_iterator;
        for (; target_product <= product && left_iterator != array_end;
             ++left_iterator) {
          product /= *left_iterator;
        }
        vector<item_t> buffer;
        for (auto iterator = make_reverse_iterator(right_iterator + 1),
                  end = make_reverse_iterator(left_iterator);
             iterator != end; ++iterator) {
          buffer.push_back(*iterator);
          subarrays.push_back(vector<item_t>(rbegin(buffer), rend(buffer)));
        }
      }
      return subarrays;
    }

    template <typename Item>
    void dutch_flag_sort(Item const red, Item const blue,
                         std::vector<Item>& array) {
      using namespace std;
      for (auto left_iterator = begin(array), right_iterator = end(array) - 1,
                iterator = left_iterator;
           iterator <= right_iterator;) {
        if (*iterator == red) {
          swap(*(iterator++), *(left_iterator++));
        } else if (*iterator == blue) {
          swap(*iterator, *(right_iterator--));
        } else {
          ++iterator;
        }
      }
    }

    template <typename Item>
    auto find_quardruplets_with_taget_sum(Item target_sum,
                                          std::vector<Item> items) {
      using item_t = Item;
      using quardruplet_t = std::array<item_t, 4>;
      using namespace std;
      sort(begin(items), end(items));
      vector<quardruplet_t> quardruplets;
      for (auto items_begin = begin(items), items_end = end(items),
                first_iterator = items_begin;
           first_iterator < items_end; ++first_iterator) {
        for (auto second_iterator = first_iterator + 1;
             second_iterator < items_end; ++second_iterator) {
          auto third_iterator = second_iterator + 1;
          auto fourth_iterator = items_end - 1;
          while (third_iterator < fourth_iterator) {
            auto const sum = *first_iterator + *second_iterator +
                             *third_iterator + *fourth_iterator;
            if (sum < target_sum) {
              ++third_iterator;
            } else if (target_sum < sum) {
              --fourth_iterator;
            } else {
              quardruplets.push_back(
                  quardruplet_t{*first_iterator, *second_iterator,
                                *third_iterator, *fourth_iterator});
              ++third_iterator;
              --fourth_iterator;
            }
          }
        }
      }
      return quardruplets;
    }

    template <typename Char>
    auto compare_strings_with_backspaces(
        std::basic_string<Char> const& first,
        std::basic_string<Char> const& second) {
      using namespace std;
      auto first_iterator = rbegin(first);
      auto second_iterator = rbegin(second);
      auto const first_end = rend(first);
      auto const second_end = rend(second);
      for (; first_iterator < first_end && second_iterator < second_end;
           ++first_iterator, ++second_iterator) {
        auto backspace_count = 0;
        for (; first_iterator < first_end && *first_iterator == '#';
             ++first_iterator) {
          ++backspace_count;
        }
        advance(
            first_iterator,
            min<size_t>(backspace_count, distance(first_iterator, first_end)));
        backspace_count = 0;
        for (; second_iterator < second_end && *second_iterator == '#';
             ++second_iterator) {
          ++backspace_count;
        }
        advance(second_iterator,
                min<size_t>(backspace_count,
                            distance(second_iterator, second_end)));
        if (!(first_iterator < first_end) || !(second_iterator < second_end)) {
          break;
        }
        if (*first_iterator != *second_iterator) {
          return false;
        }
      }
      return distance(first_iterator, first_end) ==
             distance(second_iterator, second_end);
    }
  }  // namespace two_pointers
}  // namespace coin
