#include "EnemyManager.h"//�G�L�������Ǘ�����N���X

bool EnemyManager::Initialize()
{
	LPCTSTR filename[] = { _T("�G�t�@�C��/SQUID1.png"),
						   _T("�G�t�@�C��/SQUID2.png"),
						   _T("�G�t�@�C��/OCTPAS1.png"),
						   _T("�G�t�@�C��/OCTPAS2.png"),
						   _T("�G�t�@�C��/CLBE2_mini.png") 
	};
	
	//�G�̍��W
	for (int i = 0;i< sizeof(enemy) / sizeof(enemy[0]);i++) 
	{
		enemy[i].Initialize(Vector3(150.0f+((i%10)*44.0f),
			                        50.0f+((i/10)*40.0f),0.0f),
			                       (filename[i / 10]));
		enemy[i].SetMoveRight();
	}
	
	enemy_mode = RIGHT_MOVE;

	//�}�W�b�N�i���o�[�ϐ�
	enemy_x_ = 700;
	enemy_y_ = 240;

	return true;
}

void EnemyManager::Main()
{
	for (int i = 0;i < 50;i++)
	{
		enemy[i].Main();
	}

	switch (enemy_mode)
	{
	    case RIGHT_MOVE:
	    {
		    for (int i = 0;i < 50;i++)
		    {
			    if (enemy[i].GetPosition().x > enemy_x_)
			    {
					enemy_mode = DOWN_MOVE;
					for (int i = 0; i < 50; i++)
					{
						if (enemy[i].GetStatus()!= Enemy::STATE::ENEMY_DEATH)
				        {
							enemy[i].SetMoveDown();
						}
					}
					break;
			    }
		    }
	    }
		break;

		case DOWN_MOVE:
		{
			for (int i = 0;i < 50;i++)
			{
				if (enemy[i].GetPosition().y > enemy_y_)
				{
					enemy_mode = DOWN_MOVE_NEXT_RIGHT;
					for (int i = 0; i < 50; i++)
					{
						if (enemy[i].GetStatus() != Enemy::STATE::ENEMY_DEATH)
						{
							enemy[i].SetMoveLeft();
						}
					}
					break;
				}
			}
		}
		break;

	    case DOWN_MOVE_NEXT_RIGHT:
	    {
			for (int i = 0;i < 50;i++)
			{
				if (enemy[i].GetPosition().x <100)
				{
					enemy_mode = DOWN_MOVE_NEXT_LEFT;
					for (int i = 0; i < 50; i++)
					{
						if (enemy[i].GetStatus() != Enemy::STATE::ENEMY_DEATH)
						{
							enemy[i].SetMoveDown();
						}
					}
					break;
				}
			}
	    }
		break;

	      case DOWN_MOVE_NEXT_LEFT:
	     {
		      for (int i = 0;i < 50;i++)
			  {
				  if (enemy[i].GetPosition().y > 100)
				  {
					  enemy_mode = RIGHT_MOVE;
					  for (int i = 0; i < 50; i++)
					  {
						  if (enemy[i].GetStatus() != Enemy::STATE::ENEMY_DEATH)
						  {
							  enemy[i].SetMoveRight();
						  }
					  }
				  }
			      break;
		      }
	     }
		 break;
	}
}

Rect EnemyManager::GetEnemyrect(int Enemynanber)//50�@�̒���������1�@�����o��
{
	Rect collision = Rect(enemy[Enemynanber].GetPosition().x,
						  enemy[Enemynanber].GetPosition().y, 
						  enemy[Enemynanber].GetPosition().x + 44,
						  enemy[Enemynanber].GetPosition().y + 32);

	return  collision;
}

void EnemyManager::Draw()
{
	for (int i = 0;i < 50;i++)
	{
		enemy[i].Draw();
	}
}