#include <SFML/Graphics.hpp>
#include <iostream>
#include "Kura.cpp"

using namespace std;
using namespace sf;

int main()
{      
    int windowHeight = 1920;
    int windowWidth = 1080;
    RenderWindow window(VideoMode(windowHeight, windowWidth), "Qurczak Quest", Style::Fullscreen);
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
                if (event.key.code == Keyboard::Escape) window.close();
                if (event.key.code == Keyboard::D) {
                    kura.x += 2;
                    kura.kierunek = "prawo";
                    kura.chodzi = true;
                    kura.krok();

                }
                if (event.key.code == Keyboard::A) {
                    kura.x -= 2;
                    kura.kierunek = "lewo";
                    kura.chodzi = true;
                    kura.krok();
                }
                if (event.key.code == Keyboard::W) if(!kura.lata) kura.skok();
            }
            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::A) kura.chodzi = false;
                if (event.key.code == Keyboard::D) kura.chodzi = false;
            }
        }
        kura.aktualizuj();
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