#pragma once

#include "MindList.h"
#include "Game.h"

#define DEFAULT_ATTEMPTS 10
#define MAX_PRIOR 5

#define DISABLED -1


class MindAI
{
public:
	MindAI(int attempts = DEFAULT_ATTEMPTS, int colors = DEFAULT_COLORS, int tokens = DEFAULT_TOKENS);

	Game getGame() const;
	MindList getList() const;

	Combo tryInitCombos();
	Combo tryCombo();

	bool play();
	Result resultCompare(Combo) const;
	void updateList();

private:
	MindList list;
	Game game;
	vector<Combo> playLog;
	vector<Result> resultLog;
	int attempts;

	int listSize;
	int removed;

	vector<int> removeList;
};