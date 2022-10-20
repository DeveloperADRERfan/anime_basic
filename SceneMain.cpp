#include "DxLib.h"
#include <cassert>
#include "SceneMain.h"
#include "game.h"

namespace
{
	// グラフィックファイル名
	const char* const kPlayerGraphFilename = "GameGraphic/obake.png";
	
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
}

// 毎フレームの処理
void SceneMain::update()
{
	m_player.update();
	m_enemy.update();

	m_enemy.setPlayer(m_player);

	Col_Enemy();
	//Col_Shot();

	if (Col_Enemy() == true)
	{
	
		DxLib_End();				// ＤＸライブラリ使用の終了処理
	}

	
}

// 毎フレームの描画
void SceneMain::draw()
{
	m_player.draw();
	m_enemy.draw();
}

// playerとbulletの当たり判定
//bool SceneMain::Col_Shot()
//{
//	if (m_player.getLeft() > m_bullet.getRight()) return false;
//	if (m_player.getRight() < m_bullet.getLeft()) return false;
//	if (m_player.getTop() > m_bullet.getBottom()) return false;
//	if (m_player.getBottom() > m_player.getTop()) return false;
//
//	return true;
//}

// enemyとplayerの当たり判定
bool SceneMain::Col_Enemy()
{
	if (m_player.getLeft() > m_enemy.getRight()) return false;
	if (m_player.getRight() < m_enemy.getLeft()) return false;
	if (m_player.getTop() > m_enemy.getBottom()) return false;
	if (m_player.getBottom() < m_enemy.getTop()) return false;

	return true;
}
