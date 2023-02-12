#include "Bullet.h"
#include <Novice.h>

void Bullet::Init() {
	mPosition = { 0,0 };
	mVelocity = { 0,10 };
	mRadius = 25;
	mIsShot = false;
}

void Bullet::Update() {
	if (mIsShot == true) {
		mPosition.y -= mVelocity.y;
	}
	if (mPosition.y <= -mRadius) {
		mIsShot = false;
	}
}

void Bullet::Draw() {
	if (mIsShot == true) {
		Novice::DrawEllipse(mPosition.x, mPosition.y, mRadius, mRadius, 0, WHITE, kFillModeSolid);
	}
}