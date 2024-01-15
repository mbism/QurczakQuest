#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>

using namespace std;
using namespace sf;

class Ending {

private:
    Texture tekstura;
    string sciezkaTekstury = "images/kura.png";
    string sciezkaCzcionki = "pixelmix.ttf";


public:
    Sprite sprite;
    bool open2 = false;

    void rysuj(RenderWindow& window) {
        open2 = true;

        if (!tekstura.loadFromFile(sciezkaTekstury)) {
            cout << "Nie zaladowano tekstury kury" << endl;
        }
        else {
            sprite.setTexture(tekstura);
            sprite.setPosition(Vector2f(1750, 910));
            sprite.scale(Vector2f(2, 2));
            sprite.setTextureRect(IntRect(0, 0, 70, 70));
        }

        Font czcionka;
        if (!czcionka.loadFromFile(sciezkaCzcionki))
            throw("Blad ladowania czcionki");

        Text tekst;
        tekst.setFont(czcionka);
        tekst.setCharacterSize(65);
        tekst.setFillColor(Color::White);
        tekst.setStyle(Text::Bold);
        tekst.setPosition(125, 300);

        Text tekst2;
        tekst2.setFont(czcionka);
        tekst2.setCharacterSize(45);
        tekst2.setFillColor(Color::White);
        tekst2.setStyle(Text::Bold);
        tekst2.setPosition(750, 500);

        Text tekst1;
        tekst1.setFont(czcionka);
        tekst1.setCharacterSize(25);
        tekst1.setFillColor(Color::White);
        tekst1.setStyle(Text::Bold);
        tekst1.setPosition(45, 980);

        tekst.setString("Gratulacje, udalo Ci sie przejsc gre!");
        tekst2.setString("Gra skonczona.");
        tekst1.setString("Aby przejsc dalej, nacisnij Enter.");

        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                }
                if (Keyboard::isKeyPressed(Keyboard::Enter))
                {
                    //window.close();
                    open2 = false;
                }
                if (event.type == Keyboard::Escape) window.close();
            }

            if (open2) {
                window.clear();
                window.draw(tekst);
                window.draw(tekst1);
                window.draw(tekst2);
                window.draw(sprite);
                window.display();
            }
            else {
               break;
            }
        }
    }
};