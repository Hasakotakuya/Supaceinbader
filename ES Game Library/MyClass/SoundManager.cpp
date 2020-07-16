#include "SoundManager.h"

bool SoundManager::Initialize()
{
	se_[0] = SoundDevice.CreateSoundFromFile(_T("移動効果音/float_se.wav"));
	se_[1] = SoundDevice.CreateSoundFromFile(_T("移動効果音/float_se2.wav"));
	se_[2] = SoundDevice.CreateSoundFromFile(_T("移動効果音/float_se3.wav"));
	se_[3] = SoundDevice.CreateSoundFromFile(_T("移動効果音/float_se4.wav"));

	return true;
}

void SoundManager::PlaySE(int index)
{
    se_[index]->Play();	
}


void SoundManager::Stop(int index)
{
	se_[index]->Stop();

}