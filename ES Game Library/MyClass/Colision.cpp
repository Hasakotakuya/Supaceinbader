#include "Colision.h"

bool Colision::Initialize()
{
	
	return false;
}

bool Colision::Update(EnemyManager& enemymanager,Tama& tama)
{
	Rect collision= tama.GetTamarect();

	for (int i = 0;i < 50;i++)
	{
		Rect collision2 = enemymanager.GetEnemyrect(i);

		// 敵と有効なショットの当たり判定を行う
		if (collision.Intersect(collision2))
		{

		}
	}

	return 0;
}

void Colision::Draw()
{
	
}