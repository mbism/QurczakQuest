#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Kura {
public:
	Sprite sprite;
	Texture tekstura;
	string sciezkaTekstury = "images/testowe.png";
	int x = 20;
	int y = 100;
	int i = 0; //o ile razy ma siê przesun¹æ prostok¹t wyciêty ze sprite'a
	string kierunek = "prawo";
	string kierunekUprzedni = "prawo";

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
		if (++i > 5) i = 0;
		sprite.setPosition(Vector2f(x, y));
		if (kierunek != kierunekUprzedni) {
			sprite.scale(Vector2f(-1, 1));
			kierunekUprzedni = kierunek;
		}
		sprite.setTextureRect(IntRect(0+30*i, 80, 30, 24));
		cout << "update kura" << endl;
	}
};