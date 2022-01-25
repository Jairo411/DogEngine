#ifndef FILEDIRECTORYHANDLER_H
#define FILEDIRECTORYHANDLER_H
#include <filesystem>
#include <vector>
#include <string>
#include <iostream>
#include <assert.h>
/*
* This class is suppose to read the contents of whatever directory it is in.
	What you are doing here is pure C++ 17 magic 
	*NOTE* you can do something with file extentions probably only showing the file extentions that you want. 
	* You haven't implementmented it because you're pretty lazy and it seems kinda extra work for you engine. 
	* leaving this note, to remind you it's possible just in case you need it. *From past jairo =) 
*/
/* just some clarfication here
* because im building my own command line object, ill leave some terminolongy for myself
* there are only three things my command line object can do 
* READ 
* which reads a physical directory or file 
* WRITE 
* which changes a physical directory or file by either adding it or removing it 
* VOID 
* anything else pretty much, using setters and getters (sometimes) anything that isn't immediate with the console interface.
*/
namespace fs = std::filesystem; //typedef, name alias
class FileDirectoryHandler
{
public:
	///Will construct a FileDirectoryHandler with no idea in which directory it is currently working in
	FileDirectoryHandler();
	///Will properly construct a FileDirectoryHandler with a CWD 
	FileDirectoryHandler(std::string directoryPath_);
	~FileDirectoryHandler();
	///Return current working READ
	std::string GetCurrentPath();
	///Returns directories inside of current working directory READ
	std::vector<std::string> GetDirectories();
	///Returns directory contents READ
	std::vector<std::string> GetDirectoryContents();
	///VOID
	std::vector<std::string> GetIntialDirectories();
	///VOID
	std::vector<std::string> GetIntialFiles();
	///Set intials directories and or files for the filedirectoryHandler class to have VOID
	void SetDefaults(std::vector<std::string> intial_directories_);
	void SetDefaults(std::vector<std::string> intial_directories_, std::vector<std::string> intial_files_);
	///Will show current Directory Contents READ
	void PrintDirectoryContents(); //Now I need to iteratorate through all the directory contents
	///Will show directory path READ
	void PrintDirectoryPath();
	///Will create new Directory, using full directory path WRITE
	void CreateDirectory(std::string fulldirectoryPath_);
	///VOID
	void Update();
	//Logic operators
	/// check to see if the directory path exist
	bool operator == (const char* directoryPath_);
	/// check to see if the default directories/file exist  
	bool operator == (std::vector<std::string> directories_);
	/// check to see if the directory path doesn't exist
	bool operator != (const char* directoryPath_);
	/// check to see if the default directories/file don't exist
	bool operator != (std::vector<std::string> directories_);
	//Assign operator
	/// Change the current working directory with full paths
	bool operator = (std::string path_);
private:
	std::string currentPath;
	std::vector<std::string> directoryFiles;
	std::vector<std::string> directories;
	std::vector<std::string> default_directories; 
	std::vector<std::string> default_files; 
	
};
#endif //FILEDIRECTORYHANDLER_H
