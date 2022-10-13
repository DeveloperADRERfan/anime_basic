#pragma once

#include "Vec2.h"

class Bullet
{
public:
	Bullet();
	virtual ~Bullet();

	// ������
	void init();
	// �I������
	void end();
	// �T�C�Y�擾
	void get();
	// ����
	void update();
	// �`��
	void draw();


private:
	// �\���ʒu
	Vec2 m_pos;
	// �ړ���
	Vec2 m_vec;
	// �O���t�B�b�N�̃T�C�Y�擾
	Vec2 m_GraphSize;

	// �e�̃n���h��
	int m_handle;
	
};
