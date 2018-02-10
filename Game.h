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

	vector<int> comboToFind;

public:
	Game(int _colors = DEFAULT_COLORS, int _tokens = DEFAULT_TOKENS);

	int getTokens() const;
	int getColors() const;

	Result play(Combo);

	// TEST FUNCTIONS
	vector<int> getComboToFind() const;

};