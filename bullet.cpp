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

// 初期化
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

// 終了処理
void Bullet::end()
{
	DeleteGraph(m_handle);
}

// サイズ取得
void Bullet::getGraphSize()
{
	GetGraphSizeF(m_handle, &m_size.x, &m_size.y);
}

// 発射開始
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

// 処理
void Bullet::update()
{
	// ショットを撃つ処理
	m_pos.x += m_vec.x;

	if (getRight() > Game::kScreenWidth)
	{
		m_isExist = false;
	}
}

// 描画
void Bullet::draw()
{
	if (!m_isExist) return;
	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
}
