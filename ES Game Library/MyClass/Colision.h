#pragma once
#include "../ESGLib.h"
#include "EnemyManager.h"
#include"Tama.h"

class Colision
{
public:

	Colision() {};
	~Colision() {};

	bool Initialize();
	bool Update(EnemyManager&enemymanager, Tama&tama);
	void Draw();

	
private:
	// •Ï”éŒ¾

};