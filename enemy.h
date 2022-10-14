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
	void get();
	// ����
	void update();
	// �`��
	void draw();

	Vec2 getPos() { return m_pos; }

private:
	// �O���t�B�b�N�̃T�C�Y�擾
	Vec2 m_GraphSize;
	// �G�̃n���h��
	int m_handle;

	// �\���ʒu
	Vec2 m_pos;
	// �ړ���
	Vec2 m_vec;
};
