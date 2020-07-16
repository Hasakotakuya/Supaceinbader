#pragma once
#include "../ESGLib.h"

class EnemyBullet
{
public:

	enum STATE {
		NOTFIRED,
		FIRED
	};

	bool Initialize();
	void Firing(Vector3& b_pos);
	void Main();
	void Draw();
	
	int  GetState() { return state_; }

private:
	// •Ï”éŒ¾
	static SPRITE sprite_;
	Vector3       position_;
	int           state_;
};