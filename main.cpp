#include <SFML/Graphics.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include "config.h"
using namespace sf;

const char* windowName = "Hera - Pantalla Principal";
const char* windowTitle = "Secciones";

int main() {
    RenderWindow window(
        VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), 
        windowName,
        Style::Titlebar | Style::Close // Resize blocked
    );

    // Load elememts: Font, button texture, sprite
    Font font;
    if(!font.loadFromFile("assets/Arimo/ArimoNerdFont-Bold.ttf"))
        return -1;
    Texture btTexture;
    if(!btTexture.loadFromFile("assets/Sinusoidal.png")) {
        return -1;
    }
    Sprite btSprite(btTexture);


    // Title Text
    Text text;
    text.setFont(font);
    text.setString(windowTitle);
    text.setCharacterSize(56);
    // Title centered
    float windowCenter = window.getSize().x / 2.0f;
    float textWidth = text.getLocalBounds().width;
    text.setPosition(windowCenter - textWidth / 2.0f, 20); // 20px desde arriba

  
    // Buttons
    btSprite.setPosition(0,0);
    btSprite.setColor(Color::White);

    // While main
    while(window.isOpen()) {
        Event event;
        while(window.pollEvent(event))
            if(event.type == Event::Closed)
                window.close();
        
        // Calls
        window.clear(BACKGROUND_COLOR);
        window.draw(text);
        window.draw(btSprite);
        window.display();
    }
}
