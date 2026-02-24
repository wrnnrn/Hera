#ifndef CONFIG_H
#define CONFIG_H

#include <SFML/Graphics.hpp>
#include <iostream>

// Window configuration const
const int WINDOW_WIDTH{1600};
const int WINDOW_HEIGHT{900};
const sf::Color BACKGROUND_COLOR = sf::Color(77, 77, 77);
const char* windowName = "Debug";

class Button {
public:
    std::string fileTexture;
    int x, y; // Position coordinates
    std::string fontFile;
    std::string textBtn;

    sf::Font font;
    sf::Texture btTexture;

    // Ahora son atributos de la clase
    sf::Sprite btSprite;
    sf::Text btText;

    int ButtonFn() {
        // Debug 
        std::cout << "Texture file direction: " << fileTexture << std::endl;
        std::cout << "Position coordinates: (" << x << "," << y << ")" << std::endl;

        // Load texture
        if(!btTexture.loadFromFile(fileTexture)) {
            std::cout << "Error loading texture" << std::endl;
            return 0;
        }
        btSprite.setTexture(btTexture);
        btSprite.setPosition((x), (y));

        // Load font
        if(!font.loadFromFile(fontFile)) {
            std::cout << "Error loading font" << std::endl;
            return 0;
        }

        // Create text
        btText.setFont(font);
        btText.setString(textBtn);
        btText.setCharacterSize(24);
        btText.setFillColor(sf::Color::Black);

        // Center text under sprite
        sf::FloatRect spriteBounds = btSprite.getGlobalBounds();
        sf::FloatRect textBounds = btText.getLocalBounds();
        btText.setOrigin(textBounds.width / 2.f, 0.f);
        btText.setPosition(
            spriteBounds.left + spriteBounds.width / 2.f,
            spriteBounds.top + spriteBounds.height + 5.f
        );

        return 0;
    }
};

#endif