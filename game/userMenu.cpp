#include "userMenu.h"

void die(string die);

userMenu::userMenu(int windowX, int windowY) {
	Vector2f size(windowX / 3.0f , windowY / 4.0f);
	Vector2f pos((windowX - size.x) / 2.0f, (windowY - size.y) / 2.0f);
	button.setPosition(pos);
	button.setSize(size);
	button.setFillColor(Color::Green);
	score = 0;
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

void userMenu::draw(RenderWindow& win, int i) {
	Font font;
	if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		die("couldn't load font");

	if (i == 1 || i == 2) {
		win.draw(button);

		Text title("START", font, 50);
		title.setFillColor(Color::Black);
		title.setPosition(button.getPosition().x + (button.getSize().x - title.getLocalBounds().width) / 2, button.getPosition().y + button.getSize().y / 2 - title.getLocalBounds().height);
		win.draw(title);
		if (i == 2) {
			Text title2("LEVEL 2", font, 25);
			title2.setFillColor(Color::White);
			title2.setPosition(button.getPosition().x + (button.getSize().x - title.getLocalBounds().width) / 2, 20);
			win.draw(title2);
		}
	}
	else if (i == 3) {
		Text title2("YOU LOSE!", font, 50);
		title2.setFillColor(Color::White);
		title2.setPosition(button.getPosition().x + (button.getSize().x - title2.getLocalBounds().width) / 2, 20);
		win.draw(title2);
	}
	else if (i == 4) {
		Text title2("WINNER!!", font, 50);
		title2.setFillColor(Color::White);
		title2.setPosition(button.getPosition().x + (button.getSize().x - title2.getLocalBounds().width) / 2, 20);
		win.draw(title2);
	}

	if (i > 2) {
		win.draw(button);

		Text title("START", font, 50);
		title.setFillColor(Color::Black);
		title.setPosition(button.getPosition().x + (button.getSize().x - title.getLocalBounds().width) / 2, button.getPosition().y + button.getSize().y / 2 - title.getLocalBounds().height);
		win.draw(title);
	}

}

// Function that ends program if there is an error
void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}

void userMenu::addScore() {
	score++;
}

void userMenu::drawGame(RenderWindow& win) {
	Font font;
	if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		die("couldn't load font");

	// Color Title
	Text title("Score: ", font, 50);
	title.setFillColor(Color::White);
	title.setPosition(0, 0);
	win.draw(title);

	Text title1(to_string(score), font, 50);
	title1.setFillColor(Color::White);
	title1.setPosition(title.getLocalBounds().width, 0);
	win.draw(title1);

	Text title2("Lives: ", font, 50);
	title2.setFillColor(Color::White);
	title2.setPosition(600, 0);
	win.draw(title2);

	Text title3(to_string(lives), font, 50);
	title3.setFillColor(Color::White);
	title3.setPosition(600 + title2.getLocalBounds().width, 0);
	win.draw(title3);

}

int userMenu::getScore() {
	return score;
}

void userMenu::loseLife() {
	lives--;
}

int userMenu::getLives() {
	return lives;
}

void userMenu::setScore(int s) {
	score = s;
}

void userMenu::setLives(int l) {
	lives = l;
}