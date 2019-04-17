#include "userMenu.h"

void die(string die);

userMenu::userMenu(int windowX, int windowY) {
	Vector2f size(windowX / 3.0f , windowY / 4.0f);
	Vector2f pos((windowX - size.x) / 2.0f, (windowY - size.y) / 2.0f);
	button.setPosition(pos);
	button.setSize(size);
	button.setFillColor(Color::Green);
	kills = 0;
	lives = 3;
 }

RectangleShape userMenu::getButton() {
	return button;
}

bool userMenu::handelMouseUp(Vector2f mousePos) {
	bool clicked = false;
	if (button.getGlobalBounds().contains(mousePos)) {
		clicked = true;
	}
	return clicked;
}

void userMenu::draw(RenderWindow& win) {
	win.draw(button);
	Font font;
	if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		die("couldn't load font");

	// Color Title
	Text title("START", font, 50);
	title.setFillColor(Color::Black);
	title.setPosition(button.getPosition().x + (button.getSize().x - title.getLocalBounds().width) / 2, button.getPosition().y + button.getSize().y / 2 - title.getLocalBounds().height);
	win.draw(title);

}

// Function that ends program if there is an error
void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}