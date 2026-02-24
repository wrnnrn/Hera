#include "config.h"
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
        windowName,
        sf::Style::Titlebar | sf::Style::Close
    );

    // Object class Button
    Button b;
    b.fileTexture = "../assets/debug.jpeg";
    b.textBtn = "Debugging";
    b.fontFile = "../assets/Arimo/ArimoNerdFont-Bold.ttf";
    b.x = 200;
    b.y = 200;

    b.ButtonFn(); // Inicializa btSprite y btText

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        window.draw(b.btSprite);
        window.draw(b.btText);

        window.display();
    }

    return 0;
}