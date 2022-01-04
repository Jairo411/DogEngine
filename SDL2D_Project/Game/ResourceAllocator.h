#ifndef RESOURCEALLOCATOR
#define RESOURECALLOCATOR
/*NOTES I could Assign my ID's from one location within my engine that way all the ID's will be assigned one thing, instead of having multiple different IDS
*/
#include <utility>
#include <memory>
#include <string>
template<typename T>
class ResoureAllocator
{
public:

	ResoureAllocator(std::string filePath_)
	{
		reSource.first = filePath_;
		reSource.second = &T;
		currentID = 1; // this will change in the future
	}
	~ResoureAllocator()
	{
		currentID = 0;
		reSource.first = std::string().empty();
		reSource.second = nullptr;
		delete reSource.second;
	}

	T* getResource()
	{
		return reSource.second;
	};

	std::string getFileDirectory()
	{
		return reSource.first;
	};
private:
	int currentID;
	std::pair<std::string, T*> reSource;
};
#endif // !RESOURCEALLOCATOR
