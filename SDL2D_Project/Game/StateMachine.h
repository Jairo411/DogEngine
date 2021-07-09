#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <thread>
#include<variant>
#include <utility>
#include <string>
/*
	QUICK EXPLAINTION:
	to as why you decided that having a statemachine was better than just separating threads and such,
	Since the serializer Engine has clear states that I can define, like read and write. At first I wanted to simply have these processes ran
	through a thread object, but because I only could run one process within the class before having to, join the thread back again. I would essentially have
	one extra processing doing all my serializtion/deserializition. Something that I consider to be, very stupid....

	REASONING:
	If the processes could be clearly define through what serializer is doing. Then I could have the processes run through at the very least two threads.
	As well by adding the statemachine we are simplifying the update capiability for this project.
*/

template <typename... States> // what is with all the dots, seems like just a prefence thing 
class StateMachine
{
public:
	template <typename State>
	void transitionTo()
	{
		CurrentState = &std::get<State>(state);
		//CurrentState = &std::get<State>(states);// gets current state to be later called in function
	}

	/*template <typename Event>
	void handle(const Event& event)
	{
		handleBy(event, *this);
	}*/

	//template <typename Event, typename Machine>
	//void handleBy(const Event& event, Machine& machine)
	//{
	//	auto passEventToState = [&machine, &event](auto statePtr)
	//	{
	//		auto action = statePtr->handle(event); // handle returns a event and action essentially becomes the event, then you are able to straight up call .execute
	//		action.execute(machine, *statePtr, event);
	//	};
	//	std::visit(passEventToState, CurrentState);
	//}
	//template <typename Event>
	void handle(const Event& event)
	{
		auto passeventToState = [this, &event](auto statePtr){ // generic lambda function, I pass a state, since my parameter variable define as auto, the computer will assign its type to the state I give it.
			statePtr->handle(event).execute(*this); //StatePtr has yet no function, this is a way of letting the computer handle the type and you define what function of that type to be called, since all events will have a handle function, which will return a a State function object( I think...) which will allow to execute your stateMachine functions for single state at a given time.
		};// a lambda function is, the "forward delcaration of a function" for a lack of a better term. its calling a function that has yet to be define properly. 
		std::visit(passeventToState, CurrentState); //its a function call for variants 
		//Because statePTr->handle(event).execute(*this) line of code exist it will call execute always, even if it has nothing to transition too
		//last but not least the compiler ensures that all the state types have a 'handle' method that accpets an event of type T
	}
	std::tuple<States...> states; //What are tuples????, tuple is an ordering of what it seems like generic types of data. Its like std::pair.
	std::variant<States...> CurrentState{ &std::get<0>(states) };//the {bracket std::get<0>(State) is defaulting the CurrentState variable to the first index of variant variable }//what is this as well?, std::variant allows you to present all the possible types it could be, then you decide what it will be later. the reason its doing this is because of the amount of possible states I could create, each one is considered a different type. 
};

/*
* This is a way of instructing the machine to perform a transition while being iside an event handler in a given state.
* By returning an intermediate object from the state's 'handle' method that will describe what action should the machine take.
* Now for my description :
* this is essentally a functor, this struct is always in the return part of the function EXAMPLE:
* TransitionTo<WriteState>
*
* with one function and a template type, when execute is ran it access a template within our execute function on a Machine type which will be passed as the *this keyword making the type STATEMACHINE<N0,N1,N..> making it the type,
* Then running within our StateMachine code the transitionTo() void function that we created.
* Which will Change the Current State Within our std::tuple data structure. As well to comfirm to as why std::variant needs to be used, all the types are generic but not the same types.
* I am making a bunch of random types before hand and defining them later, essentally.
*/
template<typename State>
struct TransitionTo
{
	template <typename Machine>
	void execute(Machine& machine)
	{
		machine.template  transitionTo<State>(); // what is template? I'm pretty sure this is a way of saying call this function template, then you have to describe it what function template it is. 
												// so forward delcaration but for a function. 
	}
};


struct Nothing
{
	template<typename Machine>
	void execute(Machine&)
	{
	}
};

template<typename Action>
struct ByDefault
{
	template <typename Event>
	Action handle(const Event&)const
	{
		return {};
	}
};
///*The On struct is essentally what turns the state On.
//* Takes an a Event which has an Action associated with it,
//* so it could be easily tranistioned into.
//*/
//template <typename Event, typename Action>
//struct On
//{
//	Action handle(const Event&) const
//	{
//		return {};
//	}
//};
//
//template <typename... Handlers>
//struct Will : Handlers...
//{
//	using Handlers::handle...; //I think this is saying that whatever functor, and most likely ill be putting a functor into the typename handlers 
//							// the using delecaration would display all handle functions, or override them. not sure yet.
//};
//
//template<typename... Actions>
//class OneOf
//{
//public:
//	template<typename T>
//	OneOf(T&& arg)
//		: options(std::forward<T>(arg)) // The best way to describe this is forwards the L vaules as L values and R values as R Values. There is no better way to describe this at the current moment
//	{
//	}
//
//	template <typename Machine, typename State, typename Event>
//	void execute(Machine& machine, State& state, const Event& event)
//	{
//		std::visit([&machine](auto& action) {action.execute(machine); }, options); //pretty sure this is a lambda function again within this function. 
//	}
//private:
//	std::variant<Actions...> options;
//};
//template<typename Action>
//struct Maybe : public OneOf<Action, Nothing>
//{
//	using OneOf<Action, Nothing>::OneOf; // I guess this is a quick way of saying return this or dont. 
//};

struct IntializedEvent
{
};
struct UpdateEvent //Only event I need to lock, is this one 
{
};
struct ReadEvent
{
};
struct WriteEvent
{
};


