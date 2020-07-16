#include "EnemyBullet.h"

SPRITE  EnemyBullet::sprite_ = NULL;//’è‹`

bool EnemyBullet::Initialize()
{

	sprite_ = GraphicsDevice.CreateSpriteFromFile(_T("Berm_.png"));
	position_ = Vector3(0,0,0);
	state_ = NOTFIRED;

	return true;
}

void EnemyBullet::Firing(Vector3& b_pos)
{
	if (state_ == NOTFIRED)
	{
		state_ = FIRED;
		position_.x = b_pos.x;
		position_.y = b_pos.y;
	}
}

void EnemyBullet::Main()
{
	if (state_ == FIRED)
	{
		position_.y += 5.0f;
		if (position_.y >540)
			state_ = NOTFIRED;
	}
}

void EnemyBullet::Draw()
{
	if (state_ == FIRED)
	{
		SpriteBatch.Draw(*sprite_,position_);
	}
}