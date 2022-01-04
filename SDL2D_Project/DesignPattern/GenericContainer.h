#ifndef GENERICCONTAINER_H
#define GENERICCONTAINER_H
#include <string>
#include <vector>
#include <list>
#include <typeinfo>
#include <cstring>
#include <assert.h>
class GenericContainer
{
public:
	GenericContainer();
	~GenericContainer();

	// Function to add elements to the front of the container
	// simply pass the data type variable to the functions

	template <typename T>
	void Push_Front(const T& value_)
	{
		T* element = new T(value_);
		container.push_back(element);

		std::string type = GetTypeName<T>();
		typeNames.push_front(type);

		containerSize++;
	}


	// Function to add elements to the end of the container 
	// simply pass the data type variable to the function
	template <typename T>
	void Push_Back(const T& value)
	{
		T* element = new T(value);
		container.push_back(element);

		std::string type = GetTypeName<T>();
		typeNames.push_back(type);

		containerSize++;
	}

	//Function to set an element at a given index 
	// Returns true on successful insertion. Otherwise returns false 
	// If index > size of conatiner, all the elements in between are set as NULL
	// Doesn't allow setting to an index which already stores an element other than NULL

	template <typename T>
	void Insert(const int index_, const T& value_)
	{
		//check to see if the index you want to place is valid
		assert(index_ > container.size() || index_ < 0);
		if (index_ == 0) //check to see if its at the front of the container
		{
			Push_Front<T>(value_);
		}
		else if (index_ == container.size()) //check to see if its at the back of the container
		{
			Push_Back<T>(value_);
		}
		containerSize++;
		return true;
	};
	//Functions to remove an element at a given index 
	//Returns true on successful removal. Otherwise returns false 
	//call the function as remove<data type>()
	
	void RemoveFront();
	
	void Remove(void* type_); //RawPointer

	void RemoveBack();

	// Function returns the type cast value at the given index 
	// call get<data type>() to get the value 
	// casting to an incompatible type result in unexpected behaviour 
	// Does not allow to get an C++ array. Returns a zero on trying to do so 

	template <typename T>
	T Get(const int index)
	{
		return *((T*)container[index]);
	}
	template<typename T>
	bool IsType(const int index)
	{
		std::string type = typeid(T).name();

		if (type == typeNames[index])
			return true;

		return false;
	}
	// The function returns a string vector all data types
	std::vector <std::string> get_all_types();

	// Returns the data type name at the given index
	std::string get_type(const int index);

	// Returns the size of the container 
	size_t size();
private:
	std::list<void*> container; //these are the physical types that you access
	std::list<std::string> typeNames; // these are the types you have in the container. 
	size_t containerSize;
	
	//Function returns the demangled type 
	//Returns "NULL" if demangling fails
	template <typename T>
	std::string GetTypeName()
	{
		std::string nameType;
		nameType = typeid(T).name();
	
		return nameType;
	};
};
#endif //GENERICCONTAINER_H
