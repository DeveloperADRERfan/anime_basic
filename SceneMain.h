#pragma once

#include "player.h"
#include "enemy.h"

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
	// プレイヤー
	Player m_player;
	// 敵
	Enemy m_enemy;
};