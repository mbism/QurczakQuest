#include <SFML/Graphics.hpp>
#include <iostream>
#include "Kura.cpp"
#include "Tlo.cpp"
#include "Skorpion.cpp"
#include "Myszoskoczek.cpp"
#include "Zmija.cpp";
#include "Sep.cpp";
#include "Kurczak.cpp";

using namespace std;
using namespace sf;
//do³aczy³am

int main()
{      
    int windowHeight = 1920;
    int windowWidth = 1080;
    int poziom = 1;
    bool kolizja = false;
    RenderWindow window(VideoMode(windowHeight, windowWidth), "Qurczak Quest", Style::Fullscreen);
    Tlo tlo;
    //sztuczne zmienne
    //tlo.dodajSciezke("pustynia");
    //tlo.granica = -14470;
    //-----------------------------
    tlo.rysuj();
    Kura kura;
    kura.rysuj();
    //---------------POZIOM 3: RYSOWANIE I USTAWIANIE POSTACI
    const int myszN = 6;
    Myszoskoczek myszoskoczki[myszN];
    int myszX[] = { 1000, 4060, 6200, 8000, 8500, 9000 };
    for (int n = 0; n<myszN; n++)
    {
        myszoskoczki[n].rysuj();
        myszoskoczki[n].ustawX(myszX[n]);
    };
    const int skorpioN = 8;
    Skorpion skorpiony[skorpioN];
    int skorpioX[] = { 3560, 4560, 7500, 10300, 10800, 11400, 15100, 15700};
    for (int n = 0; n < skorpioN; n++)
    {
        skorpiony[n].rysuj();
        skorpiony[n].ustawX(skorpioX[n]);
    };
    const int zmijeN = 7;
    Zmija zmije[zmijeN];
    int zmijeX[] = { 2104, 2588, 3072, 5560, 13000, 13700, 14400 };
    for (int n = 0; n < zmijeN; n++){
        zmije[n].rysuj();
        zmije[n].ustawX(zmijeX[n]);
    };
    Kurczak kurczak;
    kurczak.rysuj();
    Sep sep;
    sep.rysuj();
    //--------------------------------------------------------------

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
                            for (int n = 0; n < skorpioN; n++) {
                                skorpiony[n].x -= 10;
                                skorpiony[n].poczatkoweX -= 10;
                            }
                            for (int n = 0; n < myszN; n++) myszoskoczki[n].x -= 10;
                            for (int n = 0; n < zmijeN; n++) zmije[n].x -= 10;
                            sep.x -= 10;
                            kurczak.x -= 10;
                        }

                    }
                    else kura.x += 10;
                    kura.kierunek = "prawo";
                    kura.chodzi = true;
                    kura.krok();
                }
                if (event.key.code == Keyboard::A) {
                    cout << tlo.x << " tlo; " << kura.x << " kura" << endl;
                    if (kura.x <= 580 && kura.x>20 && tlo.x < 0) {
                        tlo.x += 10;
                        tlo.aktualizuj();
                        if (poziom == 3) {
                            for (int n = 0; n < skorpioN; n++) {
                                skorpiony[n].x += 10;
                                skorpiony[n].poczatkoweX += 10;
                            }
                            for (int n = 0; n < myszN; n++) myszoskoczki[n].x += 10;
                            for (int n = 0; n < zmijeN; n++) zmije[n].x += 10;
                            sep.x += 10;
                            kurczak.x += 10;
                        }
                    }
                    else kura.x -= 10;
                    kura.kierunek = "lewo";
                    kura.chodzi = true;
                    kura.krok();
                    if (tlo.x == 0 && kura.x < 190 && kura.kierunek == "lewo") kura.x = 180;
                }
                if (event.key.code == Keyboard::W) if(!kura.lata) kura.skok();
            }
            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::A) kura.chodzi = false;
                if (event.key.code == Keyboard::D) kura.chodzi = false;
            }
        }
        kura.aktualizuj();
        //-----------ZMIANA SPRITE'ÓW I KOLIZJE
        if (poziom == 3) {
            for (int n = 0; n < skorpioN; n++) skorpiony[n].aktualizuj();
            for (int n = 0; n < myszN; n++) myszoskoczki[n].aktualizuj();
            for (int n = 0; n < zmijeN; n++) zmije[n].aktualizuj();
            sep.aktualizuj();
            if(!kurczak.zdobyty) kurczak.aktualizuj();

            //if (kolizja) kura.x = 120;
            for (int n = 0; n < myszN; n++) {
                kolizja = myszoskoczki[n].sprawdz(kura.x, kura.y, kura.dlugosc, kura.wysokosc, kura.kierunek);
                if (kolizja) break;
            }
            if(!kolizja) {
                for (int n = 0; n < skorpioN; n++) {
                    kolizja = skorpiony[n].sprawdz(kura.x, kura.y, kura.dlugosc, kura.wysokosc, kura.kierunek);
                    if (kolizja) break;
                }
            }
            if (!kolizja) {
                for (int n = 0; n < zmijeN; n++) {
                    kolizja = zmije[n].sprawdz(kura.x, kura.y, kura.dlugosc, kura.wysokosc, kura.kierunek);
                    if (kolizja) break;
                }
            }
            if (kolizja) kura.x = 120;
        }
        //-----------ZMIANA SPRITE'ÓW I KOLIZJE

        
        //-----------------------------------UPDATE-----------------------------------
        if (tlo.x == tlo.granica && kura.x >= 1980) {
            cout << "Koniec poziomu" << endl;
            poziom++;
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

            
        }

        //-----------------------------------DRAW-----------------------------------
        window.clear();
        window.draw(tlo.sprite);
        window.draw(kura.sprite);
        if (poziom == 3) {
            for (int n = 0; n < skorpioN; n++) window.draw(skorpiony[n].sprite);
            for (int n = 0; n < myszN; n++) window.draw(myszoskoczki[n].sprite);
            for (int n = 0; n < zmijeN; n++) window.draw(zmije[n].sprite);
            window.draw(sep.sprite);
            if (!kurczak.zdobyty) {
                kurczak.sprawdz(kura.x, kura.y, kura.dlugosc, kura.wysokosc, kura.kierunek);
                window.draw(kurczak.sprite);
            }
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