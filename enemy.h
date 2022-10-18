#pragma once

#include "Vec2.h"

#include "bullet.h"

class Enemy 
{
	
public:
	Enemy();
	virtual ~Enemy();

	// ������
	void init();

	void end();
	// �擾
	Vec2 getGraphSize() { return m_GraphSize; }
	// ����
	void update();
	// �`��
	void draw();
	// �e�̐���
	void createShot(Vec2 pos);

	Vec2 getPos() { return m_pos; }

private:
	static constexpr int kMobMax = 10;

private:
	// �O���t�B�b�N�̃T�C�Y�擾
	Vec2 m_GraphSize;
	// �G�̃n���h��
	int m_handle;

	// ���ˈʒu
	Vec2 m_shotPos;

	// �\���ʒu
	Vec2 m_pos;
	// �ړ���
	Vec2 m_vec;

	// �e
	Bullet m_bullet[kMobMax];
};
