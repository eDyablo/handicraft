#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

namespace coin {
  namespace mzn {
    struct log_record_t {
      using user_id_t = size_t;
      using amount_t = size_t;

      user_id_t sender;
      user_id_t recipient;
      amount_t transaction_amount;

      void load(std::istream& stream) {
        stream >> sender >> recipient >> transaction_amount;
      }

      void load(std::string const& text) {
        using namespace std;
        auto stream = istringstream(text);
        load(stream);
      }

      static auto load_record(std::string const& text) {
        log_record_t record;
        record.load(text);
        return record;
      }
    };

    auto find_excessive_users(size_t threshold, std::vector<std::string> log) {
      using namespace std;
      auto lookup = map<log_record_t::user_id_t, log_record_t::amount_t>();
      for (auto entry : log) {
        auto record = log_record_t::load_record(entry);
        ++lookup[record.sender];
        if (record.recipient != record.sender) {
          ++lookup[record.recipient];
        }
      }
      auto answer = vector<size_t>();
      for (auto entry : lookup) {
        if (threshold <= entry.second) {
          answer.push_back(entry.first);
        }
      }
      return answer;
    }
  }  // namespace mzn
}  // namespace coin
