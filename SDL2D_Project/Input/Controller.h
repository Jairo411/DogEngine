#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../EventSystem/Event.h"
typedef std::pair<bool, float> inputVals;

enum class PLAYSTATION_MAPPINGS
{
	T_BUTTON = false,
	C_BUTTON,
	X_BUTTON,
	S_BUTTON,
	OPTIONS,
	SHARE,
	R1,
	R2,
	L1,
	L2,
	TOPDIR,
	RIGHTDIR,
	BOTTOMDIR,
	LEFTDIR,
	RIGHTANALOG,
	LEFTANALOG,
};

enum class XBOX_MAPPINGS
{
	Y_BUTTON = false,
	X_BUTTON,
	B_BUTTON,
	A_BUTTON,
	RB_BUTTON,
	RT_BUTTON,
	LB_BUTTON,
	LT_BUTTON,
	TOPDIR,
	RIGHTDIR,
	BOTTOMDIR,
	LEFTDIR,
	RIGHTANALOG,
	LEFTANALOG,
};
class Controller : public EventListener
{
public:
	Controller();
	~Controller();
	virtual void OnCreate()=0;
	virtual void OnDestroy() =0;
	virtual void HandleEvents()=0;
protected:
	bool click;
	float L_Analog;
	float R_Analog;
};


class PS4Controller : public Controller
{
public:
	PS4Controller();
	~PS4Controller();
	virtual void OnCreate() final;
	virtual void OnDestroy() final;
	virtual void HandleEvents() final;
	std::map<PLAYSTATION_MAPPINGS, inputVals> GetInput();
private:
	std::map<PLAYSTATION_MAPPINGS, inputVals> controllermap;
};

class XBOXController : public Controller
{
public:
	XBOXController();
	~XBOXController();
	virtual void OnCreate() final;
	virtual void OnDestroy() final;
	virtual void HandleEvents() final;
	std::map<XBOX_MAPPINGS, inputVals> GetInput();
private:
	std::map<XBOX_MAPPINGS, inputVals> controllermap;
};

#endif // !CONTROLLER_H