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

// 初期化
void Bullet::init()
{
	m_pos.x = 0;
	m_pos.y = 0;
	m_vec.x = kSpeed;
	m_vec.y = 0.0f;

	m_handle = LoadGraph("GameGraphic/bullet.png");
}

// 終了処理
void Bullet::end()
{
	DeleteGraph(m_handle);
}

// サイズ取得
void Bullet::get()
{
	GetGraphSizeF(m_handle, &m_GraphSize.x, &m_GraphSize.y);
}

// 処理
void Bullet::update()
{
	// パッド(もしくはキーボード)からの入力を取得する
	int padstate = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	// ショットを撃つ処理
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		m_pos.x += m_vec.x;
	}
	
	if (m_pos.x + m_GraphSize.x >= Game::kScreenWidth)
	{
		
	}
}

// 描画
void Bullet::draw()
{
	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
}