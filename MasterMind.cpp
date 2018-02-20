// MasterMind.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "MindAI.h"
#include "Game.h"

using namespace std;

int main()
{
	/* jeu */
	for (size_t i = 0; i < 5; ++i)
	{
		cout << endl << "\t MASTERMIND RESOLTUTION" << endl;

		MindAI test(AUTO);
		test.launch();
		cout << "  >> " << test.getGame()->getComboToFind() << endl;
	}

    return 0;
}

