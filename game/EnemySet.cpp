#include "enemySet.h"

EnemySet::EnemySet() {
	
}

void EnemySet::createEnemys(int level) {
	list<Enemy>::iterator iter;
	for (iter = hoard.begin(); iter != hoard.end();)
	{
		iter = hoard.erase(iter);
	}

	float x = 20;
	float y = 30;
	
	for (int i = 0; i < 10; i++) {
		Enemy badguy(enemyTexture, 4 * i * x, y, level);
		hoard.push_back(badguy);
	}
}

void EnemySet::moveEnemy() {
	list<Enemy>::iterator iter;
	for (iter = hoard.begin(); iter != hoard.end(); iter++)
	{
		iter->moveEnemy();
	}
}

void EnemySet::draw(RenderWindow& window) {
	list<Enemy>::iterator iter;
	for (iter = hoard.begin(); iter != hoard.end(); iter++)
	{
		iter->draw(window);
	}
}

int EnemySet::getSize() {
	return hoard.size();
}

Sprite EnemySet::getSprite(int i) {
	list<Enemy>::iterator iter = hoard.begin();
	advance(iter, i);
	return iter->getEnemy();
}

void EnemySet::deleteEnemy(int i) {
	list<Enemy>::iterator iter = hoard.begin();
	advance(iter, i);
	iter = hoard.erase(iter);
}

bool EnemySet::toLow(userMenu &menu) {
	bool low = false;
	list<Enemy>::iterator iter = hoard.begin();
	Sprite temp = iter->getEnemy();
	Vector2f pos = temp.getPosition();
	if (pos.y > 500) {
		low = true;
		menu.loseLife();
	}
	return low;
}