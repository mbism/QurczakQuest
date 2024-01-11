#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

using namespace std;
using namespace sf;


class Myszoskoczek {
private:
	Texture tekstura;
	string sciezkaTekstury = "images/myszoskoczek.png";
	int dlugosc = 45;
	int wysokosc = 70;
	int podloga = 630 - wysokosc;
	int sufit = 350;
	clock_t start, koniec; //timery, które pozwalaja na zmiane sprite'a 
	int i = 0;
	int krok = 2;
public:
	Sprite sprite;
	int poczatkoweX = 1200;
	int x = poczatkoweX;
	int y = podloga;
	bool w_gorze = false;
	bool na_dole = true;
	bool wstrzymaj = true;

	void ustawX(int poczatkoweX_) {
		poczatkoweX = poczatkoweX_;
		x = poczatkoweX_;
	}

	void rysuj() {
		start = clock();
		if (!tekstura.loadFromFile(sciezkaTekstury)) {
			cout << "Nie załadowano tekstury myszoskoczka" << endl;
		}
		else {
			sprite.setTexture(tekstura);
			sprite.setPosition(Vector2f(x, y));
			sprite.setTextureRect(IntRect(0, 0, dlugosc, wysokosc));
		}
	}

	void aktualizuj() {
		if (y >= podloga && wstrzymaj == false) {
			wstrzymaj = true;
			na_dole = true;
			w_gorze = false;
			start = clock();
			i = 0;
		}
		else if (wstrzymaj) {
			koniec = clock();
			if ((koniec - start)/CLOCKS_PER_SEC > 1) {
				wstrzymaj = false;
				y -= krok;
				i = 1;
			}
		}
		else {
			if (na_dole) {
				if (y <= sufit) {
					na_dole = false;
					w_gorze = true;
				}
				else y -= krok;
			}
			else y += krok;
		}
		sprite.setPosition(Vector2f(x, y));
		sprite.setTextureRect(IntRect(0 + dlugosc * i, 0, dlugosc, wysokosc));
		
	}

	bool sprawdz(int kx, int ky, int kw, int kh, string kkierunek) {
		int w = dlugosc;
		int h = wysokosc;
		//cout << "kura " << kx << " " << ky << " " << kw << " " << kh << " " << kkierunek << " " << endl;
		//cout << "myszoskoczek " << x << " " << y << " " << w << " " << h << endl;
		if (kkierunek == "prawo") {
			if (kx < x + w && kx + kw > x && ky <= y + h && ky + kh >= y) {
				// Jest kolizja!
				return true;
			}
			else return false;
		}
		else {
			if (kx - kw < x + w && kx > x && ky <= y + h && ky + kh >= y) {
				// Jest kolizja!
				return true;
			}
			else return false;	
		}
	}
};