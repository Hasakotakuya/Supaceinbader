#include "Enemy.h"

bool Enemy::Initialize(Vector3& Initialize_pos, LPCTSTR filename)
{
	//�G�̌Ăяo��
	enemy = GraphicsDevice.CreateSpriteFromFile(filename);

	//�G�̏������W
	enemy_pos= Initialize_pos;

	// �G�������Ă��邩�ǂ����̃t���O��\���ϐ�
	enemy_flag_mode = STOP;

	tama.Initialize();

	return true;
}

void Enemy::Update()
{
	key_state = Keyboard->GetState();
	key_buffer = Keyboard->GetBuffer();
	Main();
}

void Enemy::Main()
{
	switch (enemy_state_)
	{
	case MOVE_RIGHT:
	{
		enemy_pos.x = enemy_pos.x + 0.5;
		break;
	}

	case MOVE_DOWN:
	{
		enemy_pos.y = enemy_pos.y + 0.5;
		break;
	}

	case MOVE_LEFT:
	{
		enemy_pos.x = enemy_pos.x - 0.5;
		break;
	}
	}
}

void Enemy::SetMoveRight()
{
	enemy_state_ = MOVE_RIGHT;
}

void Enemy::SetMoveDown()
{
	enemy_state_ = MOVE_DOWN;
}

void Enemy::SetMoveLeft()
{
	enemy_state_ = MOVE_LEFT;
}

void Enemy::SetDeathStatus()
{
	enemy_flag_mode = ENEMY_DEATH;
}

void Enemy::Draw()
{
	if (enemy_flag_mode != ENEMY_DEATH)
	{
		SpriteBatch.Draw(*enemy,enemy_pos);
	}
}
