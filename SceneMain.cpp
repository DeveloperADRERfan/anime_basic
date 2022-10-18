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
}

// ���t���[���̕`��
void SceneMain::draw()
{
	m_player.draw();
	m_enemy.draw();
}

// �����蔻��
bool SceneMain::Col_shot()
{
	m_player.getPos();

	m_bullet.getLeft();
	m_bullet.getRight();
	m_bullet.getTop();
	m_bullet.getBottom();


	m_player.getLeft();
	m_player.getRight();
	m_player.getTop();
	m_player.getBottom();

	if (m_player.getLeft() > m_bullet.getRight()) 
	//{

	//}
	//if (m_player.getRight() > )
	//{

	//}
	//if (m_player.getTop() > )
	//{

	//}
	//if (m_player.getBottom() > )
	//{

	//}

	return true;
}
