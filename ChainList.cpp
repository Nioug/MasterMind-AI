#include "stdafx.h"

#include "ChainList.h"

ChainList::ChainList()
{
	start = new ChainElt();
	end = new ChainElt();

	start->prevElt = nullptr;
	start->nextElt = end;

	end->prevElt = start;
	start->nextElt = nullptr;
}


ChainList::~ChainList()
{
	delete start;
	delete end;
}


void ChainList::addElt(Position, const ChainElt eltToFind)
{
	ChainElt *ref = end;
	while (ref->prevElt != nullptr)
	{
		if (*ref == eltToFind)
		{

		}
	}
}


int ChainList::getSize() const
{
	return size;
}



ChainElt::ChainElt()
{

}


ChainElt::ChainElt(Position, ChainElt elt)
{

}