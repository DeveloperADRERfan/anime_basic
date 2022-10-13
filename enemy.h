#pragma once

#include "Vec2.h"

class Enemy
{
	
public:
	Enemy();
	virtual ~Enemy();

	// 初期化
	void init();

	void end();
	// 取得
	void get();
	// 処理
	void update();
	// 描画
	void draw();


	// 位置の取得
	Vec2 getPos() const { return m_pos; }

private:
	// グラフィックのサイズ取得
	Vec2 m_GraphSize;
	// 敵のハンドル
	int m_handle;
	// 表示位置
	Vec2 m_pos;
	// 移動
	Vec2 m_vec;
};
