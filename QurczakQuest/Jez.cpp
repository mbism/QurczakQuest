#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

using namespace std;
using namespace sf;

class Jerz {
private:
	Texture tekstura;
	string sciezkaTekstury = "images/jerz.png";
	int wymiar = 80;
	int podloga = 630 - wymiar;
	clock_t start, koniec; //timery, które pozwalaja na zmiane sprite'a 
	int max = 1; // iloœæ klatek w spricie
	int i = 0;
public:
	Sprite sprite;
	int poczatkoweX = 1000;
	int x = poczatkoweX;
	int y = podloga;

	void ustawX(int poczatkoweX_) {
		poczatkoweX = poczatkoweX_;
		x = poczatkoweX_;
	}

	void rysuj() {
		start = clock();
		if (!tekstura.loadFromFile(sciezkaTekstury)) {
			cout << "Nie za³adowano tekstury jezyka" << endl;
		}
		else {
			sprite.setTexture(tekstura);
			sprite.setPosition(Vector2f(x, y));
			sprite.setTextureRect(IntRect(0, 0, wymiar, wymiar));
		}
	}

	void aktualizuj() {
		koniec = clock();
		cout << koniec - start << endl;
		if ((koniec - start) > 500) {
			i++;
			start = clock();
			if (i > max) i = 0;
		}
		sprite.setPosition(Vector2f(x, y));
		sprite.setTextureRect(IntRect(0 + wymiar * i, 0, wymiar, wymiar));

	}

	bool sprawdz(int kx, int ky, int kw, int kh, string kkierunek) {
		//cout << "kura " << kx << " " << ky << " " << kw << " " << kh << " " << kkierunek << " " << endl;
		//cout << "zmija " << x << " " << y << " " << wymiar  << endl;
		if (kkierunek == "prawo") {
			if (kx < x + wymiar && kx + kw > x && ky <= y + wymiar && ky + kh >= y) {
				// Jest kolizja!
				return true;
			}
			else return false;
		}
		else {
			if (kx - kw < x + wymiar && kx > x && ky <= y + wymiar && ky + kh >= y) {
				// Jest kolizja!
				return true;
			}
			else return false;
		}
	}
};