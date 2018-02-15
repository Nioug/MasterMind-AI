#pragma once
#include "stdafx.h"

#include "Result.h"


//
// Constructeurs :
// le constructeur par défaut défini les résultats à 0
//
Result::Result(int goodPos, int badPos)
{
	result[GOOD] = goodPos;
	result[BAD] = badPos;
}

Result::Result(int _result[2])
{
	result[GOOD] = _result[GOOD];
	result[BAD] = _result[BAD];
}


//
// GETTERS
//
int Result::getGoodPos() const
{
	return result[GOOD];
}

int Result::getBadPos() const
{
	return result[BAD];
}


//
// SETTERS
//
void Result::setGood(int goodPos)
{
	result[GOOD] = goodPos;
}

void Result::setBad(int badPos)
{
	result[BAD] = badPos;
}

void Result::setResult(int _result[])
{
	result[GOOD] = _result[GOOD];
	result[BAD] = _result[BAD];
}



ostream& operator<<(ostream& out, Result r)
{
	return out << "V: " << r.getGoodPos() << " - X: " << r.getBadPos();
}