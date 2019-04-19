#include "MissileSet.h"


MissileSet::MissileSet() {

}

void MissileSet::createMissile(Vector2f shipPos) {
	
	Missile missile(missileTexture, shipPos);
	bullets.push_back(missile);

}

void MissileSet::move(float x, float y) {
	list<Missile>::iterator iter;
	for (iter = bullets.begin(); iter != bullets.end(); iter++)
	{
		iter->move(x, y);
	}
}


void MissileSet::draw(RenderWindow& window) {
	list<Missile>::iterator iter;
	for (iter = bullets.begin(); iter != bullets.end(); iter++)
	{
		iter->draw(window);
	}
}

void MissileSet::outOfBounds() {
	list<Missile>::iterator iter;
	for (iter = bullets.begin(); iter != bullets.end();)
	{
		bool out = false;
		Vector2f vec = iter->getPosition();
		if (vec.y < 0) {
			out = true;
			iter = bullets.erase(iter);
		}
		if (!out) {
			iter++;
		}
	}
}

void MissileSet::hit(EnemySet &enemies, userMenu &menu, int i) {
	int index;
	list<Missile>::iterator iter;
	for (iter = bullets.begin(); iter != bullets.end(); ){
		bool hit = false;
		for (int k = 0; k < enemies.getSize() && !hit; k++){
			if ((iter)->getSprite().getGlobalBounds().intersects(enemies.getSprite(k).getGlobalBounds())){
				iter = bullets.erase(iter);
				hit = true;
				menu.addScore();
				if (enemies.getSize() > 1) {
					enemies.deleteEnemy(k);
				}
				else {
					enemies.createEnemys(i);
					enemies.deleteEnemy(k);
				}
			}
		}
		if (!hit){
			iter++;
		}
	}
}
