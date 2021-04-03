#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace lark {
  struct player_char_t : public sf::Drawable {
    void draw(sf::RenderTarget& target, sf::RenderStates states) const {
      auto box = sf::RectangleShape{};
      box.setSize(sf::Vector2f(50, 50));
      target.draw(box);
    }
  };

  struct player_t {};
}  // namespace lark
