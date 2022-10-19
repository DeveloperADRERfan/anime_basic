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
	void getGraphSize();
	// ���ˊJ�n
	void start(Vec2 pos);
	// ����
	void update();
	// �`��
	void draw();

	// ���݂��邩
	bool isExist() const { return m_isExist; }

	// ���̎擾
	Vec2 getPos() const { return m_pos; }

	// �����蔻������p�Ɏl�����̍��W���擾����@
	float getLeft()	const { return m_pos.x; }
	float getRight()	const { return m_pos.x + m_size.x; }
	float getTop()	const { return m_pos.y; }
	float getBottom() const { return m_pos.y + m_size.y; }

private:
	// �\���ʒu
	Vec2 m_pos;
	// �ړ���
	Vec2 m_vec;
	// �O���t�B�b�N�̃T�C�Y�擾
	Vec2 m_size;

	float graphSize;

	// �e�̃n���h��
	int m_handle;

	// �e�̊Ԋu
	int m_waitBullet;

	// ���݂��邩
	bool m_isExist;
};
