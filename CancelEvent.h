#ifndef __CANCEL_EVENT_H_
#define __CANCEL_EVENT_H_

#include "Events/Event.h"


//class for the Cancel event
class CancelEvent : public Event
{
	
public:
	CancelEvent(int eTime, int oID);

	virtual void Execute(Restaurant* pRest);	//override execute function

};

#endif
