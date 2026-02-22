#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main() {
    RenderWindow window(VideoMode(800, 600), "Botones");

    Texture btTexture;
    if(!btTexture.loadFromFile("assets/debug.jpeg")) {
        cout << "Error cargando las texturas de los botones" << endl;
        return -1;
    }
    Sprite btSprite(btTexture);
    btSprite.setPosition(100, 100);

    Font font;
    if(!font.loadFromFile("assets/Arimo/ArimoNerdFont-Bold.ttf")) {
        cout << "Error cargando la fuente" << endl;
        return -1;
    }

    Text btText("Movimiento Ondulatorio", font, 24);
    btText.setFillColor(Color::Black);

    // Centrar texto debajo de la imagen
    FloatRect spriteBounds = btSprite.getGlobalBounds();
    FloatRect textBounds = btText.getLocalBounds();
    btText.setOrigin(textBounds.width/2, 0);
    btText.setPosition(spriteBounds.left + spriteBounds.width/2,
                       spriteBounds.top + spriteBounds.height + 5);

    while(window.isOpen()) {
        Event event;        
        while(window.pollEvent(event)) {
            if(event.type == Event::Closed)
                window.close();
       
            if(event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                Vector2i mousePos = Mouse::getPosition(window);
                if(btSprite.getGlobalBounds().contains( // Si en todo el area del Sprite contiene:
                            static_cast<float>(mousePos.x), // Posicion del raton en x
                            static_cast<float>(mousePos.y))) { // Posicion del raton en y
                    cout << "Boton presionado" << endl;
                }
            }
        }

        window.clear(Color::White);
        window.draw(btSprite);
        window.draw(btText);
        window.display();
    }
}
