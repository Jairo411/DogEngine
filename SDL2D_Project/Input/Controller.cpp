#include "Controller.h"

PS4Controller::PS4Controller() : controllermap(std::map<PLAYSTATION_MAPPINGS, inputVals>())
{
}

PS4Controller::~PS4Controller()
{
}

void PS4Controller::OnCreate()
{
}

void PS4Controller::OnDestroy()
{
}

void PS4Controller::HandleEvents()
{
	switch (eventInfo->event_->type)
	{
	case SDL_CONTROLLERAXISMOTION:

		break;
	case SDL_CONTROLLERBUTTONDOWN:

		break;

	case SDL_CONTROLLERBUTTONUP:

		break;

	case SDL_CONTROLLERDEVICEADDED:

		break;
	case SDL_CONTROLLERDEVICEREMOVED:

		break;
	default:
		break;
	}
}

std::map<PLAYSTATION_MAPPINGS, inputVals> PS4Controller::GetInput()
{
	return controllermap;
}

XBOXController::XBOXController() : controllermap(std::map<XBOX_MAPPINGS,inputVals>())
{
	switch (eventInfo->event_->type)
	{
	case SDL_CONTROLLERAXISMOTION:

		break;
	case SDL_CONTROLLERBUTTONDOWN:

		break;
	case SDL_CONTROLLERBUTTONUP:

		break;
	case SDL_CONTROLLERDEVICEADDED:

		break;
	case SDL_CONTROLLERDEVICEREMOVED:

		break;
	default:
		break;
	}
}

XBOXController::~XBOXController()
{
}

void XBOXController::OnCreate()
{
}

void XBOXController::OnDestroy()
{
}

void XBOXController::HandleEvents()
{
}

std::map<XBOX_MAPPINGS, inputVals> XBOXController::GetInput()
{
	return controllermap;
}
