#ifndef __PROMOTE_EVENT_H_
#define __PROMOTE_EVENT_H_

#include "Events/Event.h"


//class for the Promotion event
class PromoteEvent : public Event
{
	//info about the order ralted to Promotion event
	ORD_TYPE OrdType;		// order type: Normal, vegan, VIP //  	                
	double ExMony;	//Total order money
public:
	PromoteEvent(int eTime, int oID, ORD_TYPE oType);
	PromoteEvent(int eTime, int oID,int ExM, ORD_TYPE oType=TYPE_NRM);
	//Add more constructors if needed

	virtual void Execute(Restaurant* pRest);	//override execute function

};

#endif