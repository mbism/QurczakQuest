#include <SFML/Graphics.hpp>
#include <iostream>
#include "Kura.cpp"

using namespace std;
using namespace sf;

int main()
{      
    RenderWindow window(VideoMode(1200, 800), "Qurczak Quest");
    Kura kura;
    kura.rysuj();

    //-----------------------------------GAME------------------------------------------------------------------
    while (window.isOpen())
    {
        //-----------------------------------UPDATE-----------------------------------
        Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) window.close();
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::D) {
                    kura.x += 5;
                    kura.kierunek = "prawo";
                    kura.aktualizuj();

                }
                if (event.key.code == Keyboard::A) {
                    kura.x -= 5;
                    kura.kierunek = "lewo";
                    kura.aktualizuj();
                }
            }
        }
        
        //-----------------------------------UPDATE-----------------------------------


        //-----------------------------------DRAW-----------------------------------
        window.clear(Color::White);
        window.draw(kura.sprite);
        window.display();
        //-----------------------------------DRAW-----------------------------------

    }
    //-----------------------------------GAME------------------------------------------------------------------
    
    return 0;
}