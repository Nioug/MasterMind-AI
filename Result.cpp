#pragma once
#include "stdafx.h"

#include "Result.h"

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

int Result::getGoodPos() const
{
	return result[GOOD];
}

int Result::getBadPos() const
{
	return result[BAD];
}

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
