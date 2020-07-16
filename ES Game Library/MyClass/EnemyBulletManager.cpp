#include "EnemyBulletManager.h"


bool EnemyBulletManager::Initialize()
{
	random = mt19937(seed());
    rand10 = std::uniform_int_distribution<>(0,9);//”ÍˆÍ‚Ìˆê—l—”

	bullet_.Initialize();
	
	random_box = 0;

	return true;
}

void EnemyBulletManager::Main()
{
	bullet_.Main();
	//‰æ–Ê‚É’e‚ª‚È‚¢‚©’²‚×‚é
	if (bullet_.GetState() == NOTFIRED)
	{
		random_box = rand10(random);
		
		cout << "ƒŒƒA5" << random_box << endl;
		
		//’e‚ª‚È‚¯‚ê‚ÎA”­Ë‚·‚é
		bullet_.Firing(Vector3_Zero);
	}
}

void EnemyBulletManager::Draw()
{
	bullet_.Draw();
}
