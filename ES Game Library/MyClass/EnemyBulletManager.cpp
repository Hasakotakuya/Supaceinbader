#include "EnemyBulletManager.h"


bool EnemyBulletManager::Initialize()
{
	random = mt19937(seed());
    rand10 = std::uniform_int_distribution<>(0,9);//範囲の一様乱数

	bullet_.Initialize();
	
	random_box = 0;

	return true;
}

void EnemyBulletManager::Main()
{
	bullet_.Main();
	//画面に弾がないか調べる
	if (bullet_.GetState() == NOTFIRED)
	{
		random_box = rand10(random);
		
		cout << "レア5" << random_box << endl;
		
		//弾がなければ、発射する
		bullet_.Firing(Vector3_Zero);
	}
}

void EnemyBulletManager::Draw()
{
	bullet_.Draw();
}
