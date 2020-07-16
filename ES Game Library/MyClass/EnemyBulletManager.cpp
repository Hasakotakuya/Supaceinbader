#include "EnemyBulletManager.h"


bool EnemyBulletManager::Initialize()
{
	random = mt19937(seed());
    rand10 = std::uniform_int_distribution<>(0,9);//�͈͂̈�l����

	bullet_.Initialize();
	
	random_box = 0;

	return true;
}

void EnemyBulletManager::Main()
{
	bullet_.Main();
	//��ʂɒe���Ȃ������ׂ�
	if (bullet_.GetState() == NOTFIRED)
	{
		random_box = rand10(random);
		
		cout << "���A5" << random_box << endl;
		
		//�e���Ȃ���΁A���˂���
		bullet_.Firing(Vector3_Zero);
	}
}

void EnemyBulletManager::Draw()
{
	bullet_.Draw();
}
