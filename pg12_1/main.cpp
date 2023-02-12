#include <Novice.h>
#include "main.h"

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	for (int i = 0; i < 2; i++) {
		enemy[i].mPosition = { 640.0f + 100 * i,260.0f + 100 * i };
		enemy[i].mVelocity = { 10,0 };
		enemy[i].mRadius = 15;
		enemy[i].mIsAlive = true;
	}
	player.Init();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		for (int i = 0; i < 2; i++) {
			enemy[i].Update();
			float disAx = player.bullet.mPosition.x - enemy[0].mPosition.x;
			float disAy = player.bullet.mPosition.y - enemy[0].mPosition.y;
			float disBx = player.bullet.mPosition.x - enemy[1].mPosition.x;
			float disBy = player.bullet.mPosition.y - enemy[1].mPosition.y;

			if (disAx * disAx + disAy * disAy <= player.bullet.mRadius * enemy[0].mRadius) {
				Enemy::mIsAlive = false;
			}
			if (disBx * disBx + disBy * disBy <= player.bullet.mRadius * enemy[1].mRadius) {
				Enemy::mIsAlive = false;
			}
		}
		player.Update();
		if (keys[DIK_R]) {
			Enemy::mIsAlive = true;
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		for (int i = 0; i < 2; i++) {
			enemy[i].Draw();
		}
		player.Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