struct IntializedState;
struct UpdateState;
struct ReadState;
struct WriteState;

//struct IntializedState : public Will<ByDefault<Nothing>,On<UpdateEvent,TransitionTo<UpdateState>>>
//{};
//struct UpdateState : public Will<ByDefault<Nothing>,On<ReadEvent,TransitionTo<ReadState>>,On<WriteEvent,TransitionTo<WriteState>>>
//{};
//struct ReadState : public Will<ByDefault<Nothing>, On<WriteEvent,TransitionTo<WriteState>>, On<UpdateEvent, TransitionTo<UpdateEvent>>>
//{};
//struct WriteState : public Will<ByDefault<Nothing>, On<ReadState, TransitionTo<ReadState>>, On<UpdateEvent, TransitionTo<UpdateState>>>
//{};

/* What Do these States do?
* Well Agian these are functors, In the Website they describes this as intermedite objects,
* I agree with there use now that I understand them. They are a functors, that return certain functors based
* on what parameters you give them. Each different State is a define functor that has its behaviour defined after the
* statemachine.
*
* Note:
* return {}; means return an object of the function's return type initialized.
* meaning:
* {
*			Nothing handle(const IntializedEvent&)const
*		 {
*			return{};<-- will return Nothing();
*		 }
* };
*/

//class IntializedState :public ByDefault<Nothing>
//{
//public:
//	using ByDefault::handle;
//	IntializedState()
//	{
//		std::cout << "StateMachine Created" << std::endl;
//	};
//	Maybe<TransitionTo<UpdateState>> handle(const UpdateEvent& e)const
//	{
//		return TransitionTo<UpdateState>{};
//	}
//};
//
//class UpdateState :public ByDefault<Nothing>
//{
//public:	
//	using ByDefault::handle;
//	UpdateState()
//	{
//		std::cout << "Currently in the Update State" << std::endl;
//	}
//	
//};

//struct IntializedState : public Will<ByDefault<Nothing>, On<IntializedEvent, TransitionTo<UpdateState>>>
//{
//	//using ByDefault::handle; //Sorta like inheretance but not really. I should be able to see the ByDefault's handle function.
//	//using On < IntializedEvent, TransitionTo<UpdateState>>::handle;
//	//Nothing handle(const IntializedEvent&)const
//	//{
//	//	std::cout << "Starting StateMachine" << std::endl;
//	//	return {};
//	//}
//
//	//Nothing handle(const ReadEvent&)const //It will return a TransitionTo UpdateState Type
//	//{
//	//	std::cout << "Can't transition to ReadState from intialized" << std::endl;
//	//	std::cout << "moving to UpdateState" << std::endl;
//	//	return {};
//	//}
//	//Nothing handle(const WriteEvent&)const //It will return a TransitionTo UpdateState Type
//	//{
//	//	std::cout << "Can't transition to Write from intialized" << std::endl;
//	//	std::cout << "moving to UpdateState" << std::endl;
//	//	return {};
//	//}
//
//	//TransitionTo<UpdateState> handle(const UpdateEvent&)const
//	//{
//	//	std::cout << "moving to UpdateState" << std::endl;
//	//	return {};
//	//}
//};


/* These are the State in there define nature....
*/
struct IntializedState
{
	Nothing handle(const IntializedEvent&)const
	{
		std::cout << "Intializing StateMachine" << std::endl;
		return {};
	}
	TransitionTo<UpdateState> handle(const UpdateEvent&)const
	{
		std::cout << "Transitioning to updateState" << std::endl;
		return{};
	}
	Nothing handle(const ReadEvent&) const
	{
		std::cout << "Can't Transition to ReadState" << std::endl;
		return {};
	}
	Nothing handle(const WriteEvent&)const
	{
		std::cout << "Can't Transition to WriteState" << std::endl;
	}

};

struct UpdateState
{
	Nothing handle(const UpdateEvent&)const
	{
		std::cout << "Current State is UpdateState" << std::endl;
		return {};
	}
	Nothing handle(const IntializedEvent&)const
	{
		std::cout << "Can't traverse from Update to Intialized" << std::endl;
		return {};
	}
	TransitionTo<ReadState> handle(const ReadEvent&)const
	{
		std::cout << "Moved to ReadState" << std::endl;
		return {};
	}
	TransitionTo<WriteState> handle(const WriteEvent&)const
	{
		std::cout << "Moved to WriteState" << std::endl;
		return {};
	}
};

struct ReadState
{
	Nothing handle(const ReadEvent&)const
	{
		std::cout << "Current State is ReadState" << std::endl;
		return {};
	}
	Nothing handle(const IntializedEvent&)const
	{
		std::cout << "Can't traverse from Read to Intialized" << std::endl;
		return {};
	}
	TransitionTo<UpdateState> handle(const UpdateEvent&)const
	{
		std::cout << "moved to UpdateState" << std::endl;
		return {};
	}
	TransitionTo<WriteState> handle(const WriteEvent&)const
	{
		std::cout << "moved to WriteState" << std::endl;
		return {};
	}
};

struct WriteState
{
	Nothing handle(const WriteEvent&)const
	{
		std::cout << "Current State is WriteEvent" << std::endl;
		return {};
	}
	Nothing handle(const IntializedEvent&)const
	{
		std::cout << "Can't traverse from Write to Intialized" << std::endl;
		return {};
	}
	TransitionTo<ReadState> handle(const ReadEvent&)const
	{
		std::cout << "Moved to ReadState" << std::endl;
		return {};
	}
	TransitionTo<UpdateState> handle(const UpdateEvent&)const
	{
		std::cout << "Moved to UpdateState" << std::endl;
		return {};
	}
};

#endif