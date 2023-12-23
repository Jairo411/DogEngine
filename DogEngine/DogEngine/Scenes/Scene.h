#ifndef SCENE_HEADER
#define SCENE_HEADER
/* 13-07-2023
* abstract Scene class. This is where all gamescenes inheret there functionality. 
*/
class Scene
{
public:
	virtual void OnCreate() = 0; 
	virtual void OnDestroy() = 0;
	virtual void OnActivate() = 0;
	virtual void OnDeactivate() = 0;
	virtual void HandleEvents() {};
	virtual void HandleCollison() {};
	/// <summary>
	/// Put all scene game logic here  
	/// </summary>
	/// <param name="deltaTime_"> change in time ms </param>
	virtual void Update(float deltaTime_) = 0;
	/// <summary>
	/// Render GameObjects to the Scene. NOTE: There shouldn't be alot of logic added 
	/// in this function. Most of the time the GameObjectManager()->render should be the only line of code here. 
	/// </summary>
	virtual void Render() = 0;
	int currentScene;
};
#endif //SCENE_HEADER