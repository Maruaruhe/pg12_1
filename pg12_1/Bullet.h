#pragma once
#include "Entity.h"
class Bullet:public Entity
{
public:
	bool mIsShot;

	void Init();
	void Update();
	void Draw();
};

