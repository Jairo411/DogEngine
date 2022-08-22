#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
#include <list>
#include <queue>
#include "Event.h"
#include <thread>
#include <chrono>

enum class EVENTPRIORITY
{
	NONE = 0,
	LOW,
	MEDIUM, 
	HIGH,
};

struct EventInfo
{
	SDL_Event* event_ = nullptr;
	EVENTPRIORITY priority =  EVENTPRIORITY::NONE;
};

struct ListenerInfo 
{
	int order = 0;  
	int index = 0; 
	EventListener* listener = nullptr; 
};  

inline bool operator ==(ListenerInfo lhs, ListenerInfo rhs)
{
	if (&lhs == &rhs)
	{
		return true;
	}
	else
	{
		return false;
	}
};
class EventManager
{
public:
	EventManager(const EventManager&) = delete;
	EventManager(EventManager& other) = delete;
	EventManager& operator =(const EventManager&) = delete;
	EventManager& operator =(EventManager&) = delete;
	~EventManager() {};
	inline static EventManager* GetInstance()
	{
		if (instance==nullptr)
		{
			instance= new EventManager();
		}
		return instance;
	};
	void OnCreate()
	{
	};
	void OnDestroy()
	{
		listenerContainer.empty();
	};
	void AddListener(ListenerInfo info_) 
	{
		listenerContainer.push_back(info_);
		currentLength++;
	}
	void RemoveListener(ListenerInfo info_)
	{ 
		listenerContainer.remove(info_); 
		info_.listener->~EventListener();
		currentLength--;
	}
	void SetEvent(SDL_Event* e_)
	{
		event_ = e_;
	};
	void CheckInputs()
	{
		
	}
	void HandleEvents()
	{
		SDL_PollEvent(event_);
		EventInfo eventInfo = EventInfo();
		eventInfo.event_ = event_;
		std::cout << "Event Type " << event_->type << std::endl;
			switch (event_->type)
			{
		/*	SDL_WINDOWEVENT_CLOSE:
				eventInfo.priority = EVENTPRIORITY::LOW;
				requestContainer.push(eventInfo);
				break;
			SDL_WindowEvent:
				eventInfo.priority = EVENTPRIORITY::LOW;
				requestContainer.push(eventInfo);
				break;
			SDL_KeyboardEvent:
				eventInfo.priority = EVENTPRIORITY::HIGH;
				requestContainer.push(eventInfo);
				break;
			SDL_MouseMotionEvent:
				eventInfo.priority = EVENTPRIORITY::HIGH;
				requestContainer.push(eventInfo);
				break;
			SDL_MouseButtonEvent:
				eventInfo.priority = EVENTPRIORITY::HIGH;
				requestContainer.push(eventInfo);
				break;
			SDL_MouseWheelEvent:
				eventInfo.priority = EVENTPRIORITY::HIGH;
				requestContainer.push(eventInfo);
				break;
			SDL_ControllerAxisEvent:
				eventInfo.priority = EVENTPRIORITY::HIGH;
				requestContainer.push(eventInfo);
				break;
			SDL_ControllerButtonEvent:
				eventInfo.priority = EVENTPRIORITY::HIGH;
				requestContainer.push(eventInfo);
				break;
			SDL_ControllerDeviceEvent:
				eventInfo.priority = EVENTPRIORITY::HIGH;
				requestContainer.push(eventInfo);
				break;
			default:
				break;*/
			} 
		/*	if (eventInfo.priority==EVENTPRIORITY::LOW)
			{
				requestContainer.emplace(eventInfo);
			}
			
		if (!requestContainer.empty())
		{
				SDL_Event* tempEvent = requestContainer.front().event_;
				for (auto item : listenerContainer)
				{
					item.listener->SetEvent(tempEvent);
					item.listener->HandleEvents();
				};
		}*/
		
	};
private:
	EventManager() : listenerContainer (std::list<ListenerInfo>()) , requestContainer(std::queue<EventInfo>()), currentLength(0),passLength(0), event_(nullptr)
	{
	};
	inline static EventManager* instance = nullptr;
	std::list<ListenerInfo> listenerContainer;
	std::queue<EventInfo> requestContainer;
	SDL_Event* event_;
	int currentLength;
	int passLength;
};


#endif // !EVENTMANAGER_H*/
