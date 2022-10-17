#include "DxLib.h"
#include <cassert>
#include "enemy.h"
#include "game.h"

namespace
{
	constexpr float kSpeed = 5.0f;
}

Enemy::Enemy()
{
	
}

Enemy::~Enemy()
{

}

void Enemy::init()
{
	m_pos.x = 0;
	m_pos.y = 0;
	m_vec.x = 0.0f;
	m_vec.y = kSpeed;

	m_handle = LoadGraph("GameGraphic/enemy.png");
	GetGraphSizeF(m_handle, &m_GraphSize.x, &m_GraphSize.y);
}

void Enemy::end() {

	DeleteGraph(m_handle);
}

void Enemy::update()
{
	m_shotPos.y = m_pos.y + m_GraphSize.y / 2;
	m_shotPos.x = m_pos.x + m_GraphSize.x;



	m_pos.y += m_vec.y;

	if (m_pos.y + m_GraphSize.y > Game::kScreenHeight)
	{
		m_vec.y *= -1;
	}
	if (m_pos.y <= 0)
	{
		m_vec.y *= -1;
		m_pos.y = 0;
	}

}

void Enemy::draw()
{
	DrawGraphF(m_pos.x, m_pos.y,m_handle, true);
}




