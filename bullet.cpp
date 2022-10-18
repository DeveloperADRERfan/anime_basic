#include "DxLib.h"
#include "bullet.h"
#include "game.h"
#include "enemy.h"


namespace
{
	constexpr float kSpeed = 5.0f;
	constexpr int kBulletInterval = 15;

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
	m_pos.y = 0;
	m_pos.x = 0;
	m_vec.x = kSpeed;
	m_vec.y = 0.0f;

	graphSize = 0.0f;

	m_waitBullet = kBulletInterval;
	m_isExist = false;

	m_handle = LoadGraph("GameGraphic/bullet.png");
}

// �I������
void Bullet::end()
{
	DeleteGraph(m_handle);
}

// �T�C�Y�擾
void Bullet::getGraphSize()
{
	GetGraphSizeF(m_handle, &m_size.x, &m_size.y);
}

// ���ˊJ�n
void Bullet::start(Vec2 pos) 
{
	m_waitBullet--;
	
	if (m_waitBullet != 0) {

		return;

	}

	m_waitBullet = kBulletInterval;

	m_isExist = true;

	m_pos = pos;
}

// ����
void Bullet::update()
{
	// �V���b�g��������
	m_pos.x += m_vec.x;

	if (getRight() > Game::kScreenWidth)
	{
		m_isExist = false;
	}
}

// �`��
void Bullet::draw()
{
	if (!m_isExist) return;
	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
}
