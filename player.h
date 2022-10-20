#pragma once

#include "Vec2.h"

class Player
{
public:
	// 定数定義

	// グラフィックデータ分割数
	static constexpr int kGraphicDivX = 3;
	static constexpr int kGraphicDivY = 4;
	static constexpr int kGraphicDivNum = kGraphicDivX * kGraphicDivY;
	// グラフィックデータサイズ
	static constexpr int kGraphicSizeX = 28;
	static constexpr int kGraphicSizeY = 28;

public:
	Player();
	virtual ~Player();

	// グラフィックデータ設定
	void setHandle(int index, int handle) { m_handle[index] = handle; }

	// プレイヤーの初期化
	void init();
	// 終了処理
	void end();
	// 処理
	void update();
	// 描画
	void draw();

	//死亡設定
	void setDead(bool isDead) { m_isDead = isDead; }

	// 情報の取得
	Vec2 getPos() const { return m_pos; }

	// 当たり判定実装用に四方向の座標を取得する　
	float getLeft()	const { return m_pos.x; }
	float getRight()	const { return m_pos.x + m_size.x; }
	float getTop()	const { return m_pos.y; }
	float getBottom() const { return m_pos.y + m_size.y; }

private:
	int m_handle[kGraphicDivNum];	// 分割した12個の

	// 死亡設定
	bool m_isDead;

	// 表示位置
	Vec2 m_pos;
	// 移動
	Vec2 m_vec;
	// グラフィックのサイズ取得
	Vec2 m_size;

	// キャラクターのアニメーション
	int m_animeNo;	
	// 表示する番号
	int m_animeFrame;
	// 進行方向
	int m_dirNo;	
};