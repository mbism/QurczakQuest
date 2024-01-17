#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

using namespace std;
using namespace sf;

class Pien {
private:
	Texture tekstura;
	string sciezkaTekstury = "images/pien.png";
	//	int wymiar = 100;
	int podloga = 630 - 70;
	//	clock_t start, koniec; //timery, które pozwalaja na zmiane sprite'a 
	//	int max = 5; // iloœæ klatek w spricie
	int krok = 2;
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
		//		start = clock();
		if (!tekstura.loadFromFile(sciezkaTekstury)) {
			cout << "Nie za³adowano tekstury pnia" << endl;
		}
		else {
			tekstura.setSmooth(true);
			sprite.setTexture(tekstura);
			sprite.setTextureRect(IntRect(0, 0, 100, 70));
			sprite.setPosition(Vector2f(x, y));
		}
	}


	void aktualizuj() {
		sprite.setPosition(Vector2f(x, y));
		sprite.setTextureRect(IntRect(0, 0, 100, 70));
	}

	bool sprawdz(int kx, int ky, int kw, int kh, string kkierunek) {
		//cout << "kura " << kx << " " << ky << " " << kw << " " << kh << " " << kkierunek << " " << endl;
		//cout << "zmija " << x << " " << y << " " << wymiar  << endl;
		if (kkierunek == "prawo") {
			if (kx < x + 100 && kx + kw > x && ky <= y + 70 && ky + kh >= y) {
				// Jest kolizja!
				return true;
			}
			else return false;
		}
		else {
			if (kx - kw < x + 100 && kx > x && ky <= y + 70 && ky + kh >= y) {
				// Jest kolizja!
				return true;
			}
			else return false;
		}
	}
};