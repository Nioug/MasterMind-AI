#pragma once

/*
	LE JEU DU MASTERMIND :
	La classe "Game" travaille avec les classes "Combo" (qui contient une combinaison)
	et la classe "Result" qui donne le résultat d'une combinaison envoyée à la méthode
	play() comparée à celle générée aléatoirement par le constructeur de cette classe.
*/

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

#include "Combo.h"
#include "Result.h"

#define DEFAULT_TOKENS 4
#define DEFAULT_COLORS 8

using namespace std;

enum errors { TOKENS };
enum mode { AUTO, COMBO, RESULT };

class Game
{
private:
	int mode;									// mode de jeu { AUTO, COMBO, RESULT }
	int colors;									// nombre de couleurs différentes
	int tokens;									// nombre de jetons d'une combinaison

	Combo comboToFind;							// combinaison à trouver
	Combo comboToTry;							// combinaison à tenter
	Result comboRestult;						// résultat de cette combinaison

public:
	Game(int _mode = AUTO, int _colors = DEFAULT_COLORS, int _tokens = DEFAULT_TOKENS);

	int getTokens() const;						// retourne le nombre de jetons d'une combinaison du jeu
	int getColors() const;						// retourne le nombre de couleurs utilisées

	Result getResult() const;					// retourne le résultat généré par la méthode play()
	void setResult(Result);						// définit un résultat (multijoueur)

	void setComboToTry(Combo);					// recoit la combinaison à comparer à comboToFind
	Combo getTriedCombo() const;				// retourne la combinaison tentée
	void setcomboToFind(Combo);					// redéfinit la combinaison à trouver (multijoueur)
	
	Result play(Combo);							// définit un résultat en comparant comboToTry et comboToFind
	bool win() const;							// retourne "true" si la combinaison tentée est gagnante

	// TEST FUNCTIONS
	Combo getComboToFind() const;				// retourne la combinaison à trouver
};

#endif // !GAME_H
