#ifndef SCENEMANAGER_HEADER
#define SCENEMANAGER_HEADER
#include <memory>
#include <unordered_map>
#include "Scene.h"
#include "../EngineSerializer.h"
#include "../../Thread/ThreadAble.h"
/*2021-07-09
 This code here is fine.*/
class SceneManager : public ThreadAble
{
public:

	SceneManager(const SceneManager&) = delete;
	SceneManager(SceneManager&&) = delete;
	SceneManager& operator =(const SceneManager&) = delete;
	SceneManager& operator =(SceneManager&&) = delete;

	static SceneManager* GetInstance();

	void HandleEvents();
	void Update(float deltaTime_);
	void FixedUpdate(float deltaTime_);
	void Render();
	void handleCollison();
	unsigned int Add(std::shared_ptr<Scene> scene);
	bool load(); // this will take a deserialized string value and create a new scene in prospective to its coording xml information
	void SwitchTo(unsigned int id);
	void Remove(unsigned int id);
	//Inherited function
	virtual void RunInstructions();
private:
	SceneManager();
	~SceneManager();
	static SceneManager* instance;
	friend Serializer;
	std::unordered_map<unsigned int, std::shared_ptr<Scene>> scenes;
	std::shared_ptr<Scene> curScene;
	unsigned int insertedSceneID;
};
#endif //SCENEMANAGER_HEADER
