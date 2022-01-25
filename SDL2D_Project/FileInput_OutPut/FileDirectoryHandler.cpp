#include "FileDirectoryHandler.h"

FileDirectoryHandler::FileDirectoryHandler()
{
	currentPath = std::string();
}

FileDirectoryHandler::FileDirectoryHandler(std::string directoryPath_)
{
	currentPath = directoryPath_;
}

FileDirectoryHandler::~FileDirectoryHandler()
{
}

std::string FileDirectoryHandler::GetCurrentPath()
{
	return currentPath;
}

std::vector<std::string> FileDirectoryHandler::GetDirectories()
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

std::vector<std::string> FileDirectoryHandler::GetDirectoryContents()
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

std::vector<std::string> FileDirectoryHandler::GetIntialDirectories()
{
	return default_directories;
}

std::vector<std::string> FileDirectoryHandler::GetIntialFiles()
{
	return default_files;
}

void FileDirectoryHandler::SetDefaults(std::vector<std::string>intial_directories_)
{
	default_directories = intial_directories_;
}

void FileDirectoryHandler::SetDefaults(std::vector<std::string> intial_directories_, std::vector<std::string> intial_files_)
{
	default_directories = intial_directories_;
	default_files = intial_files_;
}


void FileDirectoryHandler::PrintDirectoryContents()
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

void FileDirectoryHandler::PrintDirectoryPath()
{
	const auto& entry = fs::directory_entry(currentPath.c_str());
	std::cout << "Dir: " << entry.path().string();
}


void FileDirectoryHandler::CreateDirectory(std::string fulldirectoryPath_)
{
	fs::path directory; 
	directory = fulldirectoryPath_;
	fs::create_directory(directory);
}

void FileDirectoryHandler::Update()
{
}

bool FileDirectoryHandler::operator==(const char* directoryPath_)
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

bool FileDirectoryHandler::operator==(std::vector<std::string> directories_)
{
	return false;
}

bool FileDirectoryHandler::operator!=(const char* directoryPath_)
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

bool FileDirectoryHandler::operator!=(std::vector<std::string> directories_)
{
	return false;
}

bool FileDirectoryHandler::operator=(std::string path_)
{
	if (fs::exists(path_))
	{
		currentPath = path_;
		std::cout << "Moved to " << currentPath.c_str() << std::endl;
	}
	return false;
}
