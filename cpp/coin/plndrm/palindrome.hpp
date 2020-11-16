#include <string>

namespace coin {
  namespace plndrm {
    bool is_palindrome(std::string const& string) {
      for (auto left = string.begin(), right = string.end(); left < --right; ++left) {
        if (*left != *right) return false;
      }
      return true;
    }
  }
}
