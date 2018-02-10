#pragma once

enum Position
{
	FIRST, LAST, BEFORE, AFTER
};

class ChainList
{
public:
	ChainList();
	~ChainList();
	virtual void addElt(Position, const ChainElt);
	int getSize() const;
private:
	int size;
	ChainElt* start;
	ChainElt* end;
};


class ChainElt
{
public:
	ChainElt();
	ChainElt* nextElt;
	ChainElt* prevElt;
};