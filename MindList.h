#pragma once

#ifndef MINDLIST_H
#define MINDLIST_H

#include <vector>
#include "Combo.h"

#define DEFAULT_TOKENS 4
#define DEFAULT_COLORS 8

using namespace std;

class MindList
{
public:
	MindList(int colors = DEFAULT_COLORS, int tokens = DEFAULT_TOKENS);
	virtual ~MindList();

	int setPriority(Combo);

	int getTokens() const;
	int getColors() const;

	vector<Combo>* getAllCombos() const;
	vector<Combo>* getInitCombos() const;

	int getActualSize();

	int remove(Combo);
	void removeAt(int);
	void switchBack(int);
	void popFrontInit();

	void show(vector<Combo>&) const;
	void showListWP() const;

private:
	int tokens;
	int colors;
	vector<Combo> *allCombos;
	vector<Combo> *initCombos;

	int maxSize;
	int rejected;
	
	void listFill(vector<int>);
};

#endif // !MINDLIIST_H
