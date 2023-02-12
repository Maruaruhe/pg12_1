#include "Player.h"
#include <Novice.h>
void Player::Init() {
	mPosition = { 640,500 };
	mVelocity = { 5,5 };
	mRadius = 30;
	bullet.Init();
}

void Player::Update() {
	if (Novice::CheckHitKey(DIK_W)) {
		mPosition.y -= mVelocity.y;
	}
	if (Novice::CheckHitKey(DIK_S)) {
		mPosition.y += mVelocity.y;
	}
	if (Novice::CheckHitKey(DIK_A)) {
		mPosition.x -= mVelocity.x;
	}
	if (Novice::CheckHitKey(DIK_D)) {
		mPosition.x += mVelocity.x;
	}
	if (Novice::CheckHitKey(DIK_SPACE) && bullet.mIsShot == false) {
		bullet.mPosition.x = mPosition.x;
		bullet.mPosition.y = mPosition.y;
		bullet.mIsShot = true;
	}
	bullet.Update();
}

void Player::Draw() {
	Novice::DrawEllipse(mPosition.x, mPosition.y, mRadius, mRadius, 0, BLUE, kFillModeSolid);
	bullet.Draw();
}