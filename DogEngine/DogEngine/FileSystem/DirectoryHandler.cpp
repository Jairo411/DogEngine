#include "DirectoryHandler.h"

DGEngine::DirectoryHandler::DirectoryHandler()
{
	currentPath = std::string();
	files = std::vector<std::string>();
}

DGEngine::DirectoryHandler::DirectoryHandler(std::string directoryPath_)
{
	currentPath = directoryPath_;
}

DGEngine::DirectoryHandler::~DirectoryHandler()
{
}

std::string DGEngine::DirectoryHandler::GetCurrentPath()
{
	return currentPath;
}

std::vector<std::string> DGEngine::DirectoryHandler::GetDirectories()
{
	std::vector<std::string> directories;
	for (const auto& entry : fs::directory_iterator(currentPath.c_str()))
	{
		std::string filenameStr = entry.path().filename().string();
		if (entry.is_directory())
		{
			directories.push_back(filenameStr);
		}
	}
	return directories;
}

std::vector<std::string> DGEngine::DirectoryHandler::GetDirectoryContents()
{
	std::vector<std::string> contents;
	for (const auto& entry : fs::directory_iterator(currentPath.c_str()))
	{
		std::string filenameStr = entry.path().filename().string();
		if (entry.is_regular_file()) // files
		{
			contents.push_back(filenameStr);
		}
	}
	return contents;
}

void DGEngine::DirectoryHandler::SetDirectory(const char* dp_)
{
	directories.push_back(dp_);
}

void DGEngine::DirectoryHandler::SetDirectory(const std::vector<std::string> dp_)
{
	directories = dp_;
}

void DGEngine::DirectoryHandler::SetDirectory(const std::vector<std::string> dp_, const std::vector<std::string> fp_)
{
	directories = dp_;
	files = fp_;
}


void DGEngine::DirectoryHandler::PrintDirectoryContents()
{
	for (const auto& entry: fs::directory_iterator(currentPath.c_str()))
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

void DGEngine::DirectoryHandler::PrintDirectoryPath()
{
	const auto& entry = fs::directory_entry(currentPath.c_str());
	std::cout << "Dir: " << entry.path().string();
}


void DGEngine::DirectoryHandler::CreateDirectory(std::string fulldirectoryPath_)
{
	fs::path directory; 
	directory = fulldirectoryPath_;
	fs::create_directory(directory);
}

void DGEngine::DirectoryHandler::Update()
{
}

bool DGEngine::DirectoryHandler::operator==(const char* directoryPath_)
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

bool DGEngine::DirectoryHandler::operator==(std::vector<std::string> directories_)
{
	return false;
}

bool DGEngine::DirectoryHandler::operator!=(const char* directoryPath_)
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

bool DGEngine::DirectoryHandler::operator!=(std::vector<std::string> directories_)
{
	return false;
}

bool DGEngine::DirectoryHandler::operator=(std::string path_)
{
	if (fs::exists(path_))
	{
		currentPath = path_;
		std::cout << "Moved to " << currentPath.c_str() << std::endl;
	}
	return false;
}

bool DGEngine::DirectoryHandler::FileExceptionThrower(const char* path_)
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