#include "DxLib.h"
#include "SceneMain.h"

SceneMain::SceneMain()
{
	m_hPlayerGraphic = -1;
}
SceneMain::~SceneMain()
{

}

// ������
void SceneMain::init()
{
	m_hPlayerGraphic = LoadGraph("data/char.png");
	m_player.setHandle(m_hPlayerGraphic);
	m_player.init();
}

// �I������
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
}

// ���t���[���̏���
void SceneMain::update()
{
	m_player.update();
}

// ���t���[���̕`��
void SceneMain::draw()
{
	m_player.draw();
}