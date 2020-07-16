#include "Player.h"

bool Player::Initialize()
{
	player = GraphicsDevice.CreateSpriteFromFile(_T("CANNON.png"));
	pos = Vector3(380,540,0);
	player_state_ = 0;
	tama.Initialize();

	TORCHKA = GraphicsDevice.CreateSpriteFromFile(_T("TORCHKA.png"));
	TORCHKA_pos = Vector3(100,420,0);


	SNDMANAGER.Initialize();

	return true;
}

void Player::Update()
{
	key_state = Keyboard->GetState();
	key_buffer = Keyboard->GetBuffer();
	Main();
}

void Player::Main()
{
    if (pos.x >740.0f)
    {
		pos.x = 740;
    }

    if (pos.x <15.0f)
    {
		pos.x = 15;
    }

	if (key_state.IsKeyDown(Keys_Left)) 
	{
		pos.x = pos.x -10;
	}

	if (key_state.IsKeyDown(Keys_Right)) 
	{
		pos.x = pos.x +10;
	}

	//’e‚Ì¶¬
	tama.Main();

	if (key_buffer.IsPressed(Keys_Space))
	{
		tama.firing(pos);
	}

	if (key_buffer.IsPressed(Keys_NumPad1))
	{
		SNDMANAGER.PlaySE(0);
	}

	if (key_buffer.IsPressed(Keys_NumPad2))
	{
		SNDMANAGER.PlaySE(1);
	}

	if (key_buffer.IsPressed(Keys_NumPad3))
	{
		SNDMANAGER.PlaySE(2);
	}

	if (key_buffer.IsPressed(Keys_NumPad4))
	{
		SNDMANAGER.PlaySE(3);
	}
}


void Player::Draw()
{
   SpriteBatch.Draw(*player,pos);

   SpriteBatch.Draw(*TORCHKA, TORCHKA_pos);

   tama.Draw();
}