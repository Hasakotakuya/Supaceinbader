#pragma once
#include "../ESGLib.h"

class SoundManager
{
public:
	virtual ~SoundManager() {}

	// シングルトンインスタンスの取得
	static SoundManager& GetInstance()
	{
		static SoundManager theSEManager;
		return theSEManager;
	}

	bool Initialize();
	void PlaySE(int index);
	void Stop(int index);

private:
	SoundManager() {}

	SOUND  se_[4];

	SoundManager(const SoundManager&);
	SoundManager& operator=(const SoundManager&);
};

//------------------------------------------------------------------------------
//	インライン関数定義
//------------------------------------------------------------------------------
inline SoundManager& SNDMgr() { return SoundManager::GetInstance(); }
#define SNDMANAGER SoundManager::GetInstance()
	

	