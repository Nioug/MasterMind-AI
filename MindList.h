#pragma once

using namespace std;

#include <vector>

#include "Combo.h"

#define DEFAULT_TOKENS 4
#define DEFAULT_COLORS 8

class MindList
{
public:
	MindList(int colors = DEFAULT_COLORS, int tokens = DEFAULT_TOKENS);

	void setTokens(int);
	void setColors(int);
	int getTokens() const;
	int getColors() const;

	void remove(Combo);

	void showList(vector<Combo>&) const;

private:
	int tokens;
	int colors;
	vector<Combo> list;
	vector<Combo> init;
	
	void listFill(vector<int>);
};
