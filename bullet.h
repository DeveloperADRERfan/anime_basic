#pragma once

#include "Vec2.h"



class Bullet
{
public:
	Bullet();
	virtual ~Bullet();

	// 初期化
	void init();
	// 終了処理
	void end();
	// サイズ取得
	void getGraphSize();
	// 発射開始
	void start(Vec2 pos);
	// 処理
	void update();
	// 描画
	void draw();

	// 存在するか
	bool isExist() const { return m_isExist; }

	// 情報の取得
	Vec2 getPos() const { return m_pos; }

	// 当たり判定実装用に四方向の座標を取得する　
	float getLeft()	const { return m_pos.x; }
	float getRight()	const { return m_pos.x + m_size.x; }
	float getTop()	const { return m_pos.y; }
	float getBottom() const { return m_pos.y + m_size.y; }

private:
	// 表示位置
	Vec2 m_pos;
	// 移動量
	Vec2 m_vec;
	// グラフィックのサイズ取得
	Vec2 m_size;

	float graphSize;

	// 弾のハンドル
	int m_handle;

	// 弾の間隔
	int m_waitBullet;

	// 存在するか
	bool m_isExist;
};
