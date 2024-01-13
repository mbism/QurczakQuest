#include <SFML/Graphics.hpp>
#include <iostream>
#include "Kura.cpp"
#include "Tlo.cpp"
#include "Skorpion.cpp"
#include "Wiewiora.cpp"
#include "Statystyki.cpp"
#include "Gameover.cpp"

using namespace std;
using namespace sf;
using namespace chrono;

int main()
{
    int windowHeight = 1920;
    int windowWidth = 1080;
    int poziom = 1;
    int podloga = 550;
    RenderWindow window(VideoMode(windowHeight, windowWidth), "Qurczak Quest", Style::Fullscreen);
    Tlo tlo;
    //sztuczne zmienne
    //tlo.dodajSciezke("pustynia");
    //tlo.x = -8430;
    //-----------------------------
    tlo.rysuj();
    Kura kura;
    kura.rysuj();
    Skorpion skorpion;
    Statystyki statystyki;
    Wiewiora wiewiora;
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
                    cout << tlo.x << " tlo; " << kura.x << " kura" << endl;
                    if (kura.x > 1200 && tlo.x > tlo.granica) {
                        tlo.x -= 10;
                        tlo.aktualizuj();
                        if (poziom == 3) {
                            skorpion.x -= 10;
                            skorpion.poczatkoweX -= 10;
                        }

                    }
                    else kura.x += 10;
                    kura.kierunek = "prawo";
                    kura.chodzi = true;
                    kura.krok();
                }
                if (event.key.code == Keyboard::A) {
                    cout << tlo.x << " tlo; " << kura.x << " kura" << endl;
                    if (kura.x <= 580 && kura.x > 20 && tlo.x < 0) {
                        tlo.x += 10;
                        tlo.aktualizuj();
                        if (poziom == 3) {
                            skorpion.x += 10;
                            skorpion.poczatkoweX += 10;
                        }
                    }
                    else kura.x -= 10;
                    kura.kierunek = "lewo";
                    kura.chodzi = true;
                    kura.krok();
                    if (tlo.x == 0 && kura.x < 190 && kura.kierunek == "lewo") kura.x = 180;
                }
                if (event.key.code == Keyboard::W) if (!kura.lata) kura.skok();
            }
            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::A) kura.chodzi = false;
                if (event.key.code == Keyboard::D) kura.chodzi = false;
            }
        }
        kura.aktualizuj();
        if (poziom == 3) {
            skorpion.aktualizuj();
            bool kolizja = skorpion.sprawdz(kura.x, kura.y, kura.dlugosc, kura.wysokosc, kura.kierunek);
            if (kolizja) kura.x = 120;
        }


        //-----------------------------------UPDATE-----------------------------------
        if (tlo.x == tlo.granica && kura.x >= 1980) {
            cout << "Koniec poziomu" << endl;
            statystyki.zdobytePoziomy++;
            statystyki.zapiszCzasZakonczenia();
            if (poziom == 2) {
                // KOD NA EKRAN PO POZIOMIE I LAS PODSIAD£A
                tlo.dodajSciezke("miasto");
                tlo.x = 0;
                tlo.granica = -13450;
                tlo.rysuj();
                kura.x = 50;
            }
            else if (poziom == 3) {
                // KOD NA EKRAN PO POZIOMIE I PIOSENKA O MIEŒCIE (proponujê Sen o Warszawie Niemena)
                tlo.dodajSciezke("pustynia");
                tlo.x = 0;
                tlo.granica = -14470;
                tlo.rysuj();
                kura.x = 50;
            }
            else {
                //KOD NA EKRAN PO POZIOMIE (WYGRANA !!!) NIE MA WODY NA PYSTYNI BAJMU
            }

            statystyki.rysuj(window);
            poziom++;
        }

        //-----------------------------------DRAW-----------------------------------
        window.clear();
        window.draw(tlo.sprite);
        window.draw(kura.sprite);
        if (poziom == 3) {
            window.draw(skorpion.sprite);
        }
        if (poziom == 1) {
            window.draw(wiewiora.sprite);
        }

        /*Vertex line[] =
        {
            Vertex(Vector2f(kura.x, 200)),
            Vertex(Vector2f(kura.x, 600))
        };
        window.draw(line, 2, Lines);
        */
        window.display();
        //-----------------------------------DRAW-----------------------------------

    }
    //-----------------------------------GAME------------------------------------------------------------------

    return 0;
}