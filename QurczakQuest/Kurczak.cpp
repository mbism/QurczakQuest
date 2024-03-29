#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

using namespace std;
using namespace sf;

class Kurczak {
private:
	Texture tekstura;
	string sciezkaTekstury = "images/kurczak.png";
	int wymiar = 70;
	int podloga = 435;
	clock_t start, koniec; //timery, kt�re pozwalaja na zmiane sprite'a 
	int max = 5; // ilo�� klatek w spricie
	int i = 0;
public:
	Sprite sprite;
	int poczatkoweX = 15960;
	int x = poczatkoweX;
	int y = podloga;
	bool zdobyty = false;

	void rysuj() {
		start = clock();
		if (!tekstura.loadFromFile(sciezkaTekstury)) {
			cout << "Nie za�adowano tekstury myszoskoczka" << endl;
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
		if ((koniec - start) > 800) {
			i++;
			start = clock();
			if (i >= max) i = 0;
		}
		sprite.setPosition(Vector2f(x, y));
		sprite.setTextureRect(IntRect(0 + wymiar * i, 0, wymiar, wymiar));

	}

	void sprawdz(int kx, int ky, int kw, int kh, string kkierunek) {
		//cout << "kura " << kx << " " << ky << " " << kw << " " << kh << " " << kkierunek << " " << endl;
		//cout << "kurczak " << x << " " << y << " " << wymiar  << endl;
		if (kkierunek == "prawo") {
			if (kx < x + wymiar && kx + kw > x && ky <= y + wymiar && ky + kh >= y) {
				zdobyty = true;
			}
		}
		else {
			if (kx - kw < x + wymiar && kx > x && ky <= y + wymiar && ky + kh >= y) {
				zdobyty = true;
			}
		}
	}
};