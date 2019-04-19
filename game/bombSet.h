#pragma once
#include "Weapon.h"
#include "enemySet.h"
#include "userMenu.h"
#include "Ship.h"
#include <cstdlib>
#include <list>

class BombSet
{
private:
	list<Bomb> bombs;
	Texture bombTexture;
public:
	BombSet();
	void createBomb(Vector2f shipPos);
	void move(float x, float y);
	void draw(RenderWindow& window);
	void outOfBounds();
	void randBomb(EnemySet &es, int &timer);
	bool hit(Ship& ship, userMenu &menu);
};