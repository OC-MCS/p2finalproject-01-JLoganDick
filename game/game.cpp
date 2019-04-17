//=========================================================
// This is just the starting point for your final project.
// You are expected to modify and add classes/files as needed.
// The code below is the original code for our first graphics
// project (moving the little green ship). 
//========================================================
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "userMenu.h"
#include "Ship.h"
#include "Weapon.h"
using namespace sf;

//============================================================
// YOUR HEADER WITH YOUR NAME GOES HERE. PLEASE DO NOT FORGET THIS
//============================================================

// note: a Sprite represents an image on screen. A sprite knows and remembers its own position
// ship.move(offsetX, offsetY) adds offsetX, offsetY to 
// the current position of the ship. 
// x is horizontal, y is vertical. 
// 0,0 is in the UPPER LEFT of the screen, y increases DOWN the screen


void moveEnemy(Sprite& enemy, bool& enemyDirection) {
	const float DISTANCE = 9.0f;
	if (enemy.getPosition().x < 0) {
		enemyDirection = true;
	}
	if (enemy.getPosition().x > 750) {
		enemyDirection = false;
	}
	if (enemyDirection) {
		enemy.move(DISTANCE, 0);
	}
	if (!enemyDirection) {
		enemy.move(-DISTANCE, 0);
	}
}

int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	bool enemyDirection = true;
	bool start = false;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	// load textures from file into memory. This doesn't display anything yet.
	// Notice we do this *before* going into animation loop.
	Texture shipTexture;
	if (!shipTexture.loadFromFile("ship.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture starsTexture;
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture missileTexture;
	if (!missileTexture.loadFromFile("missile.png"))
	{
		cout << "Unable to load missile texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture enemyTexture;
	if (!enemyTexture.loadFromFile("enemy.png"))
	{
		cout << "Unable to load enemy texture!" << endl;
		exit(EXIT_FAILURE);
	}

	// A sprite is a thing we can draw and manipulate on the screen.
	// We have to give it a "texture" to specify what it looks like

	Sprite background;
	background.setTexture(starsTexture);
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(1.5, 1.5);

	Sprite enemy;
	enemy.setTexture(enemyTexture);

	Ship ship(window, shipTexture);

	Missile missile(missileTexture);
	

	userMenu menu(WINDOW_WIDTH,WINDOW_HEIGHT);

	float enemyX = window.getSize().x / 2.0f;
	float enemyY = window.getSize().y / 5.0f;
	enemy.setPosition(enemyX, enemyY);

	bool isMissileInFlight = false;
	int hitcount = 0;

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;
		

		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			else {
				missile.shootWeapon(isMissileInFlight, ship.getShip(), event);
			}
		}

		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================

		// draw background first, so everything that's drawn later 
		// will appear on top of background
		window.draw(background);

		if (!start) {
			menu.draw(window);
			if (event.type == Event::MouseButtonReleased) {
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				start = menu.handelMouseUp(mousePos);
			}
			// check start click
			// draw start button

		}
		else {
			ship.moveShip();
			moveEnemy(enemy, enemyDirection);

			// draw the ship on top of background 
			// (the ship from previous frame was erased when we drew background)
			//ship.draw(window);
			//window.draw(ship.getShip());
			ship.draw(window);
			window.draw(enemy);

			if (isMissileInFlight)
			{
				missile.draw(window);
				missile.move(0, -5.0f);
				Vector2f misPos = missile.getPosition();
				if (misPos.y < 0) {
					isMissileInFlight = false;
				}
				// ***code goes here to handle a missile in flight
				// don't forget to turn the flag off when the missile goes off screen!

			}

			FloatRect missileBounds = missile.getGlobalBounds();
			FloatRect enemyBounds = enemy.getGlobalBounds();
			if (missileBounds.intersects(enemyBounds)) {
				hitcount++;
				cout << "The enemy has been hit!" << endl;
				missile.setPosition(-1, -1);
			}
		}
		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
		window.display();

		// At this point the frame we have built is now visible on screen.
		// Now control will go back to the top of the animation loop
		// to build the next frame. Since we begin by drawing the
		// background, each frame is rebuilt from scratch.

	} // end body of animation loop

	cout << "You hit the enemy " << hitcount << " times!!" << endl;

	return 0;
}

