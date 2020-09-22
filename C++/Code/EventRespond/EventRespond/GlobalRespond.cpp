#include <map>
#include "GlobalRespond.h"

struct GlobalRespondPrivate
{
	std::map<int, GLOBAL_CALLBACK> _EventCodeFunction;//EventCode,Function
};

GlobalRespond::GlobalRespond()
{
	_p = new GlobalRespondPrivate;
}

GlobalRespond::~GlobalRespond()
{
}

GlobalRespond * GlobalRespond::Instance()
{
	static GlobalRespond instance;
	return &instance;
}

void GlobalRespond::PostEvent(int EventCode, void *Param)
{
	std::map<int, GLOBAL_CALLBACK>::iterator it = _p->_EventCodeFunction.find(EventCode);
	if (it!=_p->_EventCodeFunction.end())
	{
		it->second(Param);
	}
}

void GlobalRespond::SubscribeEvent(int EventCode, GLOBAL_CALLBACK Function)
{
	_p->_EventCodeFunction[EventCode] = Function;
}

void GlobalRespond::UnSubscribeEvent(int EventCode)
{
	std::map<int, GLOBAL_CALLBACK>::iterator it = _p->_EventCodeFunction.find(EventCode);
	if (it!=_p->_EventCodeFunction.end())
	{
		_p->_EventCodeFunction.erase(it);
	}
}

