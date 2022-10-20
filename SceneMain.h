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

	// ������
	void init();
	// �I������
	void end();
	// ���t���[���̏���
	virtual SceneBase* update();
	// ���t���[���̕`��
	void draw();


	// enemy��player�̓����蔻��
	bool Col_Enemy();

private:

	// �v���C���[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic[Player::kGraphicDivNum];
	// �V���b�g�̃O���t�B�b�N�n���h��
	int m_hShotGraphic;

	// �e
	Bullet m_bullet;
	// �v���C���[
	Player m_player;
	// �G
	Enemy m_enemy;
};