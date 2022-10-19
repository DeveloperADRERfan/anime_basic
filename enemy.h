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

	// ���̎擾
	Vec2 getPos() { return m_pos; }

	// �����蔻������p�Ɏl�����̍��W���擾����@
	float getLeft()	const { return m_pos.x; }
	float getRight()	const { return m_pos.x + m_GraphSize.x; }
	float getTop()	const { return m_pos.y; }
	float getBottom() const { return m_pos.y + m_GraphSize.y; }

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
