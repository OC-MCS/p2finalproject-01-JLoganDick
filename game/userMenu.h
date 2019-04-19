#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class userMenu {
private:
	RectangleShape button;
	int score;
	int lives;
public:
	userMenu(int windowX, int windowY);
	RectangleShape getButton();
	bool handelMouseUp(Vector2f mousePos);
	void draw(RenderWindow& win, int i);
	void addScore();
	void loseLife();
	void drawGame(RenderWindow& win);
	int getScore();
	int getLives();
	void setScore(int s);


};
