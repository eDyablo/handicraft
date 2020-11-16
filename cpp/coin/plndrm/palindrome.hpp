#include <string>

namespace coin {
  namespace plndrm {
    bool is_palindrome(std::string const& string) {
      if (string.size() < 2)
        return true;
      return string[0] == string[string.size() - 1]
        and is_palindrome(string.substr(1, string.size() - 2));
    }
  }
}
