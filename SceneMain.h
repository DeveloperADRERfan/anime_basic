#pragma once

#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "SceneBase.h"

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();

	// 初期化
	void init();
	// 終了処理
	void end();
	// 毎フレームの処理
	virtual SceneBase* update();
	// 毎フレームの描画
	void draw();


	// enemyとplayerの当たり判定
	bool Col_Enemy();

private:

	// プレイヤーのグラフィックハンドル
	int m_hPlayerGraphic[Player::kGraphicDivNum];
	// ショットのグラフィックハンドル
	int m_hShotGraphic;

	// 弾
	Bullet m_bullet;
	// プレイヤー
	Player m_player;
	// 敵
	Enemy m_enemy;
};