#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;

SceneManager::SceneManager() : scenes(0), curScene(0), insertedSceneID(NULL) {}

SceneManager::~SceneManager()
{
	instance = nullptr;
	delete instance;
}

SceneManager* SceneManager::GetInstance()
{
	if (instance==nullptr)
	{
		instance = new SceneManager();
		return instance;
	}
	else
	{
		return instance;
	}
}

void SceneManager::HandleEvents()
{
	if (curScene)
	{
		curScene->HandleEvents();
	}
}

void SceneManager::Update(float deltaTime_)
{
	if (curScene)
	{
		curScene->Update(deltaTime_);
	}
}

void SceneManager::FixedUpdate(float deltaTime_)
{
	if (curScene)
	{
		curScene->FixedUpdate(deltaTime_);
	}
}

void SceneManager::Render()
{
	if (curScene)
	{
		curScene->Render();
	}
}

void SceneManager::handleCollison()
{
	if (curScene)
	{
		curScene->HandleCollison();
		
	}
}



unsigned int SceneManager::Add(std::shared_ptr<Scene> scene)
{
	auto inserted = scenes.insert(std::make_pair(insertedSceneID, scene));
	insertedSceneID++;

	inserted.first->second->OnCreate();

	return insertedSceneID - 1;
}

void SceneManager::SwitchTo(unsigned int id)
{
	auto it = scenes.find(id);
	if (it != scenes.end())
	{
		if (curScene)
		{
			curScene->OnDeactivate();
		}

		curScene = it->second;

		curScene->OnActivate();
	}
}

void SceneManager::Remove(unsigned int id)
{
	auto it = scenes.find(id);

	if (it != scenes.end())
	{
		if (curScene == it->second)
		{
			curScene = nullptr;
		}

		it->second->OnDestroy();
		scenes.erase(it);
	}
}

void SceneManager::RunInstructions()
{
	while (getThreadAssignment() == true)
	{
		Render();
	}

}

