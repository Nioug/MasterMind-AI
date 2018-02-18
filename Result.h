#pragma once

//
// class Result stocke le résultat d'une combinaison de MasterMind
// elle indique la quantité de pions correctement et incorrectement placés
//

#include <iostream>
using namespace std;

enum pos {GOOD, BAD, NONE};

class Result
{
public:
	Result(int goodPos = 0, int badPos = 0);
	Result(int result[2]);

	int getGoodPos() const;
	int getBadPos() const;

	void setGood(int goodPos);
	void setBad(int badPos);
	void setResult(int result[]);

	operator int();

private:
	int result[2];
};


ostream& operator<<(ostream&, Result);
bool operator==(const Result &r1, const Result &r2);
bool operator!=(const Result &r1, const Result &r2);
