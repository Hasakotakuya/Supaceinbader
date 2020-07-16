#pragma once
#include "../ESGLib.h"
#include "Tama.h"

class Enemy
{
public:
	enum STATE {
		STOP,
		MOVE_RIGHT,
		MOVE_LEFT,
		MOVE_DOWN,
		ENEMY_DEATH
	};

	bool Initialize(Vector3& Initialize_pos, LPCTSTR filename);
	void Update();
	void Main();
	void Draw();
	
	void SetMoveRight();
	void SetMoveLeft();
	void SetMoveDown();
	void SetDeathStatus();

	Vector3 GetPosition() { return enemy_pos; }
	int     GetStatus(){ return enemy_flag_mode; }

private:
	// •Ï”éŒ¾

	SPRITE  enemy;
	Vector3  enemy_pos;

	Tama  tama;
	Vector3  tama_pos;

	KeyboardBuffer	key_buffer;
	KeyboardState   key_state;

	//“G‚ª¶‚«‚Ä‚¢‚é‚©‚Ç‚¤‚©‚Ìƒtƒ‰ƒO‚ğ•\‚·•Ï”
	int  enemy_flag_mode;

	int     enemy_HP_;
	int     enemy_state_;

};
