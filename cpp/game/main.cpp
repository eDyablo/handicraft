#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace ::sf;
using namespace ::std;

namespace game {
  struct Cursor : public Drawable {
    Vector2i position;

    void draw(RenderTarget& target, RenderStates states) const {
      RectangleShape horizontal(Vector2f(10, 3));
      horizontal.setFillColor(Color::Black);
      RectangleShape vertical(Vector2f(3, 10));
      vertical.setFillColor(Color::Black);
      horizontal.setPosition(Vector2f(position));
      vertical.setPosition(Vector2f(position));
      target.draw(horizontal);
      target.draw(vertical);
    }
  };
}  // namespace game

int main(int argc, char* argv[]) {
  auto executable_path = string(argv[0]);
  auto executable_dir =
      executable_path.substr(0, executable_path.find_last_of("/\\"));
  RenderWindow window(VideoMode(1280, 720), "game");
  // window.setMouseCursorVisible(false);
  auto cursor = game::Cursor();
  Texture texture;
  texture.loadFromFile(executable_dir + "/texture/wrinkled-paper");
  texture.setSmooth(false);
  Sprite sprite;
  sprite.setTexture(texture);
  Drawable* objects[] = {&sprite, new RectangleShape(Vector2f(100, 100)), new CircleShape(50)};
  auto world = View();
  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
      if (event.type == Event::MouseMoved) {
        cursor.position = Vector2i(event.mouseMove.x, event.mouseMove.y);
      }
      if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::A) {
          world.move(-10, 0);
        }
        if (event.key.code == Keyboard::D) {
          world.move(10, 0);
        }
        if (event.key.code == Keyboard::W) {
          world.move(0, -5);
        }
        if (event.key.code == Keyboard::S) {
          world.move(0, 5);
        }
      }
    }
    window.clear();
    window.setView(world);
    for (auto* obj : objects) {
      window.draw(*obj);
    }
    window.setView(window.getDefaultView());
    window.display();
  }
  return 0;
}
