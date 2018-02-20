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

	void setComboToFind(Combo);					// définit la combinaison de jeu à trouver

	int launch();								// lance la résolution automatique en fonction du mode et retourne le nombre de tentative restantes pour la victoire 

private:
	int mode;
	MindList *list;
	Game *game;
	int attempts;

	Result catchResult();						// l'utilisateur encode un résultat pour une combinaison
	Combo catchCombo();							// l'utilisateur définit la combinaison à trouver
	bool MindAI::validCombo(Combo _combo);		// vérifie la validité d'une combinaison encodée

	void playIt(Combo _combo);					// Lance un jeu avec la combinaison et diminue le nombre de tentatives

	void updateList();							// efface de la liste toutes les combinaisons incompatibles avec le résultat obtenu
	Result resultCompare(Combo) const;			// retourne le résultat d'une combinaison sur la combinaison tentée 

	Combo tryInitCombos();						// retourne la première occurence de la liste d'initialisation
	Combo tryCombo();							// retourne la première combinaison avec la priorité la plus élevée
};

#endif // !MINDAI_H