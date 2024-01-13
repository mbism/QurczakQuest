#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Wiewiora {
private:

	Texture tekstura;
	string sciezkaTekstury = "images/wiewiora.png";
	int podloga = 550 - 40;
	int y = podloga;
	int x = 1080;
public:
	Sprite sprite;
	void rysuj() {
		if (!tekstura.loadFromFile(sciezkaTekstury))
		{
			cout << "Nie zaladowano tekstury wiewiorki" << endl;
		}
		else {
			sprite.setTexture(tekstura);
			int XIndex = 0;
			int YIndex = 0;
			sprite.setTextureRect(IntRect(XIndex * 52, YIndex * 52, 52, 52));
			sprite.scale(Vector2f(2, 2));
			sprite.setPosition(Vector2f(1100, 545));
		}
	}
};