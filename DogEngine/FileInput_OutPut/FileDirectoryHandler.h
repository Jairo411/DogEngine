#ifndef FILEDIRECTORYHANDLER_H
#define FILEDIRECTORYHANDLER_H
#include <filesystem>
#include <vector>
#include <string>
#include <iostream>
#include <assert.h>
/* 13-07-2023
* This is my FileDirectoryHandler class, this class creates,navigates and stores important file information. 
* The types of files that I want to create mainly are, Dogengine files. These files are mainly plain txt.
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
	///Return current working, READ
	std::string GetCurrentPath();
	///Returns directories inside of current working directory, READ
	std::vector<std::string> GetDirectories();
	///Returns directory contents, READ
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
