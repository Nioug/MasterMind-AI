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

Result::Result(int _result[SIZE])
{
	result[GOOD] = _result[GOOD];
	result[BAD] = _result[BAD];
}




/*
	GETTERS
*/
int Result::getGoodPos() const		{ return result[GOOD];	}
int Result::getBadPos() const		{ return result[BAD];	}



/*
	SETTERS
*/
void Result::setGood(int goodPos)	{ result[GOOD] = goodPos;	}
void Result::setBad(int badPos)		{ result[BAD] = badPos;		}

void Result::setResult(int _result[SIZE])
{
	result[GOOD] = _result[GOOD];
	result[BAD] = _result[BAD];
}

void Result::setResult(int _good, int _bad)
{
	result[GOOD] = _good;
	result[BAD] = _bad;
}




/*
	SURCHARGE DES OPERATEURS
*/
Result::operator int()
{
	return getGoodPos() + getBadPos();
}


ostream& operator<<(ostream& out, Result r)
{
	return out << "V: " << r.getGoodPos() << " - X: " << r.getBadPos();
}


bool operator==(const Result &r1, const Result &r2)
{
	if (r1.getBadPos() == r2.getBadPos() && r1.getGoodPos() == r2.getGoodPos())
		return true;
	else
		return false;
}


bool operator!=(const Result &r1, const Result &r2)
{
	return !(r1 == r2);
}