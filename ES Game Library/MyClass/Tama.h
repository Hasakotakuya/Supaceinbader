#pragma once
#include "../ESGLib.h"

class Tama
{
public:
	enum STATE {
		NOTFIRED,
		FIRED
	};

	bool Initialize();
	void firing(Vector3& state_pos);
	void Main();
	Rect GetTamarect();
	void Draw();

	int  GetState() { return state_; }

	Vector3 GetPosition() { return shot_pos; }

private:
	// •Ï”éŒ¾
	SPRITE  shot;
	Vector3 shot_pos;
	int     state_;

};