#ifndef FILEDIRECTORYHANDLER_H
#define FILEDIRECTORYHANDLER_H
#include <filesystem>
#include <vector>
#include <string>
#include <iostream>
/*
* This class is suppose to read the contents of whatever directory it is in.
	What you are doing here is pure C++ 17 magic 
	*NOTE* you can do something with file extentions probably only showing the file extentions that you want. 
	* You haven't implementmented it because you're pretty lazy and it seems kinda extra work for you engine. 
	* leaving this note, to remind you it's possible just in case you need it. *From past jairo =) 
*/
class FileDirectoryHandler
{
public:
	FileDirectoryHandler();
	FileDirectoryHandler(std::string directoryPath_);
	~FileDirectoryHandler();
	///Return current working 
	std::string GetCurrentPath();
	///Returns directories inside of current working directory
	std::vector<std::string> GetDirectories();
	///Returns directory contents
	std::vector<std::string> GetDirectoryContents();
	///Change current working directory
	void ChangeDirectory(std::string directoryPath_);
	///Will show current Directory Contents
	void PrintDirectoryContents(); //Now I need to iteratorate through all the directory contents
	///Will show directory path
	void PrintDirectoryPath();
private:
	std::string currentPath;
	std::vector<std::string> directoryContents;
	std::vector<std::string> directories;
	
};
#endif //FILEDIRECTORYHANDLER_H
