#pragma once

#include "player.h"
#include "enemy.h"
#include "bullet.h"

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
	// �V���b�g�̃O���t�B�b�N�n���h��
	int m_hShotGraphic;
	// �v���C���[
	Player m_player;
	// �G
	Enemy m_enemy;
	// �e
	Bullet m_bullet;

	// �e�̐���
	bool createShotNormal(Vec2 pos);
};