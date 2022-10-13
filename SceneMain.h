#pragma once

#include "player.h"
#include "enemy.h"

class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	// ������
	void init();
	// �I������
	void end();

	// ���t���[���̕`��
	void draw();
	// ���t���[���̏���
	void update();
	
private:

	// �v���C���[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic[Player::kGraphicDivNum];
	// �v���C���[
	Player m_player;
	// �G
	Enemy m_enemy;
};