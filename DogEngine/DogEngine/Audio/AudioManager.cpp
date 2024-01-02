#include "AudioManager.h"

AudioManager* AudioManager::instance = nullptr;

AudioManager::AudioManager()
{
	songContainer = std::vector<std::string>();
	engine = createIrrKlangDevice();
}

AudioManager::~AudioManager()
{
	engine->drop();
	engine = nullptr;
	delete engine;
}



AudioManager* AudioManager::GetInstance()
{
	if (instance==nullptr)
	{
		instance = new AudioManager();
	}
	return instance;
}

void AudioManager::AddSong(std::string songContainer_)
{
	songContainer.push_back(songContainer_.c_str());
}

void AudioManager::playFirstSong()
{
	engine->play2D(songContainer.front().c_str(),true);
}
