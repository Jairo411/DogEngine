#include "DirectoryHandler.h"

DirectoryHandler* DirectoryHandler::instance = nullptr;


DirectoryHandler* DirectoryHandler::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new DirectoryHandler();
	}
	return instance;
}

DirectoryHandler::DirectoryHandler()
{
	currentPath = nullptr;
	currentFiles = std::vector<const char*>();
	savedDirectories = std::vector<const char*>();

	std::string fileP = __FILE__;
	
	assert(FileExceptionThrower == false);

	for (auto it = fileP.begin(); it < fileP.end(); it++)
	{
		if (*it=='/')
		{
			//read directory name
		}
	}

	/* 
	* 1. Loop the iterator and delete all characters till you reach ./DogEngine 
	*  the reason you do this, is because you want your game engine to be able to be set up on any computer. 
	*  because it will take the full path from where your DirectoryHandler.cpp file is and then get to where the dog engine folder 
	*  is.
	* 2. Once you've reach this directory path, create two folders DogEngineSaveDirectory and DogEngineGameSaveDirectory
	* 
	*	DogEngineSaveDirectory will be created, ./DogEngine/DogEngine/dogEngineSaveDirectory 
	*	DogEngineGameSaveDirectory will be created ./DogEngine/DogEnginePlayground
	* 3. 
	*/


	
}


DirectoryHandler::~DirectoryHandler()
{
}

const char * DirectoryHandler::GetCurrentPath()
{
	return currentPath;
}

std::vector<std::string> DirectoryHandler::GetDirectories()
{
	std::vector<std::string> directories;
	for (const auto& entry : fs::directory_iterator(currentPath))
	{
		std::string filenameStr = entry.path().filename().string();
		if (entry.is_directory())
		{
			directories.push_back(filenameStr);
		}
	}
	return directories;
}

std::vector<std::string> DirectoryHandler::GetDirectoryContents()
{
	std::vector<std::string> contents;
	for (const auto& entry : fs::directory_iterator(currentPath))
	{
		std::string filenameStr = entry.path().filename().string();
		if (entry.is_regular_file()) // files
		{
			contents.push_back(filenameStr);
		}
	}
	return contents;
}

void DirectoryHandler::SetDirectory(const char* dp_)
{
	currentPath = dp_;
}



void DirectoryHandler::PrintDirectoryContents()
{
	for (const auto& entry: fs::directory_iterator(currentPath))
	{
		std::string filenameStr = entry.path().filename().string();
		if (entry.is_directory())
		{
			std::cout << "Dir: " << filenameStr << std::endl;
		}
		else if (entry.is_regular_file())
		{
			std::cout << "file: " << filenameStr << std::endl;
		}
		else
		{
			std::cout << "?? " << filenameStr << std::endl;
		}
	}
}

void DirectoryHandler::PrintDirectoryPath()
{
	const auto& entry = fs::directory_entry(currentPath);
	std::cout << "Dir: " << entry.path().string();
}


void DirectoryHandler::CreateDirectory(std::string fulldirectoryPath_)
{
	fs::path directory; 
	directory = fulldirectoryPath_;
	fs::create_directory(directory);
}

void DirectoryHandler::Update()
{
}

bool DirectoryHandler::operator==(const char* directoryPath_)
{
	if (fs::exists(directoryPath_) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool DirectoryHandler::operator==(std::vector<std::string> directories_)
{
	return false;
}

bool DirectoryHandler::operator!=(const char* directoryPath_)
{
	if (fs::exists(directoryPath_) == false)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool DirectoryHandler::operator!=(std::vector<std::string> directories_)
{
	return false;
}

bool DirectoryHandler::operator=(const char* path_)
{
	if (fs::exists(path_))
	{
		currentPath = path_;
		std::cout << "Moved to " << currentPath << std::endl;
	}
	return false;
}

bool DirectoryHandler::FileExceptionThrower(const char* path_)
{
	std::string s = path_;
	std::string::iterator it = std::string::iterator();
	int length = strlen(s.c_str());
	it = s.end() - 1;


	std::cout << "Current size of const char * path" << length << std::endl;

	for (int i = 0; i < i - 1 < length; it--)
	{
		if (*it == '.')
		{
			std::string errpath = __FILE__;
			throw std::invalid_argument("In " + errpath + " gave invalid string input");
		}
		else if (*it == '/')
		{
			return true;
		}
		else if (it == s.begin())
		{
			std::string errpath = __FILE__;
			throw std::invalid_argument("In " + errpath + " gave invalid string input");
		}
		it++;
	}
}
