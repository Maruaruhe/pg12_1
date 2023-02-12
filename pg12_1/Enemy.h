#pragma once
#include "Entity.h"
class Enemy:public Entity
{
public:
	static bool mIsAlive;

	void Init();
	void Update();
	void Draw();
};

