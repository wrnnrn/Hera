#include <SFML/Graphics.hpp>
#include "src/config.h" // Window config file 

using namespace sf;
String windowName = "Hera - Pantalla Principal";

int main() {
    // Window Properties
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), windowName);
    
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed){
                window.close();
            }
        }

        window.clear(Color(77, 77, 77));
        window.display();
    }
}
