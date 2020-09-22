#ifndef __EventRespond_H__
#define __EventRespond_H__

#include<functional>

struct EventRespondPrivate;

class EventRespond
{
public:
	static EventRespond *Instance();

public:
	void PostEvent(int EventCode, void *Param, void *Receiver = nullptr);

	template<typename ClassType, typename FuncType>
	void SubscribeEvent(int EventCode, ClassType Receiver, FuncType Function);

	void UnSubscribeEvent(int EventCode, void *Receiver = nullptr);

private:
	void Subscibe(int EventCode, void *Receiver, const std::function<void(void*)>& Function);

private:
	EventRespond();
	~EventRespond();

	EventRespondPrivate *_p;
};

template<typename ClassType, typename FuncType>
void EventRespond::SubscribeEvent(int EventCode, ClassType Receiver, FuncType Function)
{
	Subscibe(EventCode, Receive, std::bind(Function, Receiver, std::placeholders::_1));
}

#endif // __EventRespond_H__


