#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

using namespace std;
using namespace sf;

class Skorpion{
private:
	Texture tekstura;
	string sciezkaTekstury = "images/skorpion.png";
	int dlugosc = 90;
	int wysokosc = 50;
	int poczatkoweY = 630 - wysokosc;
	int max = 2; //ilość klatek sprite'a
	clock_t start = clock(); //timer, który pozwala na zmianę sprite'a 
	clock_t koniec; //timer, który pozwala na zmianê sprite'a 
	int i = 0;
	int krok = 2;
public:
	Sprite sprite;
	int poczatkoweX = 900;
	int x = poczatkoweX;
	int y = poczatkoweY;
	string kierunek = "prawo";

	void ustawX(int poczatkoweX_) {
		poczatkoweX = poczatkoweX_;
	}

	void rysuj() {
		if (!tekstura.loadFromFile(sciezkaTekstury)) {
			cout << "Nie załadowano tekstury skorpiona" << endl;
		}
		else {
			sprite.setTexture(tekstura);
			sprite.setPosition(Vector2f(x, y));
			sprite.setTextureRect(IntRect(0, 0, dlugosc, wysokosc));
		}
	}

	void aktualizuj() {
		koniec = clock();
		//cout << "skorpion: i= " << i << "dlugosc i wysokosc: " << dlugosc << wysokosc <<" x i y = "<<x<<" "<<y << endl;
		i = (koniec - start) / 1000 % max;
		if (i > max - 1) i = 0;
		//ruch skorpiona--------------------------------------------------------
		if (kierunek == "prawo") {
			if (x >= poczatkoweX + 200) {
				kierunek = "lewo";
				sprite.scale(Vector2f(-1, 1));
			}
			else {
				if ((koniec - start) / 1000 % 1 == 0) x += krok;
			}
		}
		else {
			if (x <= poczatkoweX - 200) {
				kierunek = "prawo";
				sprite.scale(Vector2f(-1, 1));
			}
			else {
				if ((koniec - start) / 1000 % 1 == 0) x -= krok;
			}
		}
		//-----------------------------------------------------------------------
		sprite.setPosition(Vector2f(x, y));
		sprite.setTextureRect(IntRect(0 + dlugosc * i, 0, dlugosc, wysokosc));
	}

	bool sprawdz(int kx, int ky, int kw, int kh, string kkierunek) {
		int w = dlugosc;
		int h = wysokosc;
		cout << "kura " << kx << " " << ky << " " << kw << " " << kh << " " << kkierunek << " " << endl;
		cout << "skrpion " << x << " " << y << " " << w << " " << h << " " << kierunek << " " << endl;
		if (kkierunek == "prawo") {
			if (kierunek == "prawo") {
				if (kx < x + w && kx + kw > x && ky <= y + h && ky + kh >= y) {
					// Jest kolizja!
					return true;
				}
				else return false;
			}
			else {
				if (kx < x && kx + kw > x-w && ky <= y + h && ky + kh >= y) {
					// Jest kolizja!
					return true;
				}
				else return false;
			}
		}
		else {
			if (kierunek == "prawo") {
				if (kx - kw < x + w && kx > x && ky <= y + h && ky + kh >= y) {
					// Jest kolizja!
					return true;
				}
				else return false;
			}
			else {
				if (kx - kw < x && kx > x - w && ky <= y + h && ky + kh >= y) {
					// Jest kolizja!
					cout << "jest kolizja" << endl;
					return true;
				}
				else return false;
			}
		}
	}
};