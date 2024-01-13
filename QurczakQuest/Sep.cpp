#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

using namespace std;
using namespace sf;

class Sep {
private:
	Texture tekstura;
	string sciezkaTekstury = "images/sep.png";
	int wysokosc = 100;
	int dlugosc = 125;
	int podloga = 130;
	clock_t start, koniec; //timery, które pozwalaja na zmiane sprite'a 
	int i = 0;
	int max = 2;
public:
	Sprite sprite;
	int poczatkoweX = 16060;
	int x = poczatkoweX;
	int y = podloga;

	void rysuj() {
		start = clock();
		if (!tekstura.loadFromFile(sciezkaTekstury)) {
			cout << "Nie za³adowano tekstury sepa" << endl;
		}
		else {
			sprite.setTexture(tekstura);
			sprite.setPosition(Vector2f(x, y));
			sprite.scale(Vector2f(2, 2));
			sprite.setTextureRect(IntRect(0, 0, dlugosc, wysokosc));
		}
	}

	void aktualizuj() {
		cout << "sep y: " << y << " x: " << x << endl;
		koniec = clock();
		if (koniec - start > 500) {
			i++;
			start = clock();
			if (i >= max) i = 0;
		}
		sprite.setPosition(Vector2f(x, y));
		sprite.setTextureRect(IntRect(0 + dlugosc * i, 0, dlugosc, wysokosc));

	}

	bool sprawdz(int kx, int ky, int kw, int kh, string kkierunek) {
		int w = dlugosc*2;
		int h = wysokosc*2;
		//cout << "kura " << kx << " " << ky << " " << kw << " " << kh << " " << kkierunek << " " << endl;
		//cout << "sep " << x << " " << y << " " << w << " " << h << endl;
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