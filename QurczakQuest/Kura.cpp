#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

using namespace std;
using namespace sf;

class Kura {
private:
	Texture tekstura;
	string sciezkaTekstury = "images/kura.png";
	string kierunekUprzedni = "prawo";
	int i = 0; //o ile razy ma sie przesunie prostokat wyciety ze sprite'a
	int podloga = 630-140;
	clock_t start = clock(); //timer, który pozwala na zmianê sprite'a 
	clock_t koniec; //timer, który pozwala na zmianê sprite'a 
public:
	Sprite sprite;
	int x = 120;
	int y = podloga;
	string kierunek = "prawo";
	int dlugosc = 140;
	int wysokosc = 140;
	bool do_gory = false;
	bool na_dol = false;
	bool lata = false;
	bool chodzi = false;

	void rysuj() {
		if (!tekstura.loadFromFile(sciezkaTekstury)) {
			cout << "Nie za³adowano tekstury kury" << endl;
		}
		else {
			sprite.setTexture(tekstura);
			sprite.setPosition(Vector2f(x, y));
			sprite.scale(Vector2f(2, 2));
			sprite.setTextureRect(IntRect(0, 0, 70, 70));
		}
	}

	void aktualizuj() {
		if (lata) {
			dlugosc = 180;
			wysokosc = 100;
			if (do_gory) {
				if (y >= podloga - 140) y -= 2;
				else {
					na_dol = true;
					do_gory = false;
				}
			}
			else if (na_dol) {
				if (y <= podloga) y += 2;
				else na_dol = false;
			}
			else if (chodzi && (x > 580 && x < 1200)) {
				if (kierunek == "prawo") x += 10;
				else x -= 10;
			}
			else lata = false;
			koniec = clock();
			i = ((koniec - start) / 100) % 3;
			if (i > 2) i = 0;
			if (lata) sprite.setTextureRect(IntRect(0 + 90 * i, 140, 90, 50));
			else sprite.setTextureRect(IntRect(0, 0, 70, 70));
			sprite.setPosition(Vector2f(x, y));
		}
		else if (!chodzi) {
			koniec = clock();
			i = ((koniec - start) / 1000) % 2;
			if (i > 1) i = 0;
			sprite.setTextureRect(IntRect(0 + i * 70, 0, 70, 70));
		}
	}

	void krok() {
		int ilosc = 4;
		int wysokosc = 70;
		int dlugosc = 70;
		int miejsceY = 70;
		if (lata) {
			ilosc = 2;
			wysokosc = 50;
			dlugosc = 90;
			miejsceY = 140;
		}
		if (kierunek != kierunekUprzedni) {
			sprite.scale(Vector2f(-1, 1));
			kierunekUprzedni = kierunek;
			if (kierunek == "prawo") x -= dlugosc;
			else x += dlugosc;
		}
		sprite.setPosition(Vector2f(x, y));
		koniec = clock();
		i = ((koniec-start)/100) % ilosc;
		if (i > ilosc) i = 0;
		sprite.setTextureRect(IntRect(0 + dlugosc * i, miejsceY, dlugosc, wysokosc));
	}

	void skok() {
		lata = true;
		do_gory = true;
	}
};