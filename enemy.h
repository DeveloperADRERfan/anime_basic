#pragma once

#include "Vec2.h"

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


	// �ʒu�̎擾
	Vec2 getPos() const { return m_pos; }

private:
	// �O���t�B�b�N�̃T�C�Y�擾
	Vec2 m_GraphSize;
	// �G�̃n���h��
	int m_handle;
	// �\���ʒu
	Vec2 m_pos;
	// �ړ�
	Vec2 m_vec;
};
