#ifndef IOBSERVER_H
#define IOBSERVER_H
#include<iostream>
#include <list>
class GameObject;
class RectCollider;

class IObserver
{
public:
	virtual ~IObserver() {};
	virtual void Update() = 0;
};

class IObserverable
{
public:
	virtual ~IObserverable() {}
	void Remove();
	virtual void Notify() = 0;
	IObserver* currentObserver;
	static std::list<IObserver*> observerableContainer;
protected:
	virtual void Attach(IObserver* Observer) = 0;
	virtual void Detach(IObserver* Observer) = 0;
};

class GameObserver : public IObserver
{
public:
	GameObserver(GameObject* component_);
	~GameObserver();
	void DisplayAllMovementComponents();
	virtual void Update();
private:
	IObserverable* Observerable;
	int situation;
};







#endif //Observer
