#include "PromoteEvent.h"
#include "Rest/Restaurant.h"


PromoteEvent::PromoteEvent(int eTime, int oID, ORD_TYPE oType) :Event(eTime, oID)
{
	OrdType = oType;
}

PromoteEvent::PromoteEvent(int eTime, int oID, int ExM, ORD_TYPE oType) : Event(eTime, oID)
{
	OrdType = oType;
	ExMony = ExM;
}


void PromoteEvent::Execute(Restaurant* pRest)
{
	int count;
	Order** orders = pRest->GetNormalWaiting().toArray(count);
	for (int i = 0; i < count; i++)
	{
		if (orders[i]->GetID() == OrderID)
		{
			orders[i]->settype(TYPE_VIP);
			orders[i]->setmoney(orders[i]->GetMoney() + ExMony);
			orders[i]->VIPPriorityEquation();
			pRest->GetVIPWaiting().enqueue(orders[i]);
			pRest->GetPromotedOrders().add(orders[i]->GetID());
		}
	}
}
