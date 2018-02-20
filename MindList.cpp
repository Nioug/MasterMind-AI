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
	allCombos = new vector<Combo>;
	initCombos = new vector<Combo>;
	colors = _colors;
	tokens = _tokens;


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

	maxSize = allCombos->size();
	rejected = 0;


	// VECTOR D'INITILISATION 
	for (int i = 0; i < colors; i += 2)
	{
		vector<int> temp;
		temp.push_back(i + 1);
		temp.push_back(i + 1);
		temp.push_back(i + 2);
		temp.push_back(i + 2);

		initCombos->push_back(temp);
	}
}


/* DESTRUCTEUR */
MindList::~MindList()
{
	delete allCombos;
	delete initCombos;
}



/***** 
	DEFINIT LA PRIORITE D'UNE COMBINAISON 
*****/
int MindList::setPriority(Combo _combo)
{
	if (tokens != 4)
		return -1;
	else
	{
		int prior = 0;
		vector<int> colorArray(colors + 1, 0);
		for (int i = 0; i < tokens; i++)		// POUR CHAQUE JETON 
		{
			colorArray[_combo[i]] += 1;			// ON INCREMENTE LA VALEUR A SA POSITION DANS colorArray<int>
		}

		for (auto elt : colorArray)				// POUR CHAQUE QUANTITE DE COULEUR
		{
			if (elt == 1)
				prior += 1;
			else if (elt == 3)
				prior += 2;
			else if (elt == 4)
				prior += 4;
		}
		
		return prior;
	}
}



/***** 
	REMPLISSAGE DE LA LISTE 
*****/
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
		addCombo.setPriority(setPriority(addCombo));
		allCombos->push_back(addCombo);
	}
}



/*
GETTERS
*/
int MindList::getTokens() const { return tokens; }
int MindList::getColors() const { return colors; }

vector<Combo>* MindList::getAllCombos() const	{ return allCombos; }
vector<Combo>* MindList::getInitCombos() const	{ return initCombos; }

int MindList::getActualSize()
{
	return maxSize - rejected;
}


/*
	SUPPRIMER UNE COMBINAISON DE LA LISTE
*/
int MindList::remove(Combo _combo)
{
	// INITIALISATION DES VARIABLES
	bool sameCombo = false;
	int iToRemove = 0;


	// RECHERCHE DE L'ID DE LA COMBINAISON

	for (iToRemove = 0; iToRemove < allCombos->size(); iToRemove++)
	{
		if ((*allCombos)[iToRemove] == _combo)
		{
			sameCombo = true;
			break;
		}
	}


	// SUPPRESSION DE LA COMBINAISON
	if (sameCombo)
	{
		allCombos->erase(allCombos->begin() + iToRemove);
		/**/
		if (allCombos->size() % (int(maxSize / 100 + 1)) == 0)
			cerr << "|";
	}
	else
	{
		cerr << "// combo not found" << endl;
		iToRemove = -1;
	}	

	return iToRemove;
}


void MindList::removeAt(int i)
{
	allCombos->erase(allCombos->begin() + i);
}



void MindList::switchBack(int i)
{
	Combo temp = (*allCombos)[i];
	allCombos[i] = allCombos[maxSize - rejected - 1];
	(*allCombos)[maxSize - rejected - 1] = temp;
	rejected++;
}



void MindList::popFrontInit()
{
	initCombos->erase(initCombos->begin());
}



/*
	AFFICHE LA LISTE COMPLETE
*/
void MindList::show(vector<Combo> &vect) const
{
	for (int iCombo = 0; iCombo < vect.size(); iCombo++)
	{
		cout << iCombo << ":\t" << vect[iCombo] << endl;
	}
}

/*
AFFICHE LA LISTE COMPLETE
*/
void MindList::showListWP() const
{
	for (int iCombo = 0; iCombo < allCombos->size(); iCombo++)
	{
		cout << iCombo << ":\t" << (*allCombos)[iCombo] << " = " << (*allCombos)[iCombo].getPriority() << endl;
	}
}