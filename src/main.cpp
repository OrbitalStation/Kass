#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"

#include <SFML/Graphics.hpp>

#include <cstring>

#include "../inc/field.h"
#include "../inc/creature.h"

int main() {
    sf::RenderWindow w(sf::VideoMode(width * 20, height * 20), "Kass");
    sf::Event e{};
    sf::Texture texture;
    sf::Sprite sprite;

    texture.loadFromFile("../tile.png");
    sprite.setTexture(texture);

    memset(field, Void, sizeof(field));
#define g(x, y) field[x][y] = Alive; creatures.emplace_back(x, y);
    g(3, 9)
    g(9, 3)

//    field_fill();

    while (w.isOpen()) {
        while (w.pollEvent(e)) if (e.type == sf::Event::Closed) w.close();

        for (u8 x = 0, y; x < width; ++x) {
            for (y = 0; y < height; ++y) {
                sprite.setTextureRect(sf::IntRect(field[x][y] * 20, 0, 20, 20));
                sprite.setPosition(x * 20, y * 20);
                w.draw(sprite);
            }
        }
        w.display();
    }
    for (auto &i: creatures) if (i.handler.joinable()) i.handler.join();
}
