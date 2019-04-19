#pragma once
#include "Weapon.h"
#include "Ship.h"
#include <list>
#include "EnemySet.h"
#include "userMenu.h"

class MissileSet
{
private:
	list<Missile> bullets;
	Texture missileTexture;
public:
	MissileSet();
	void createMissile(Vector2f shipPos);
	void move(float x, float y);
	void draw(RenderWindow& window);
	void outOfBounds();
	void hit(EnemySet& enemies, userMenu &menu);
};