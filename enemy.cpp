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

	m_isShotHit = false;

	m_handle = LoadGraph("GameGraphic/enemy.png");
	GetGraphSizeF(m_handle, &m_GraphSize.x, &m_GraphSize.y);

	for (auto& Bullet : m_bullet)
	{
		Bullet.init();
	}
}

void Enemy::end() {

	for (auto& Bullet : m_bullet)
	{
		Bullet.end();
	}

	DeleteGraph(m_handle);
}

void Enemy::update()
{
	createShot(m_shotPos);

	for (auto& Bullet : m_bullet)
	{
		Bullet.update();
	}

	for (int i = 0;i < kMobMax;i++)
	{
		m_isShotHit = Col_Shot(i);
		if (m_isShotHit)		break;
	}

	if (m_isShotHit) 
	{
		m_isShotHit = false;
		DxLib_End();

	}

	m_shotPos.y = m_pos.y + m_GraphSize.y / 2;
	m_shotPos.x = m_pos.x + m_GraphSize.x;


	// ’e”­ŽË
	m_pos += m_vec;

	if (m_pos.y + m_GraphSize.y > Game::kScreenHeight)
	{
		m_vec *= -1;
	}
	if (m_pos.y < 0)
	{
		m_vec *= -1;
	}

	
}

void Enemy::draw()
{
	for (auto& Bullet : m_bullet)
	{
		Bullet.draw();
	}

	DrawGraphF(m_pos.x, m_pos.y,m_handle, true);
}

// ’e‚Ì¶¬
void Enemy::createShot(Vec2 pos)
{
	for (auto& Bullet : m_bullet)
	{
		if (Bullet.isExist()) continue;
		Bullet.start(pos);
		return;
	}
}

bool Enemy::Col_Shot(int i) {

	//DrawFormatString(0, 0, GetColor(255, 255, 255), "%f", m_bullet[1].getLeft(), true);

	if (m_player.getLeft() > m_bullet[i].getRight()) return false;
	if (m_player.getRight() < m_bullet[i].getLeft()) return false;
	if (m_player.getTop() > m_bullet[i].getBottom()) return false;
	if (m_player.getBottom() < m_bullet[i].getTop()) return false;

	return true;
}


