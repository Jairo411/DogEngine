#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
#include <list>
#include <queue>
#include "Event.h"
//For comparing if listenerInfo class has the same address. 
//checking to see if it is the same listenerInfo class not an 'equal' listenerInfo class.
inline bool operator ==(ListenerInfo lhs_, ListenerInfo rhs_)
{
	if (&lhs_ == &rhs_)
	{
		return true;
	}
	else
	{
		return false;
	}
};
//Comparing the level of priority an event has.
inline bool operator >(EventInfo lhs_, EventInfo rhs_)
{
	if (lhs_.priority>rhs_.priority)
	{
		return true;
	}
	else
	{
		return false;
	}
};
//Comparing the level of priority an event has.
inline bool operator < (EventInfo lhs_, EventInfo rhs_)
{
	if (lhs_.priority<rhs_.priority)
	{
		return true;
	}
	else
	{
		return false;
	}
}
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
		//Because of warning C4834: discarding return value of function with 'nodiscard' attribute
		(void*)listenerContainer.empty();
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
	void EnableInputs()
	{
		int totalJoySticks = SDL_NumJoysticks();
		std::cout << "Total Amount of JoySticks" << totalJoySticks << std::endl;
		SDL_GameController* controller = NULL;
		for (int i = 0; i < totalJoySticks; i++)
		{
			if (SDL_IsGameController(i))
			{
				controller = SDL_GameControllerOpen(i);
				std::cout << "Controller Name: " << SDL_GameControllerName(controller) << std::endl;
			}
		}
	};
	void HandleEvents()
	{
		SDL_PollEvent(event_);
		EventInfo eventInfo = EventInfo();
		eventInfo.event_ = event_;
		switch (event_->type)
		{
		case SDL_FIRSTEVENT:
			eventInfo.priority = EVENTPRIORITY::LOW;
			break;
		case SDL_QUIT:
			eventInfo.priority = EVENTPRIORITY::LOW;
			break;
		case SDL_APP_TERMINATING:
			eventInfo.priority = EVENTPRIORITY::LOW;
			break;
		case SDL_APP_LOWMEMORY:
			eventInfo.priority = EVENTPRIORITY::LOW;
			break;
		case SDL_APP_WILLENTERBACKGROUND:
			eventInfo.priority = EVENTPRIORITY::LOW;
			break;
		case SDL_APP_DIDENTERBACKGROUND:
			eventInfo.priority = EVENTPRIORITY::LOW;
			break;
		case SDL_APP_WILLENTERFOREGROUND:
			eventInfo.priority = EVENTPRIORITY::LOW;
			break;
		case SDL_APP_DIDENTERFOREGROUND:
			eventInfo.priority = EVENTPRIORITY::LOW;
			break;
		case SDL_DISPLAYEVENT:
			eventInfo.priority = EVENTPRIORITY::LOW;
			break;
		case SDL_WINDOWEVENT:
			eventInfo.priority = EVENTPRIORITY::LOW;
			break;
		case SDL_KEYDOWN:
			eventInfo.priority = EVENTPRIORITY::HIGH;
			break;
		case SDL_KEYUP:
			eventInfo.priority = EVENTPRIORITY::HIGH;
			break;
		case SDL_MOUSEMOTION:
			eventInfo.priority = EVENTPRIORITY::HIGH;
			break;
		case SDL_MOUSEBUTTONDOWN:
			eventInfo.priority = EVENTPRIORITY::HIGH;
			break;
		case SDL_MOUSEBUTTONUP:
			eventInfo.priority = EVENTPRIORITY::HIGH;
			break;
		case SDL_MOUSEWHEEL:
			eventInfo.priority = EVENTPRIORITY::HIGH;
			break;
		case SDL_CONTROLLERAXISMOTION:
			eventInfo.priority = EVENTPRIORITY::HIGH;
			break;
		case SDL_CONTROLLERBUTTONDOWN:
			eventInfo.priority = EVENTPRIORITY::HIGH;
			break;
		case SDL_CONTROLLERBUTTONUP:
			eventInfo.priority = EVENTPRIORITY::HIGH;
			break;
		case SDL_CONTROLLERDEVICEADDED:
			eventInfo.priority = EVENTPRIORITY::HIGH;
			EnableInputs();
			break;
		case SDL_CONTROLLERDEVICEREMOVED:
			eventInfo.priority = EVENTPRIORITY::HIGH;
			break;
		case SDL_CONTROLLERDEVICEREMAPPED:
			eventInfo.priority = EVENTPRIORITY::LOW;
			break;
		}
			if (eventInfo.priority==EVENTPRIORITY::LOW)
			{
				requestC.push(eventInfo);
			}
			else if (eventInfo.priority==EVENTPRIORITY::HIGH)
			{
				requestC.push(eventInfo);
			}
			
		if (!requestC.empty())
		{
			for (auto item : listenerContainer )
			{
				EventInfo tempEventInfo = requestC.top();
				item.listener->SetEvent(&tempEventInfo);
				item.listener->HandleEvents();
				if (tempEventInfo.handled==true)
				{
					requestC.pop();
					item.listener->SetEvent(nullptr);
					if (requestC.empty())
						break;
				}
			}
		}
		
	};
private:
	EventManager() : listenerContainer (std::list<ListenerInfo>()) , requestC(std::priority_queue<EventInfo,std::vector<EventInfo>>()), currentLength(0),passLength(0), event_(nullptr)
	{
	};
	inline static EventManager* instance = nullptr;
	std::list<ListenerInfo> listenerContainer;
	std::priority_queue<EventInfo, std::vector<EventInfo>> requestC;
	SDL_Event* event_;
	int currentLength;
	int passLength;
};


#endif // !EVENTMANAGER_H*/
