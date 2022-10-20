#include "DxLib.h"
#include <cassert>
#include "SceneMain.h"
#include "game.h"

namespace
{
	// �O���t�B�b�N�t�@�C����
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

// ������
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

// �I������
void SceneMain::end()
{
	for (auto& handle : m_hPlayerGraphic)
	{
		DeleteGraph(handle);
	}

	m_player.end();
	m_enemy.end();	
}

// ���t���[���̏���
void SceneMain::update()
{
	m_player.update();
	m_enemy.update();

	m_enemy.setPlayer(m_player);

	Col_Enemy();
	//Col_Shot();

	if (Col_Enemy() == true)
	{
	
		DxLib_End();				// �c�w���C�u�����g�p�̏I������
	}

	
}

// ���t���[���̕`��
void SceneMain::draw()
{
	m_player.draw();
	m_enemy.draw();
}

// player��bullet�̓����蔻��
//bool SceneMain::Col_Shot()
//{
//	if (m_player.getLeft() > m_bullet.getRight()) return false;
//	if (m_player.getRight() < m_bullet.getLeft()) return false;
//	if (m_player.getTop() > m_bullet.getBottom()) return false;
//	if (m_player.getBottom() > m_player.getTop()) return false;
//
//	return true;
//}

// enemy��player�̓����蔻��
bool SceneMain::Col_Enemy()
{
	if (m_player.getLeft() > m_enemy.getRight()) return false;
	if (m_player.getRight() < m_enemy.getLeft()) return false;
	if (m_player.getTop() > m_enemy.getBottom()) return false;
	if (m_player.getBottom() < m_enemy.getTop()) return false;

	return true;
}
