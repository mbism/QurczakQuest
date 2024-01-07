#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>

using namespace std;
using namespace sf;
using namespace chrono;

class Statystyki {

private:
    int zdobytePoziomy;
    steady_clock::time_point czasRozpoczecia;
    steady_clock::time_point czasZakonczenia;
    steady_clock::duration najlepszyWynik;
    Texture tekstura;
    string sciezkaTekstury = "images/kura.png";

public:
    Sprite sprite;
    Statystyki() : zdobytePoziomy(0), najlepszyWynik(steady_clock::duration::max()) {      //konstruktor
            if (!tekstura.loadFromFile(sciezkaTekstury)) {
                cout << "Nie za³adowano tekstury kury" << endl;
            }
            else {
                sprite.setTexture(tekstura);
                sprite.setPosition(Vector2f(1750, 910));
                sprite.scale(Vector2f(2, 2));
                sprite.setTextureRect(IntRect(0, 0, 70, 70));
            }
        }

    void zapiszCzasRozpoczecia() {
        czasRozpoczecia = steady_clock::now();
    }

    void zapiszCzasZakonczenia() {
        czasZakonczenia = steady_clock::now();
    }

    duration<int> zmierzCzasTrwania() {
        return duration_cast<chrono::seconds>(czasZakonczenia - czasRozpoczecia);
    }

    void rysuj(RenderWindow& window) {
        Font czcionka;
        if (!czcionka.loadFromFile("comicsans.ttf")) {
            cout << "B³¹d ³adowania czcionki.\n";
            return;
        }

        Text tekstStatystyk;
        tekstStatystyk.setFont(czcionka);
        tekstStatystyk.setCharacterSize(35);
        tekstStatystyk.setFillColor(Color::White);
        tekstStatystyk.setPosition(30, 540);

        Text tekstStatystyk1;
        tekstStatystyk1.setFont(czcionka);
        tekstStatystyk1.setCharacterSize(24);
        tekstStatystyk1.setFillColor(Color::White);
        tekstStatystyk1.setPosition(70, 540);

        auto czasTrwania = zmierzCzasTrwania();
        if (czasTrwania > najlepszyWynik)
        {
            najlepszyWynik = czasTrwania;
        }

        tekstStatystyk.setString("Udalo ci sie ukonczyc poziom. Wyniki:");
        tekstStatystyk1.setString("Zdobyte poziomy: " + to_string(zdobytePoziomy) +
            "\nCzas przechodzenia poziomu: " + to_string(czasTrwania.count()) + "s" +                     // \n bo w stringu
            "\nNajlepszy wynik: " + to_string(najlepszyWynik.count()) + "s");         

        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                }
            }

            window.clear();
            window.draw(tekstStatystyk);
            window.draw(tekstStatystyk1);
            window.draw(sprite);
            window.display();
        }
    }
};