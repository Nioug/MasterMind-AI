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
	int setPriority(Combo);

	int getTokens() const;
	int getColors() const;

	vector<Combo> getAllCombos() const;
	vector<Combo> getInitCombos() const;

	int remove(Combo);
	void removeAt(int);
	void popFrontInit();

	void show(vector<Combo>&) const;
	void showList() const;

private:
	int tokens;
	int colors;
	vector<Combo> allCombos;
	vector<Combo> initCombos;

	int maxSize;
	
	void listFill(vector<int>);
};
