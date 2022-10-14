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
	// ���ˊJ�n
	void start();
	// ���t���[���̏���
	void update();
	// ���t���[���̕`��
	void draw();
	// �e�̐���
	void createEnemyShot(Vec2 pos);
private:
	static constexpr int kMobMax = 10;

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
	Bullet m_bullet[kMobMax];
};