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
	// 毎フレームの描画
	void draw();
	// 毎フレームの処理
	void update();

	
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
	Bullet m_bullet;

	// 弾の生成
	bool createShotNormal(Vec2 pos);
};