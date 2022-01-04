#include "GenericContainer.h"

GenericContainer::GenericContainer()
{
    containerSize = 0;
    container = std::list<void*>();
    typeNames = std::list<std::string>();
}

GenericContainer::~GenericContainer()
{
    container.empty();
    typeNames.empty();
}

void GenericContainer::RemoveFront()
{
    container.pop_front();
    typeNames.pop_front();
}

void GenericContainer::Remove(void* type_)
{
    container.remove(type_);
}

void GenericContainer::RemoveBack()
{
    container.pop_back();
    typeNames.pop_back();
}

std::vector<std::string> GenericContainer::get_all_types()
{
    return std::vector<std::string>();
}

std::string GenericContainer::get_type(const int index)
{
    return std::string();
}

size_t GenericContainer::size()
{
    return size_t();
}
