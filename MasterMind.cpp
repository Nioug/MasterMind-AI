// MasterMind.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

#include "MindList.h"
#include "Game.h"

using namespace std;

int main()
{
	Game jeu;
	Combo combinaison;
	int attempts = 0;

	//cerr << "(" << jeu.getComboToFind() << ")" << endl;

	do
	{
		cout << "jeu " << ++attempts << "/10 : ";

		cin >> combinaison;

		try
		{
			jeu.play(combinaison);
		}
		catch (errors err)
		{
			if (err == TOKENS)
			{
				cout << "// erreur: il faut " << jeu.getTokens() << " jetons" << endl;
				cout << "// faites gaffe ESPECE DE BOURRIN..." << endl;
			}
		}

		cout << jeu.getResult() << endl << endl;
	} while (!jeu.win() && attempts <= 10);

	if (jeu.win())
		cout << "Victoire, vous êtes un maître !" << endl;
	else
		cout << "Vous aurez plus de chances la prochaine fois..." << endl;

	cout << endl << "Combinaison gagnante >> " << jeu.getComboToFind() << endl;

    return 0;
}

