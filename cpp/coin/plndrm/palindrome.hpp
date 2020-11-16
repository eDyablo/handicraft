#include <string>

namespace coin {
  namespace plndrm {
    bool is_palindrome(std::string const& string) {
      if (string.size() < 2)
        return true;
      return string[0] == string[1];
    }
  }
}
