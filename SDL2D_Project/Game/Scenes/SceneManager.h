#ifndef SCENEMANAGER_HEADER
#define SCENEMANAGER_HEADER
#include <memory>
#include <unordered_map>
#include "Scene.h"

class SceneManager
{
public:
	SceneManager();

	void ProcessInput();
	void Update();
	void Render();
	void handleCollison();
	unsigned int Add(std::shared_ptr<Scene> scene);

	void SwitchTo(unsigned int id);

	void Remove(unsigned int id);

private:

	std::unordered_map<unsigned int, std::shared_ptr<Scene>> scenes;

	std::shared_ptr<Scene> curScene;

	unsigned int insertedSceneID;
};
#endif //SCENEMANAGER_HEADER
