#include "FileDirectoryHandler.h"

FileDirectoryHandler::FileDirectoryHandler()
{
	currentPath = std::string();
}

FileDirectoryHandler::FileDirectoryHandler(std::string filePath_)
{
	currentPath = filePath_;
}

FileDirectoryHandler::~FileDirectoryHandler()
{
}
