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
	Combo combinaison(jeu.getTokens());
	Result resultat;
	int attempts = 0;
	bool victory = false;

	//cerr << "(" << jeu.getComboToFind() << ")" << endl;

	do
	{
		cout << "jeu " << ++attempts << "/10 : ";

		cin >> combinaison;

		try
		{
			resultat = jeu.play(combinaison);
		}
		catch (errors type)
		{
			if (type == TOKENS)
			{
				cout << "// erreur de jeton" << endl;
				cout << "// faites gaffe espère de bourrin..." << endl;
			}
		}

		cout << "\t V: " << resultat.getGoodPos() << " - X: " << resultat.getBadPos() << endl << endl;
	} while (resultat.getGoodPos() != jeu.getTokens() && attempts <= 10);	

	if (victory)
		cout << "Victoire, vous êtes un maître !" << endl;

	cout << "Combinaison gagnante >> " << jeu.getComboToFind() << endl;

    return 0;
}

