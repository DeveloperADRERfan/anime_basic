#pragma once

#include "Vec2.h"

class Player
{
public:
	// �萔��`

	// �O���t�B�b�N�f�[�^������
	static constexpr int kGraphicDivX = 3;
	static constexpr int kGraphicDivY = 4;
	static constexpr int kGraphicDivNum = kGraphicDivX * kGraphicDivY;
	// �O���t�B�b�N�f�[�^�T�C�Y
	static constexpr int kGraphicSizeX = 28;
	static constexpr int kGraphicSizeY = 28;

public:
	Player();
	virtual ~Player();

	// �O���t�B�b�N�f�[�^�ݒ�
	void setHandle(int index, int handle) { m_handle[index] = handle; }

	// �v���C���[�̏�����
	void init();
	// �I������
	void end();
	// ����
	void update();
	// �`��
	void draw();

	//���S�ݒ�
	void setDead(bool isDead) { m_isDead = isDead; }

	// ���̎擾
	Vec2 getPos() const { return m_pos; }

	// �����蔻������p�Ɏl�����̍��W���擾����@
	float getLeft()	const { return m_pos.x; }
	float getRight()	const { return m_pos.x + m_size.x; }
	float getTop()	const { return m_pos.y; }
	float getBottom() const { return m_pos.y + m_size.y; }

private:
	int m_handle[kGraphicDivNum];	// ��������12��

	// ���S�ݒ�
	bool m_isDead;

	// �\���ʒu
	Vec2 m_pos;
	// �ړ�
	Vec2 m_vec;
	// �O���t�B�b�N�̃T�C�Y�擾
	Vec2 m_size;

	// �L�����N�^�[�̃A�j���[�V����
	int m_animeNo;	
	// �\������ԍ�
	int m_animeFrame;
	// �i�s����
	int m_dirNo;	
};