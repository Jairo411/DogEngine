#ifndef FILEDIRECTORYHANDLER_H
#define FILEDIRECTORYHANDLER_H
#include "../DogEngineDefinitions.h"
#include <filesystem>
#include <vector>
#include <string>
#include <iostream>
#include <assert.h>
/* 13-07-2023
* This is my FileDirectoryHandler class, this class creates,navigates and stores important file information. 
* The types of files that I want to create mainly are, Dogengine files. These files are mainly plain txt.
* 09-01-2023
* This class should be a singleton.
* 
* With using the std::filesystem library, it should be kept in mind with either being crossplatform for windows 
* or just for windows. I have no idea what that exactly looks like, but that means making sure, that your filedirectory properly traverses 
* the windows operating system file system. With no hiccups. Or it is essentially able to exist purely through C++ code.
* 
* 
* I think so of my functions should be removed, the ones that accept or return vectors. I think it is too much and not necessary because my this class
* doesn't need that many directories to be held in reference. 
* 
* There will be a directory to store engine metadata
* There will be a directory to save current scene game state 
*/

/* 12-01-2023
* 
*  Here is a good example to as why you need to use const char * in this case.Because you're theorically building a cross platform game engine. 
*  you can't really use the standard C++ library. Because in theory, whatever platform your code is running on might not have the C++ library standard 
*  library.
* 
*  Because C/C++ is a functional programming language at its core, it runs native to the hardware it is running on. That is why you use char *.
* 
*  just noting that I am still using the standard template library where it makes the most sense. I don't really plan on making this cross compatible
* I am just practicing becoming the real deal.
*/
namespace fs = std::filesystem; //typedef, name alias
	class DirectoryHandler{
	public:
		DirectoryHandler(DirectoryHandler& other) = delete;
		DirectoryHandler(const DirectoryHandler&) = delete;
		DirectoryHandler& operator =(DirectoryHandler& other) = delete;
		DirectoryHandler& operator=(const DirectoryHandler&) = delete;
		static DirectoryHandler* GetInstance();
		///Return current working, READ
		const char* GetCurrentPath();
		///Returns directories inside of current working directory, READ
		std::vector<std::string> GetDirectories();
		///Returns directory contents, READ
		std::vector<std::string> GetDirectoryContents();
		///VOID
		std::vector<std::string> GetIntialDirectories();
		///VOID
		std::vector<std::string> GetIntialFiles();
		///Set intials directories and or files
		void SetDirectory(const char* dp_);
		///Insert new directories/files to track in accordance to the originally set Directories
		void CreateDirectory(const char* dp_);
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
		bool operator = (const char* path_);
	private:
		DirectoryHandler();
		~DirectoryHandler();
		bool FileExceptionThrower(const char* path_);
		char* currentPath;
		const char* dogEngineSaveDirectoryP;
		const char* dogEngineGameSaveDirectoryP;
		static DirectoryHandler* instance;
		std::vector<const char*> currentFiles;
		std::vector<const char*> savedDirectories;
	};
#endif //FILEDIRECTORYHANDLER_H
