#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Tlo {
private:
	int y = 0;
	string sciezkaTekstury = "images/las.PNG";
	Texture tekstura;
public:
	Sprite sprite;
	int x = 0;
	int granica = -9590;

	void dodajSciezke(string sciezka) {
		sciezkaTekstury = "images/" + sciezka + ".PNG";
	}

	void rysuj() {
		if (!tekstura.loadFromFile(sciezkaTekstury)) {
			cout << "Nie za³adowano tekstury tla" << endl;
		}
		else {
			sprite.setTexture(tekstura);
			sprite.setPosition(Vector2f(x, y));
		}
	}

	void aktualizuj() {
		sprite.setPosition(Vector2f(x, y));
	}

};