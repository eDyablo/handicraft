#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "log.hpp"
#include "player.hpp"

namespace lark {
  struct game_t {
    using event_t = sf::Event;
    using display_t = sf::RenderTarget;

    log_t& log;
    display_t& display;
    player_char_t character;
    bool running;

    void handle(event_t const& event) {
      if (event.type == event_t::Closed) {
        stop();
      }
    }

    bool is_running() const { return running; }

    void start() {
      log.record("game is running");
      running = true;
    }

    void stop() {
      log.record("game is stopped");
      running = false;
    }

    void update() {
      display.draw(character);
    }
  };
}  // namespace lark
