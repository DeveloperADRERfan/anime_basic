#pragma once

#include "Vec2.h"

#include "bullet.h"

class Enemy 
{
	
public:
	Enemy();
	virtual ~Enemy();

	// 初期化
	void init();

	void end();
	// 取得
	Vec2 getGraphSize() { return m_GraphSize; }
	// 処理
	void update();
	// 描画
	void draw();
	// 弾の生成
	void createShot(Vec2 pos);

	// 情報の取得
	Vec2 getPos() { return m_pos; }

	// 当たり判定実装用に四方向の座標を取得する　
	float getLeft()	const { return m_pos.x; }
	float getRight()	const { return m_pos.x + m_GraphSize.x; }
	float getTop()	const { return m_pos.y; }
	float getBottom() const { return m_pos.y + m_GraphSize.y; }

private:
	static constexpr int kMobMax = 10;

private:
	// グラフィックのサイズ取得
	Vec2 m_GraphSize;
	// 敵のハンドル
	int m_handle;

	// 発射位置
	Vec2 m_shotPos;

	// 表示位置
	Vec2 m_pos;
	// 移動量
	Vec2 m_vec;

	// 弾
	Bullet m_bullet[kMobMax];
};
