#pragma once

struct GlobalRespondPrivate;
typedef void(*GLOBAL_CALLBACK)(void *pData);

class __declspec(dllexport) GlobalRespond
{
public:
	static GlobalRespond *Instance();

	void PostEvent(int EventCode, void *Param);
	void SubscribeEvent(int EventCode, GLOBAL_CALLBACK Function);
	void UnSubscribeEvent(int EventCode);

private:
	GlobalRespond();
	~GlobalRespond();

	GlobalRespondPrivate *_p;
};

