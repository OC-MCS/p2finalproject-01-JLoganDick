//============================================================
// Logan Dick
// April 19th, 2019
// Programming Assignment #7
// Description: Space Invaders
// File: game.cpp
//        main game file. 
//        handels all animation rendering.
//============================================================
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "userMenu.h"
#include "Ship.h"
#include "Weapon.h"
#include "Enemy.h"
#include "enemySet.h"
#include "MissileSet.h"
#include "bombSet.h"
using namespace sf;

//============================================================
// YOUR HEADER WITH YOUR NAME GOES HERE. PLEASE DO NOT FORGET THIS
//============================================================

// note: a Sprite represents an image on screen. A sprite knows and remembers its own position
// ship.move(offsetX, offsetY) adds offsetX, offsetY to 
// the current position of the ship. 
// x is horizontal, y is vertical. 
// 0,0 is in the UPPER LEFT of the screen, y increases DOWN the screen

int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	
	int timer = 0;

	enum gamestate {
		START, LEVEL1,LEVEL2START, LEVEL2, WINNER, LOSER
	};
	gamestate game = START;

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

	Sprite background;
	background.setTexture(starsTexture);
	background.setScale(1.5, 1.5);// The texture file is 640x480, so scale it up a little to cover 800x600 window

	Enemy enemy();					    // Class holds the Sprite for the enemy
	EnemySet enemies;					// Class holds the linked list of Enemys
	Ship ship(window, shipTexture);		// Class holds the sprite for the Ship
	MissileSet missiles;				// Class holds the link list of Missiles
	BombSet bombs;						// 

	enemies.createEnemys(1);			// populates the linked list in EnemySet with Enemys

	userMenu menu(WINDOW_WIDTH,WINDOW_HEIGHT);

	//===========================================================
	// Everything from here to the end of the loop is where you put your
	// code to produce ONE frame of the animation. The next iteration of the loop will
	// render the next frame, and so on. All this happens ~ 60 times/second.
	//===========================================================

	while (window.isOpen())
	{
		Event event; // check all the window's events that were triggered since the last iteration of the loop
		

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) // "close requested" event: we close the window
				window.close();
			else {
				if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::Space)
					{
						Vector2f pos = ship.getPosition();
						missiles.createMissile(pos);
					}

				}
			}
		}

		window.draw(background); // draw background first, so everything that's drawn later will appear on top of background

		if (game == START) {
			menu.draw(window, 1);
			if (event.type == Event::MouseButtonReleased) {
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				if (menu.handelMouseUp(mousePos)) {
					game = LEVEL1;
				}
			}
		}
		else if (game == LEVEL1) {
			bombs.randBomb(enemies, timer);

			ship.moveShip();									
			enemies.moveEnemy();								
			missiles.move(0, -5.0f);								
			bombs.move(0, 3);									

			missiles.outOfBounds();									
			missiles.hit(enemies, menu, 1);							

			menu.drawGame(window);								
			ship.draw(window);										
			enemies.draw(window);									
			missiles.draw(window);								
			bombs.draw(window);									

			if (bombs.hit(ship, menu)|| enemies.toLow(menu)) {		
				enemies.createEnemys(1);						
				menu.setScore(0);									
				bombs.clear();										
			}
			if (menu.getScore() >= 10) {							
				game = LEVEL2START;									
				menu.setScore(0);									
				enemies.createEnemys(2);							
			}
			if (menu.getLives() <= 0) {								
				game = LOSER;										
			}

		}
		else if (game == LEVEL2START) {								
			menu.draw(window, 2);									
			if (event.type == Event::MouseButtonReleased) {			
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				if (menu.handelMouseUp(mousePos)) {					
					game = LEVEL2;									
				}
			}

		}
		else if (game == LEVEL2){
			ship.moveShip();									
			enemies.moveEnemy();								
			enemies.moveEnemy();								
			missiles.move(0, -4.0f);							
			bombs.move(0, 4);									

			bombs.randBomb(enemies, timer);						

			missiles.outOfBounds();									
			missiles.hit(enemies, menu, 2);							

			menu.drawGame(window);									
			ship.draw(window);										
			enemies.draw(window);									
			missiles.draw(window);									
			bombs.draw(window);										

			if (bombs.hit(ship, menu) || enemies.toLow(menu)) {		
				enemies.createEnemys(2);							
				menu.setScore(0);									//  sets score to 0 to reset level
			}
			if (menu.getScore() >= 10) {							// Gets score to see if you won
				game = WINNER;										// Sets game state to Loser
			}
			if (menu.getLives() <= 0) {								// Gets lives to see if you lost
				game = LOSER;										// Sets gamestate to Loser
			}
		}
		else if (game == WINNER) {									// If you win you go here.
			menu.draw(window, 4);									// Draws the winner page
			if (event.type == Event::MouseButtonReleased) {			// restarts the game if button is clicked (checks button)
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				if (menu.handelMouseUp(mousePos)) {					
					game = LEVEL1;									//Sets the gameState to level 1 to restart the game
					menu.setScore(0);								//Sets the score back to 0 to restart the game
					menu.setLives(3);								// Sets lives back to 3 to restart the game
				}
			}
		}
		else if (game == LOSER) {									// If you lose, go here.
			menu.draw(window, 3);									// draws the Loser page
			if (event.type == Event::MouseButtonReleased) {			// restarts the game if button is clicked (checks button)
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				if (menu.handelMouseUp(mousePos)) {					
					game = LEVEL1;									// Sets the gameState to level 1 to restart the game
					menu.setScore(0);								// Sets the score back to 0 to restart the game
					menu.setLives(3);								// Sets lives back to 3 to restart the game
				}
			}
		}

		window.display();											//end the current frame; this makes everything that we have already "drawn" actually show up on the screen
	}																// end body of animation loop

	return 0;
}

