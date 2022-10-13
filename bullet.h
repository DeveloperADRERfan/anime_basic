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
	void get();
	// 処理
	void update();
	// 描画
	void draw();


private:
	// 表示位置
	Vec2 m_pos;
	// 移動量
	Vec2 m_vec;
	// グラフィックのサイズ取得
	Vec2 m_GraphSize;

	// 弾のハンドル
	int m_handle;
	
};
