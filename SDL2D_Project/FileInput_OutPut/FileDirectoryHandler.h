#ifndef FILEDIRECTORYHANDLER_H
#define FILEDIRECTORYHANDLER_H
#include <filesystem>
#include <string>
/*
* This class is suppose to read the contents of whatever directory it is in.
	What you are doing here is pure C++ 17 magic 
*/
class FileDirectoryHandler
{
public:
	FileDirectoryHandler();
	FileDirectoryHandler(std::string filePath_);
	~FileDirectoryHandler();

	//Now I need to iteratorate through all the directory contents
	
private:
	std::string currentPath;
	
};
#endif //FILEDIRECTORYHANDLER_H
