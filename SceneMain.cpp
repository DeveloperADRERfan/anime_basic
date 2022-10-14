#include "DxLib.h"
#include <cassert>
#include "SceneMain.h"
#include "game.h"

namespace
{
	// グラフィックファイル名
	const char* const kPlayerGraphFilename = "GameGraphic/obake.png";
	constexpr float kInterval = 
}

SceneMain::SceneMain()
{
	for (auto& handle : m_hPlayerGraphic)
	{
		handle = -1;
	}
}

SceneMain::~SceneMain()
{

}

// 初期化
void SceneMain::init()
{
	LoadDivGraph(kPlayerGraphFilename, Player::kGraphicDivNum,
		Player:: kGraphicDivX, Player::kGraphicDivY,
		Player::kGraphicSizeX, Player::kGraphicSizeY, m_hPlayerGraphic);

	for (int i = 0; i < Player::kGraphicDivNum; i++)
	{
		m_player.setHandle(i, m_hPlayerGraphic[i]);
	}
	m_player.init();

	LoadGraph("GameGraphic/enemy.png");

	m_enemy.init();
	for (auto& Bullet : m_bullet)
	{
		Bullet.init();
	}
	m_enemy.get();
}

// 終了処理
void SceneMain::end()
{
	for (auto& handle : m_hPlayerGraphic)
	{
		DeleteGraph(handle);
	}

	m_player.end();
	m_enemy.end();
	for (auto& Bullet : m_bullet)
	{
		Bullet.end();
	}
	
}

// 発射開始
void SceneMain::start()
{
	
}

// 毎フレームの処理
void SceneMain::update()
{
	createEnemyShot(m_enemy.getPos());

	m_player.update();
	m_enemy.update();
	for (auto& Bullet : m_bullet)
	{
		Bullet.update();
	}
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "%f", m_enemy.getPos().y , true);
}

// 毎フレームの描画
void SceneMain::draw()
{
	m_player.draw();
	m_enemy.draw();
	for (auto& Bullet : m_bullet)
	{
		Bullet.draw();
	}
}

// 弾の生成
void SceneMain::createEnemyShot(Vec2 pos)
{
	for (auto& Bullet : m_bullet)
	{
		if (Bullet.isExist()) continue;
		Bullet.start(pos);
		return;
	}
}