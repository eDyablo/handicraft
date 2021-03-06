#include <string>

namespace coin {
  namespace mcrsft {
    std::string replace_question_marks(std::string const& riddle) {
      using namespace std;
      string answer = riddle;
      auto const length = size(answer);
      if (length > 0) {
        if (answer[0] == '?') {
          answer[0] = 'b';
        }
        for (size_t index = 1; index < length; ++index) {
          auto& prev = answer[index - 1];
          auto& curr = answer[index];
          if (prev == curr) {
            prev -= 1;
          } else if (curr == '?') {
            curr = prev + 2 > 'z' ? 'a' : prev + 2;
          }
        }
      }
      return answer;
    }
  }  // namespace mcrsft
}  // namespace coin
