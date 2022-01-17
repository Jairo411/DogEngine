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
	for (const auto& entry : std::filesystem::directory_iterator(currentPath.c_str()))
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
	for (const auto& entry : std::filesystem::directory_iterator(currentPath.c_str()))
	{
		std::string filenameStr = entry.path().filename().string();
		if (entry.is_regular_file()) // files
		{
			contents.push_back(filenameStr);
		}
	}
	return contents;
}

void FileDirectoryHandler::ChangeDirectory(std::string directoryPath_)
{
	currentPath = directoryPath_;
}

void FileDirectoryHandler::PrintDirectoryContents()
{
	for (const auto& entry: std::filesystem::directory_iterator(currentPath.c_str()))
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
	const auto& entry = std::filesystem::directory_entry(currentPath.c_str());
	std::cout << "Dir: " << entry.path().string();
}
