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



private:
	// グラフィックのサイズ取得
	Vec2 m_GraphSize;
	// 敵のハンドル
	int m_handle;

	// 敵の縦・横の中心
	int GraphHeight;
	int GraphWidth;

	// 表示位置
	Vec2 m_pos;
	// 移動量
	Vec2 m_vec;
};
