#pragma once
#include "../ESGLib.h"
#include "Tama.h"
#include "SoundManager.h"

class Player
{
public:

	bool Initialize();
	void Update();
	void Main();
	void Draw();

	Vector3 GetPosition() { return pos; }

private:
	// �ϐ��錾
	SPRITE  player;
	Vector3 pos;
	int     player_state_;

	Tama  tama;

	KeyboardBuffer	key_buffer;
	KeyboardState   key_state;

	SPRITE  TORCHKA;
	Vector3 TORCHKA_pos;
};