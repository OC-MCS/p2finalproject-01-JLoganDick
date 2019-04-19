#pragma once
#include "Enemy.h"
#include "userMenu.h"
#include <list>

class EnemySet
{
private:
	list<Enemy> hoard;
	Texture enemyTexture;
public:
	EnemySet();
	void createEnemys(int level);
	void moveEnemy();
	void draw(RenderWindow& window);
	int getSize();
	Sprite getSprite(int i);
	void deleteEnemy(int i);
	bool toLow(userMenu &menu);

};