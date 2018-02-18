#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

#include "Combo.h"
#include "Result.h"

#define DEFAULT_TOKENS 4
#define DEFAULT_COLORS 8

using namespace std;

enum errors { TOKENS };

class Game
{
private:
	int colors;
	int tokens;

	Combo comboToFind;
	Combo comboToTry;
	Result comboRestult;

public:
	Game(int _colors = DEFAULT_COLORS, int _tokens = DEFAULT_TOKENS);

	int getTokens() const;
	int getColors() const;
	Combo getTriedCombo() const;
	Result getResult() const;

	void setComboToTry(Combo);
	void setcomboToFind(Combo);
	
	Result play(Combo);
	bool win() const;

	// TEST FUNCTIONS
	Combo getComboToFind() const;
};