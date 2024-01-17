#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>

using namespace std;
using namespace sf;
using namespace chrono;


class Statystyki {

private:
    Texture tekstura;
    string sciezkaTekstury = "images/kura.png";
    string sciezkaCzcionki = "pixelmix.ttf";
    float najlepszyWynik;

public:
    float czas;
    int zdobytePoziomy;
    Sprite sprite;
    bool open = false;
    Statystyki() : zdobytePoziomy(0), najlepszyWynik(FLT_MAX), czas(0) {      //konstruktor
        if (!tekstura.loadFromFile(sciezkaTekstury)) {
            cout << "Nie zaladowano tekstury kury" << endl;
        }
        else {
            sprite.setTexture(tekstura);
            sprite.setPosition(Vector2f(1750, 910));
            sprite.scale(Vector2f(2, 2));
            sprite.setTextureRect(IntRect(0, 0, 70, 70));
        }
    }

    void rysuj(RenderWindow& window) {
        open = true;
        Font czcionka;
        if (!czcionka.loadFromFile(sciezkaCzcionki))
            throw("Blad ladowania czcionki");


        Text tekstStatystyk;
        tekstStatystyk.setFont(czcionka);
        tekstStatystyk.setCharacterSize(65);
        tekstStatystyk.setFillColor(Color::White);
        tekstStatystyk.setStyle(Text::Bold);
        tekstStatystyk.setPosition(400, 175);

        Text tekstStatystyk1;
        tekstStatystyk1.setFont(czcionka);
        tekstStatystyk1.setCharacterSize(40);
        tekstStatystyk1.setFillColor(Color::White);
        tekstStatystyk1.setStyle(Text::Bold);
        tekstStatystyk1.setPosition(880, 330);

        Text tekstStatystyk2;
        tekstStatystyk2.setFont(czcionka);
        tekstStatystyk2.setCharacterSize(40);
        tekstStatystyk2.setFillColor(Color::White);
        tekstStatystyk2.setStyle(Text::Bold);
        tekstStatystyk2.setPosition(735, 420);


        Text tekstStatystyk3;
        tekstStatystyk3.setFont(czcionka);
        tekstStatystyk3.setCharacterSize(40);
        tekstStatystyk3.setFillColor(Color::White);
        tekstStatystyk3.setStyle(Text::Bold);
        tekstStatystyk3.setPosition(575, 490);


        Text tekstStatystyk4;
        tekstStatystyk4.setFont(czcionka);
        tekstStatystyk4.setCharacterSize(40);
        tekstStatystyk4.setFillColor(Color::White);
        tekstStatystyk4.setStyle(Text::Bold);
        tekstStatystyk4.setPosition(735, 560);

        Text tekstStatystyk5;
        tekstStatystyk5.setFont(czcionka);
        tekstStatystyk5.setCharacterSize(25);
        tekstStatystyk5.setFillColor(Color::White);
        tekstStatystyk5.setStyle(Text::Bold);
        tekstStatystyk5.setPosition(45, 980);

        if (czas < najlepszyWynik) {
            najlepszyWynik = czas;
        }

        int minut = czas / 60;
        int sekund = int(czas)%60;
        int minut1 = najlepszyWynik / 60;
        int sekund1 = int(najlepszyWynik) % 60;

        tekstStatystyk.setString("Udalo ci sie ukonczyc poziom!");
        tekstStatystyk1.setString("Wyniki:");
        tekstStatystyk2.setString("Zdobyte poziomy: " + to_string(zdobytePoziomy));
        tekstStatystyk3.setString("Czas przechodzenia poziomu: " + to_string(minut) +":"+to_string(sekund) + "min");
        tekstStatystyk4.setString("Najlepszy wynik: " + to_string(minut) + ":" + to_string(sekund) + "min");
        tekstStatystyk5.setString("Aby przejsc dalej, nacisnij Enter.");

        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                }
                if (Keyboard::isKeyPressed(Keyboard::Enter))
                {
                    open = false;
                    break;
                }
                if (Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    window.close();
                }
            }

            if (open) {
                window.clear();
                window.draw(tekstStatystyk);
                window.draw(tekstStatystyk1);
                window.draw(tekstStatystyk2);
                window.draw(tekstStatystyk3);
                window.draw(tekstStatystyk4);
                window.draw(tekstStatystyk5);
                window.draw(sprite);
                window.display();
            }
            else{
                break;
            }
        }
    }
};