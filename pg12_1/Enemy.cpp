#include "Enemy.h"
#include <Novice.h>

void Enemy::Init() {

}

void Enemy::Update() {
	if (mIsAlive == true) {
		mPosition.x += mVelocity.x;
		if (mPosition.x >= 1280 - mRadius) {
			mVelocity.x *= -1;
		}
		if (mPosition.x <= mRadius) {
			mVelocity.x *= -1;
		}
	}
}

void Enemy::Draw() {
	if (mIsAlive == true) {
		Novice::DrawEllipse(mPosition.x, mPosition.y, mRadius, mRadius, 0, RED, kFillModeSolid);
	}
}