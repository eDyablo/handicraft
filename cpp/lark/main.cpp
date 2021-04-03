#include <SFML/Graphics.hpp>
#include <iostream>

#include "game.hpp"
#include "program.hpp"

struct std_log_t : public lark::log_t {
  void record(std_log_t::text_t const& text) {
    using namespace std;
    cout << text << endl;
  }
};

int main(int argc, char* argv[]) {
  using namespace lark;
  auto log = std_log_t{};
  auto window = sf::RenderWindow(sf::VideoMode(1280, 720), "lark");
  auto game = game_t{log, window};
  auto program = program_t{log, window, window, game};
  program.run();
  return 0;
}
