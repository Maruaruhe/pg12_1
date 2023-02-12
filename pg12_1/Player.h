#pragma once
#include "Entity.h"
#include "Bullet.h"
class Player:public Entity
{
public:
	Bullet bullet;

	void Init();
	void Update();
	void Draw();
};

