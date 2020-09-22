#include <map>
#include<vector>
#include "EventRespond.h"

struct RespondItem
{
	RespondItem(void *obj,const std::function<void(void*)> & func)
		:Receiver(obj),Function(func){}

	void *Receiver;
	std::function<void(void*)> Function;
};

struct EventRespondPrivate
{
	std::map<int, std::vector<RespondItem>> _EventCodeReceiverFunction;
};

EventRespond::EventRespond()
{
	_p = new EventRespondPrivate;
}


EventRespond::~EventRespond()
{
}

EventRespond * EventRespond::Instance()
{
	static EventRespond instance;
	return &instance;
}

void EventRespond::PostEvent(int EventCode, void *Param, void *Receiver /*= nullptr*/)
{
	std::map<int, std::vector<RespondItem>>::iterator it = _p->_EventCodeReceiverFunction.find(EventCode);
	if (it!=_p->_EventCodeReceiverFunction.end())
	{
		const std::vector<RespondItem> & eventHandles = it->second;
		if (Receiver!=nullptr)
		{
			for (std::size_t i=0;i<eventHandles.size();++i)
			{
				if (eventHandles[i].Receiver==Receiver)
				{
					eventHandles[i].Function(Param);
				}
			}
		}
		else
		{
			for (std::size_t i=0;i<eventHandles.size();++i)
			{
				eventHandles[i].Function(Param);
			}
		}
	}
}

void EventRespond::Subscibe(int EventCode, void *Receiver, const std::function<void(void*)>& Function)
{
	_p->_EventCodeReceiverFunction[EventCode].push_back(RespondItem(Receiver, Function));
}

void EventRespond::UnSubscribeEvent(int EventCode, void *Receiver /*= nullptr*/)
{
	std::map<int, std::vector<RespondItem>>::iterator it = _p->_EventCodeReceiverFunction.find(EventCode);
	if (it!=_p->_EventCodeReceiverFunction.end())
	{
		if (Receiver==nullptr)
		{
			it->second.clear();
			return;
		}
		
		std::vector<RespondItem> & eventHandles = it->second;
		for (std::vector<RespondItem>::iterator itRespond=eventHandles.begin();itRespond!=eventHandles.end();)
		{
			if (itRespond->Receiver==Receiver)
			{
				itRespond = eventHandles.erase(itRespond);
			}
			else
			{
				++itRespond;
			}
		}
	}
}

