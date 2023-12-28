#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Kura {
private:
	Texture tekstura;
	string sciezkaTekstury = "images/testowe.png";
	string kierunekUprzedni = "prawo";
	int i = 0; //o ile razy ma siê przesun¹æ prostok¹t wyciêty ze sprite'a
	int podloga = 500 - 24;
	int y = podloga;
public:
	Sprite sprite;
	int x = 20;
	string kierunek = "prawo";
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
			sprite.setTextureRect(IntRect(0, 80, 30, 24));
		}
	}

	void aktualizuj() {
		if (lata) {
			if (do_gory) {
				if (y >= podloga - 60) y -= 2;
				else {
					na_dol = true;
					do_gory = false;
				}
			}
			else if (na_dol) {
				if (y <= podloga) y += 2;
				else na_dol = false;
			}
			else lata = false;
			if (chodzi) {
				if (kierunek == "prawo") x += 2;
				else x -= 2;
			}
			sprite.setPosition(Vector2f(x, y));
		}
	}

	void krok() {
		if (x % 3 == 0) {
			i++;
			if (i > 5) i = 0;
		}
		sprite.setPosition(Vector2f(x, y));
		if (kierunek != kierunekUprzedni) {
			sprite.scale(Vector2f(-1, 1));
			kierunekUprzedni = kierunek;
		}
		sprite.setTextureRect(IntRect(0 + 30 * i, 80, 30, 24));
	}

	void skok() {
		lata = true;
		do_gory = true;
	}
};