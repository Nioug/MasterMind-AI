#pragma once

/*
	LE JEU DU MASTERMIND :
	La classe "Game" travaille avec les classes "Combo" (qui contient une combinaison)
	et la classe "Result" qui donne le r�sultat d'une combinaison envoy�e � la m�thode
	play() compar�e � celle g�n�r�e al�atoirement par le constructeur de cette classe.
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
	int colors;									// nombre de couleurs diff�rentes
	int tokens;									// nombre de jetons d'une combinaison

	Combo comboToFind;							// combinaison � trouver
	Combo comboToTry;							// combinaison � tenter
	Result comboRestult;						// r�sultat de cette combinaison

public:
	Game(int _mode = AUTO, int _colors = DEFAULT_COLORS, int _tokens = DEFAULT_TOKENS);

	int getTokens() const;						// retourne le nombre de jetons d'une combinaison du jeu
	int getColors() const;						// retourne le nombre de couleurs utilis�es

	Result getResult() const;					// retourne le r�sultat g�n�r� par la m�thode play()
	void setResult(Result);						// d�finit un r�sultat (multijoueur)

	void setComboToTry(Combo);					// recoit la combinaison � comparer � comboToFind
	Combo getTriedCombo() const;				// retourne la combinaison tent�e
	void setcomboToFind(Combo);					// red�finit la combinaison � trouver (multijoueur)
	
	Result play(Combo);							// d�finit un r�sultat en comparant comboToTry et comboToFind
	bool win() const;							// retourne "true" si la combinaison tent�e est gagnante

	// TEST FUNCTIONS
	Combo getComboToFind() const;				// retourne la combinaison � trouver
};

#endif // !GAME_H
