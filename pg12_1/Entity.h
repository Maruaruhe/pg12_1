#pragma once
#include "Vec2.h"
class Entity
{
public:
	Vec2 mPosition;
	Vec2 mVelocity;
	int mRadius;

	virtual void Init();
	virtual void Update();
	virtual void Draw();
};

