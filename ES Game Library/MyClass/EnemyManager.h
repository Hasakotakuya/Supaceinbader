#pragma once
#include "../ESGLib.h"
#include "Enemy.h"


class EnemyManager
{
public:
	bool Initialize();
	void Main();
	Rect GetEnemyrect(int Enemynanber);
	void Draw();


private:
	// �ϐ��錾
	Enemy enemy[50];

	//�}�W�b�N�i���o�[�ϐ�
	float  enemy_x_;
	float  enemy_y_;

	enum ENEMY_MODE
	{
		RIGHT_MOVE,
		DOWN_MOVE,
		DOWN_MOVE_NEXT_RIGHT,
		DOWN_MOVE_NEXT_LEFT
	};

	int enemy_mode;
};
