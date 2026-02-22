#include <SFML/Graphics.hpp>
#include "config.h"
using namespace sf;

const char* windowName = "Hera - Pantalla Principal";
const char* windowTitle = "Secciones";

int main() {
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), windowName);

    // Font
    Font font;
    if(!font.loadFromFile("assets/Arimo/ArimoNerdFont-Bold.ttf"))
        return -1;

    // Title Text
    Text text;
    text.setFont(font);
    text.setString(windowTitle);
    text.setCharacterSize(56);

    // Centrar horizontalmente
    float windowCenter = window.getSize().x / 2.0f;
    float textWidth = text.getLocalBounds().width;
    text.setPosition(windowCenter - textWidth / 2.0f, 20); // 20px desde arriba

    while(window.isOpen()) {
        Event event;
        while(window.pollEvent(event))
            if(event.type == Event::Closed)
                window.close();

        window.clear(BACKGROUND_COLOR);
        window.draw(text);
        window.display();
    }
}
