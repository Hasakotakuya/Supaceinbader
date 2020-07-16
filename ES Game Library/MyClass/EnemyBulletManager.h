#pragma once
#include "../ESGLib.h"
#include "EnemyBullet.h"
#include <random>
#include <iostream>

class EnemyBulletManager
{
public:
	enum STATE {
		NOTFIRED,
		FIRED
	};
	

	bool Initialize();
	void Main();
	void Draw();

private:
	// �ϐ��錾
	EnemyBullet  bullet_;
	random_device   seed;
	mt19937         random;
	std::uniform_int_distribution<> rand10;//�͈͂̈�l����
	int   random_box;

};