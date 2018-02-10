#pragma once
#include "stdafx.h"

#include "Game.h"

Game::Game(int _colors, int _tokens)
{
	colors = _colors;
	tokens = _tokens;

	srand(time(nullptr)); // use current time as seed for random generator

	// COMPOSITION DE LA COMBINAISON AU HASARD
	for (int i = 0; i < _tokens; i++)
	{
		comboToFind.push_back(rand() % colors + 1);
	}
}


int Game::getTokens() const		{ return tokens; }
int Game::getColors() const		{ return colors; }


vector<int> Game::getComboToFind() const
{
	return comboToFind;
}


Result Game::play(Combo _combo)
{
	if (_combo.getSize() != tokens)
	{
		throw TOKENS;
		return Result(0, 0);
	}		

	vector<bool> lockGood(tokens, false);
	vector<bool> lockBad(tokens, false);
	int goodPos = 0;
	int badPos = 0;

	for (int i = 0; i < tokens; ++i)
	{
		if (_combo[i] == comboToFind[i])
		{
			//cerr << "position V locked " << i << endl;
			lockGood[i] = true;
			goodPos++;
		}
	}

	for (int iC = 0; iC < tokens; ++iC)
	{
		for (int iTF = 0; iTF < tokens; ++iTF)
		{
			if (lockGood[iTF] == false && lockGood[iC] == false && lockBad[iTF] == false && iC != iTF && comboToFind[iTF] == _combo[iC])
			{
				//cerr << "position X locked " << iC << " > " << iTF << endl;
				lockBad[iTF] = true;
				badPos++;
				break;
			}
		}
	}

	return Result(goodPos, badPos);
}
