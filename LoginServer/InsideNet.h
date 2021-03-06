#ifndef _INSIDE_NET_H_
#define _INSIDE_NET_H_


#include "LNet.h"
#include "LSingleton.h"

class InsideNet :public LNet, public LSingleton<InsideNet>
{
public:
	virtual bool Init();
	virtual bool Final();

	virtual void RecvMsgPack(LBuffPtr recv,LSocketPtr s, bool bIsFromInternal);
};

#define gInsideNet InsideNet::Instance()

//////////////////////////////////////////////////////////////////////////////////////
class OutsideNet :public LNet, public LSingleton<OutsideNet>
{
public:
	virtual bool Init();
	virtual bool Final();

	virtual void RecvMsgPack(LBuffPtr recv,LSocketPtr s, bool bIsFromInternal);
};

#define gOutsideNet OutsideNet::Instance()

#endif