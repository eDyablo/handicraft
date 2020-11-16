#include <string>

namespace coin {
  namespace plndrm {
    bool is_palindrome(std::string const& string) {
      if (string.empty())
        return true;
      return false;
    }
  }
}
