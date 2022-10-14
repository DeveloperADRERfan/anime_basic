#pragma once

#include "player.h"
#include "enemy.h"
#include "bullet.h"

class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	// 初期化
	void init();
	// 終了処理
	void end();
	// 発射開始
	void start();
	// 毎フレームの処理
	void update();
	// 毎フレームの描画
	void draw();
	// 弾の生成
	void createEnemyShot(Vec2 pos);
private:
	static constexpr int kMobMax = 10;

private:

	// プレイヤーのグラフィックハンドル
	int m_hPlayerGraphic[Player::kGraphicDivNum];
	// ショットのグラフィックハンドル
	int m_hShotGraphic;
	// プレイヤー
	Player m_player;
	// 敵
	Enemy m_enemy;
	// 弾
	Bullet m_bullet[kMobMax];
};