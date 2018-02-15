#include "stdafx.h"

#include "MindList.h"
#include <cmath>
#include <iostream>


/*
	CONSTRUCTEUR DE LISTE
*/
MindList::MindList(int _colors, int _tokens)
{
	// AFFECTATION DES VARIABLES
	colors = _colors;
	tokens = _tokens;

	cerr << "colors : " << colors << endl;
	cerr << "tokens : " << tokens << endl;


	// INITIALISATION DES VARIABLES
	vector<int> fill(tokens, 1);
	bool filling = true;
	

	// REMPLISSAGE AUTOMATIQUE DE LA LISTE
	while (filling)
	{
		listFill(fill);

		for (int iT = 1; iT < tokens; iT++)
		{
			if (fill[iT] < colors)
			{
				fill[iT] += 1;
				break;
			}
			else
			{
				fill[iT] = 1;
				if (iT == tokens - 1)
					filling = false;
			}
		}
	}


	// VECTOR D'INITILISATION 
	for (int i = 0; i < tokens; i+=2)
	{
		vector<int> temp;
		temp.push_back(i);
		temp.push_back(i);
		temp.push_back(i + 1);
		temp.push_back(i + 1);
		init.push_back(temp);
	}
}



/*
	REMPLISSAGE DE LA LISTE
*/
void MindList::listFill(vector<int> status)
{
	vector<int> temp(tokens);									// vector temporaire

	for (int iColor = 1; iColor <= colors; iColor++)
	{
		temp[0] = iColor;

		for (int iToken = 1; iToken < tokens; iToken++)
		{
			temp[iToken] = status[iToken];
		}		

		Combo addCombo(temp);
		list.push_back(addCombo);
	}
}



/*
GETTERS & SETTERS
*/
void MindList::setTokens(int _tokens) { tokens = _tokens; }
void MindList::setColors(int _colors) { colors = _colors; }

int MindList::getTokens() const { return tokens; }
int MindList::getColors() const { return colors; }



/*
	SUPPRIMER UNE COMBINAISON DE LA LISTE
*/
void MindList::remove(Combo ref)
{
	// INITIALISATION DES VARIABLES
	bool sameCombo = false;
	int iToRemove = 0;


	// RECHERCHE DE L'ID DE LA COMBINAISON
	for (iToRemove = 0; iToRemove < list.size(); iToRemove++)
	{
		if (list[iToRemove] == ref)
		{
			sameCombo = true;
			break;
		}
	}


	// SUPPRESSION DE LA COMBINAISON
	if (sameCombo)
	{
		list.erase(list.begin() + iToRemove);
		cerr << "// #" << iToRemove << " removed" << endl;
	}
	else
	{
		cerr << "// combo not found" << endl;
	}	
}



/*
	AFFICHE LA LISTE COMPLETE
*/
void MindList::showList(vector<Combo> &vect) const
{
	for (int iCombo = 0; iCombo < vect.size(); iCombo++)
	{
		cout << iCombo << ":\t" << vect[iCombo] << endl;
	}
}