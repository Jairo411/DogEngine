#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H
#include <irrKlang.h>
#include <vector>
#include <string>
using namespace irrklang;
	class AudioManager
	{
	public:
		AudioManager(const AudioManager&) = delete;
		AudioManager(AudioManager&&) = delete;
		AudioManager& operator =(const AudioManager&) = delete;
		AudioManager& operator =(AudioManager&&) = delete;

		static AudioManager* GetInstance();
		void AddSong(std::string songContainer_);
		void playFirstSong();

	private:
		AudioManager();
		~AudioManager();

		std::vector<std::string> songContainer;
		static AudioManager* instance;
		ISoundEngine* engine;
	};
#endif
