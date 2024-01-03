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
*/
namespace fs = std::filesystem; //typedef, name alias
namespace DGEngine::core {
	class DirectoryHandler
	{
	public:
		DirectoryHandler(DirectoryHandler& other) = delete;
		DirectoryHandler(const DirectoryHandler&) = delete;
		DirectoryHandler& operator =(DirectoryHandler& other) = delete;
		DirectoryHandler& operator=(const DirectoryHandler&) = delete;
		///Will construct a FileDirectoryHandler with no idea in which directory it is currently working in
		DirectoryHandler();
		///Will properly construct a FileDirectoryHandler with a CWD 
		DirectoryHandler(std::string directoryPath_);
		~DirectoryHandler();
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
		///Set intials directories and or files
		void SetDirectory(const char* dp_);
		void SetDirectory(const char* dp_, const char* fp_);
		void SetDirectory(const std::vector<std::string> dp_);
		void SetDirectory(const std::vector<std::string> dp_, const std::vector<std::string> fp_);
		///Insert new directories/files to track in accordance to the originally set Directories
		void InsertDirectory(const char* dp_);
		void InsertDirectory(const char* dp_, const char* fp_);
		void InsertDirectory(const std::vector<std::string> dp_);
		void InsertDirectory(const std::vector<std::string> dp_, const std::vector<std::string> fp_);
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
		bool FileExceptionThrower(const char* path_);


		std::string currentPath;
		std::vector<std::string> files;
		std::vector<std::string> directories;
	};
}
#endif //FILEDIRECTORYHANDLER_H