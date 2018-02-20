#pragma once

#ifndef MINDAI_H
#define MIDAI_H

#include "MindList.h"
#include "Game.h"

#define DEFAULT_ATTEMPTS 10
#define MAX_PRIOR 5

#define DISABLED -1

class MindAI
{
public:
	MindAI(int mode = AUTO, int attempts = DEFAULT_ATTEMPTS, int colors = DEFAULT_COLORS, int tokens = DEFAULT_TOKENS);
	virtual ~MindAI();

	Game* getGame() const;						// retourne l'adresse de l'objet Game
	MindList* getList() const;					// retourne l'adresse de la liste

	void setComboToFind(Combo);					// d�finit la combinaison de jeu � trouver

	int launch();								// lance la r�solution automatique en fonction du mode et retourne le nombre de tentative restantes pour la victoire 

private:
	int mode;
	MindList *list;
	Game *game;
	int attempts;

	Result catchResult();						// l'utilisateur encode un r�sultat pour une combinaison
	Combo catchCombo();							// l'utilisateur d�finit la combinaison � trouver
	bool MindAI::validCombo(Combo _combo);		// v�rifie la validit� d'une combinaison encod�e

	void playIt(Combo _combo);					// Lance un jeu avec la combinaison et diminue le nombre de tentatives

	void updateList();							// efface de la liste toutes les combinaisons incompatibles avec le r�sultat obtenu
	Result resultCompare(Combo) const;			// retourne le r�sultat d'une combinaison sur la combinaison tent�e 

	Combo tryInitCombos();						// retourne la premi�re occurence de la liste d'initialisation
	Combo tryCombo();							// retourne la premi�re combinaison avec la priorit� la plus �lev�e
};

#endif // !MINDAI_H