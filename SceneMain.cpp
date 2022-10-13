#include "DxLib.h"
#include <cassert>
#include "SceneMain.h"

namespace
{
	// �O���t�B�b�N�t�@�C����
	const char* const kPlayerGraphFilename = "GameGraphic/obake.png";

	const char* const kEnemyGraphFilename = "GameGraphic/enemy.png";
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
	m_enemy.get();
}

// �I������
void SceneMain::end()
{
	for (auto& handle : m_hPlayerGraphic)
	{
		DeleteGraph(handle);
	}

	m_enemy.end();

}

// ���t���[���̏���
void SceneMain::update()
{
	m_player.update();
	m_enemy.update();
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%f", m_enemy.getPos().y , true);
}

// ���t���[���̕`��
void SceneMain::draw()
{
	m_player.draw();
	m_enemy.draw();
}