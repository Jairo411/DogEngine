#ifndef RESOURCEALLOCATOR
#define RESOURCEALLOCATOR
/*NOTES I could Assign my ID's from one location within my engine that way all the ID's will be assigned one thing, instead of having multiple different IDS
*/
#include <utility>
#include <memory>
#include <string>
/* This class goes hand in hand with the components. 
* AnyType of assets information should be stored with this piece of information right here
*/
template<typename T>
class ResoureAllocator
{
public:

	ResoureAllocator()
	{
		currentID = 0;
	}

	~ResoureAllocator()
	{
		currentID = 0;
		resource.first = std::string().empty();
		resource.second = nullptr;
		delete resource.second;
	}

	ResoureAllocator(std::string filePath_)
	{
		T* ptr = new T();
		resource.first = filePath_;
		resource.second = ptr;
		currentID = 1; // this will change in the future the manager should assign this value 
	}
	ResoureAllocator(T infoStructs_)
	{
		T* ptr = &infoStructs_;
		resource.first = "NULL";
		resource.second = ptr;
		currentID = 1; // this will change in the future the manager should assign this value 
	}

	ResoureAllocator(std::string filePath_, T infoStructs_)
	{
		T* ptr = infoStructs_;
		resource.first = filePath_;
		resource.second = ptr;
		currentID = 1; // this will change in the future the manager should assign this value 
	}

	void setFileDirectoryLocation(std::string fileDirectory_)
	{
		resource.first = fileDirectory_;
	}

	T* getResource()
	{
		return resource.second;
	};

	std::string getFileDirectory()
	{
		return resource.first;
	};
private:
	int currentID;
	std::pair<std::string, T*> resource;
};
#endif // !RESOURCEALLOCATOR
