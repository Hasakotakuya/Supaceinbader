#include "Tama.h"

bool Tama::Initialize()
{
	shot = GraphicsDevice.CreateSpriteFromFile(_T("BERM.png"));
	shot_pos =Vector3(0,0,0);
	state_ = NOTFIRED;

	return true;
}

void Tama::firing(Vector3& state_pos)
{
	if (state_ == NOTFIRED)
	{
		state_ = FIRED;
		shot_pos.x = state_pos.x+6;
		shot_pos.y = state_pos.y-14;
	}
}

void Tama::Main()
{
	if (state_ == FIRED)
	{
		shot_pos.y -=12.0f;
		if (shot_pos.y < 0)
			state_ = NOTFIRED;
	}
}

Rect Tama::GetTamarect()//50‹@‚Ì’†‚©‚ç“Á’è‚Ì1‹@‚ðŽæ‚èo‚·
{
	Rect collision = Rect(shot_pos.x, shot_pos.y,
		shot_pos.x + 22, shot_pos.y + 14);

	return  collision;
}

void Tama::Draw()
{
  if (state_ == FIRED)
  {
	SpriteBatch.Draw(*shot,shot_pos);
  }
}