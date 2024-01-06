#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <chrono>
#include <vector>
#include <math.h>
#include "Kura.cpp"
#include "WrogLas.cpp"

using namespace std;
using namespace sf;

Vector2f NormalizeVector(Vector2f vector)
{
    float m = sqrt(vector.x * vector.x + vector.y * vector.y);

    Vector2f normalizedVector;

    normalizedVector.x = vector.x / m;
    normalizedVector.y = vector.y / m;

    return normalizedVector;
}

int main()
{
    int windowHeight = 1920;
    int windowWidth = 1080;
    RenderWindow window(VideoMode(windowHeight, windowWidth), "Qurczak Quest", Style::Fullscreen);
    Texture teksturaTla;
    Sprite tlo;
    string sciezkaTla = "images/pustynia.png";
    if (!teksturaTla.loadFromFile(sciezkaTla)) {
        cout << "Nie za�adowano tekstury kury" << endl;
    }
    else {
        tlo.setTexture(teksturaTla);
        tlo.setPosition(Vector2f(0, 0));
        tlo.scale(Vector2f(1, 1)); 
    }

    vector < CircleShape > bullets;
    float bulletSpeed = 0.5f;
    Vector2f bulletDirection;

    Kura kura;
    WrogLas wiewiora;
    kura.rysuj();
    wiewiora.rysuj();

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
                if (event.key.code == Keyboard::W) if (!kura.lata) kura.skok();
            }
            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::A) kura.chodzi = false;
                if (event.key.code == Keyboard::D) kura.chodzi = false;
            }

            if (Mouse::isButtonPressed(Mouse::Button::Left))
            {
                bullets.push_back(CircleShape(12.5)); // Przyk�adowy promie� dla kuli

                int i = bullets.size() - 1;
                bullets[i].setPosition((kura.sprite).getPosition());

                // Ustawienie po�o�enia na �rodek kuli
                bullets[i].setOrigin(bullets[i].getRadius(), bullets[i].getRadius());
            }

            for (size_t i = 0; i < bullets.size(); i++)
            {
                Vector2f bulletDirection = (wiewiora.sprite).getPosition() - bullets[i].getPosition();
                bulletDirection = NormalizeVector(bulletDirection);
                bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
            }


        }
            kura.aktualizuj();
        //-----------------------------------UPDATE-----------------------------------


        //-----------------------------------DRAW-----------------------------------
        window.clear(Color::White);
        window.draw(tlo);
        window.draw(kura.sprite);
        window.draw(wiewiora.sprite);
        for (size_t i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }
        window.display();
        //-----------------------------------DRAW-----------------------------------

    }
    //-----------------------------------GAME------------------------------------------------------------------
    
    return 0;
}