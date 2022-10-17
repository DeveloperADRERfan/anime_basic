#pragma once

#include "Vec2.h"

#include "enemy.h"

class Bullet
{
public:
	Bullet();
	virtual ~Bullet();

	// ������
	void init();
	// �ʒu�ݒ�
	void setPos();
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

	float getPosX() const { return m_pos.x; }
	float getPosY() const { return m_pos.y; }

	// �����蔻������p�Ɏl�����̍��W���擾����@
	float getLeft()	const { return m_pos.x; }
	float getRight()	const { return m_pos.x + static_cast<float>(m_size.x); }
	float getTop()	const { return m_pos.y; }
	float getBottom() const { return m_pos.y + static_cast<float>(m_size.y); }

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

	// �G
	Enemy m_enemy;

	// �e�̊Ԋu
	int m_waitBullet;

	// ���݂��邩
	bool m_isExist;
};
