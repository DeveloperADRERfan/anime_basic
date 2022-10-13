#include "DxLib.h"
#include "bullet.h"
#include "game.h"
#include "enemy.h"


namespace
{
	constexpr float kSpeed = 7.0f;
}

Bullet::Bullet()
{
	
}

Bullet::~Bullet()
{

}

// ������
void Bullet::init()
{
	m_pos.x = 0;
	m_pos.y = 0;
	m_vec.x = kSpeed;
	m_vec.y = 0.0f;

	m_handle = LoadGraph("GameGraphic/bullet.png");
}

// �I������
void Bullet::end()
{
	DeleteGraph(m_handle);
}

// �T�C�Y�擾
void Bullet::get()
{
	GetGraphSizeF(m_handle, &m_GraphSize.x, &m_GraphSize.y);
}

// ����
void Bullet::update()
{
	// �p�b�h(�������̓L�[�{�[�h)����̓��͂��擾����
	int padstate = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	// �V���b�g��������
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		m_pos.x += m_vec.x;
	}
	
	if (m_pos.x + m_GraphSize.x >= Game::kScreenWidth)
	{
		
	}
}

// �`��
void Bullet::draw()
{
	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
}