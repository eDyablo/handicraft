#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window.hpp>

#include "game.hpp"
#include "log.hpp"

namespace lark {
  struct program_t {
    using window_t = sf::Window;
    using display_t = sf::RenderTarget;

    log_t& log;
    window_t& window;
    display_t& display;
    game_t& game;

    void run() {
      log.record("starting program");
      try {
        game.start();
        while (game.is_running()) {
          auto event = sf::Event{};
          while (window.pollEvent(event)) {
            game.handle(event);
            if (event.type == sf::Event::Closed) {
              window.close();
            }
          }
          display.clear();
          game.update();
          window.display();
        }
        log.record("program finished");
      } catch (...) {
        log.record("program aborted");
      }
    }
  };
}  // namespace lark
