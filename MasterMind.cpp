// MasterMind.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "MindAI.h"
#include "Game.h"

using namespace std;

int main()
{
	time_t t1 = time(NULL);

	MindAI test;
	cerr << "(" << test.getGame().getComboToFind() << ")" << endl;

	/* jeu */
	if (test.play())
		cout << endl << "\t YOU WIN" << endl << endl;
	else
		cout << endl << "\t YOU LOOSE" << endl << endl;

	time_t t2 = time(NULL);
	time_t result = t2 - t1;

	cout << result << " secondes" << endl;

    return 0;
}

