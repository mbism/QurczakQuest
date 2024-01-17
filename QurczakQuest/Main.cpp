#include <SFML/Graphics.hpp>
#include <iostream>
#include "Kura.cpp"
#include "Tlo.cpp"
//#include "Pien.cpp"
#include "Jez.cpp"
#include "Zajac.cpp"
#include "Skorpion.cpp"
#include "Myszoskoczek.cpp"
#include "Zmija.cpp";
#include "Sep.cpp";
#include "Kurczak.cpp";
#include "Statystyki.cpp";
#include "Gameover.cpp"
#include "Koniec.cpp"

using namespace std;
using namespace sf;

int main()
{   
    //TYMCZASOWE JAK JEST MENU TO DAJ PO TYM
    Clock zg;
    
    int windowHeight = 1920;
    int windowWidth = 1080;
    int poziom = 1;
    bool kolizja = false;
    RenderWindow window(VideoMode(windowHeight, windowWidth), "Qurczak Quest", Style::Fullscreen);
    window.setFramerateLimit(60);
    Tlo tlo;
    //sztuczne zmienne
   // tlo.dodajSciezke("miasto");
    //tlo.granica = -13450;

    //-----------------------------
    tlo.rysuj();
    Kura kura;
    kura.rysuj();
    Statystyki statystyki;
    Gameover smierc;
    Ending koniec;
    
    //---------------POZIOM 3: RYSOWANIE I USTAWIANIE POSTACI
  //  const int drzewN = 6;
  //  Pien drzewo[drzewN];
 //   int drzewX[] = { 1000, 4060, 6200, 8000, 8500, 9000 };
  //  for (int n = 0; n < drzewN; n++)
  //  {
 //       drzewo[n].rysuj();
 //       drzewo[n].ustawX(drzewX[n]);
 //   };
    const int jerzN = 7;
    Jerz jerze[jerzN];
    int jerzX[] = { 950, 2325, 3000, 4300, 7000, 9600, 10500 };
    for (int n = 0; n < jerzN; n++) {
        jerze[n].rysuj();
        jerze[n].ustawX(jerzX[n]);
    };
    const int zajacN = 7;
    Zajac zajace[zajacN];
    int zajacX[] = { 1950, 2700, 3500, 5400, 8800, 9200, 10000 };
    for (int n = 0; n < zajacN; n++) {
        zajace[n].rysuj();
        zajace[n].ustawX(zajacX[n]);
    };
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
                        if (poziom == 1) {
                            for (int n = 0; n < jerzN; n++) jerze[n].x -= 10;
                            for (int n = 0; n < zajacN; n++) zajace[n].x -= 10;
                        }
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
                        if (poziom == 1) {
                            for (int n = 0; n < jerzN; n++) jerze[n].x += 10;
                            for (int n = 0; n < zajacN; n++) zajace[n].x += 10;
                        }
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
        if (poziom == 1) {
            for (int n = 0; n < zajacN; n++) zajace[n].aktualizuj();
            for (int n = 0; n < jerzN; n++) jerze[n].aktualizuj();

                for (int n = 0; n < zajacN; n++) {
                    kolizja = zajace[n].sprawdz(kura.x, kura.y, kura.dlugosc, kura.wysokosc, kura.kierunek);
                    if (kolizja) break;
                }
                if (!kolizja) {
                    for (int n = 0; n < jerzN; n++) {
                        kolizja = jerze[n].sprawdz(kura.x, kura.y, kura.dlugosc, kura.wysokosc, kura.kierunek);
                        if (kolizja) break;
                    }
                }
        }
        if (poziom == 3) {
            for (int n = 0; n < skorpioN; n++) skorpiony[n].aktualizuj();
            for (int n = 0; n < myszN; n++) myszoskoczki[n].aktualizuj();
            for (int n = 0; n < zmijeN; n++) zmije[n].aktualizuj();
            sep.aktualizuj();
            kurczak.aktualizuj();

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
        }

        if (kolizja) {
            smierc.rysuj(window);
            tlo.x = 0;
            kura.x = 50;
            if (poziom == 1) {
                for (int n = 0; n < zajacN; n++)
                {
                    zajace[n].ustawX(zajacX[n]);
                };
                for (int n = 0; n < jerzN; n++) {
                    jerze[n].ustawX(jerzX[n]);
                }
                for (int n = 0; n < jerzN; n++) zajace[n].aktualizuj();
                for (int n = 0; n < jerzN; n++) jerze[n].aktualizuj();
            }
            if (poziom == 3) {
                for (int n = 0; n < myszN; n++)
                {
                    myszoskoczki[n].ustawX(myszX[n]);
                };
                for (int n = 0; n < skorpioN; n++)
                {
                    skorpiony[n].ustawX(skorpioX[n]);
                };
                for (int n = 0; n < zmijeN; n++) {
                    zmije[n].ustawX(zmijeX[n]);
                }
                sep.x = sep.poczatkoweX;
                kurczak.x = kurczak.poczatkoweX;
                for (int n = 0; n < skorpioN; n++) skorpiony[n].aktualizuj();
                for (int n = 0; n < myszN; n++) myszoskoczki[n].aktualizuj();
                for (int n = 0; n < zmijeN; n++) zmije[n].aktualizuj();
                sep.aktualizuj();
                kurczak.aktualizuj();
            }
        }
        //-----------ZMIANA SPRITE'ÓW I KOLIZJE

        
        //-----------------------------------UPDATE-----------------------------------
        if (tlo.x == tlo.granica && kura.x >= 1980) {
            cout << "Koniec poziomu" << endl;
            statystyki.czas = zg.getElapsedTime().asSeconds();
            
            poziom++;
            if (poziom == 2) {
                // KOD NA EKRAN PO POZIOMIE I LAS PODSIAD£A
                statystyki.zdobytePoziomy++;
                statystyki.rysuj(window);
                zg.restart();
                tlo.dodajSciezke("miasto");
                tlo.x = 0;
                tlo.granica = -13450;
                tlo.rysuj();
                kura.x = 50;
            }
            else if (poziom == 3) {
                // KOD NA EKRAN PO POZIOMIE I PIOSENKA O MIEŒCIE (proponujê Sen o Warszawie Niemena)
                statystyki.zdobytePoziomy++;
                statystyki.rysuj(window);
                zg.restart();
                tlo.dodajSciezke("pustynia");
                tlo.x = 0;
                tlo.granica = -14470;
                tlo.rysuj();
                kura.x = 50;
            }
            else {
                //KOD NA EKRAN PO POZIOMIE (WYGRANA !!!) NIE MA WODY NA PYSTYNI BAJMU
                statystyki.zdobytePoziomy++;
                statystyki.rysuj(window);
                koniec.rysuj(window);
            }
            
        }

        //-----------------------------------DRAW-----------------------------------
        window.clear();
        window.draw(tlo.sprite);
        window.draw(kura.sprite);
        if (poziom == 1) {
            for (int n = 0; n < zajacN; n++) window.draw(zajace[n].sprite);
            for (int n = 0; n < jerzN; n++) window.draw(jerze[n].sprite);
        }
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


        window.display();
        //-----------------------------------DRAW-----------------------------------

    }
    //-----------------------------------GAME------------------------------------------------------------------
    
    return 0;
}