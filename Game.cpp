#pragma once
#include "stdafx.h"

#include "Game.h"


/*
	Constructeur
*/
Game::Game(int _mode, int _colors, int _tokens)
{
	mode = _mode;
	colors = _colors;
	tokens = _tokens;
	vector<int> temp(_tokens, 0);

	srand(time(nullptr)); // use current time as seed for random generator

	// COMPOSITION DE LA COMBINAISON AU HASARD
	for (int i = 0; i < _tokens; i++)
	{
		temp[i] = rand() % colors + 1;
	}
	comboToFind = temp;
}


int		Game::getTokens() const			{ return tokens;		}			// retourne le nombre de jetons d'une combinaison du jeu
int		Game::getColors() const			{ return colors;		}			// retourne le nombre de couleurs utilisées
Combo	Game::getTriedCombo() const		{ return comboToTry;	}			// retourne la combinaison tentée
Combo	Game::getComboToFind() const	{ return comboToFind;	}			// retourne la combinaison à trouver

Result	Game::getResult() const			{ return comboRestult;	}			// retourne le résultat généré par la méthode play()
void	Game::setResult(Result r)		{ comboRestult = r;		}			// définit un résultat (multijoueur)

void	Game::setComboToTry(Combo c)	{ comboToTry = Combo(c); }			// recoit la combinaison à comparer à comboToFind
void	Game::setcomboToFind(Combo c)	{ comboToFind = Combo(c); }			// redéfinit la combinaison à trouver (multijoueur)



/* 
	Calcule un résultat en comparant comboToTry et comboToFind 
*/
Result Game::play(Combo _combo)
{
	if (_combo.getSize() != tokens)
	{
		throw TOKENS;
		comboRestult = Result(0, 0);
		return comboRestult;
	}		

	comboToTry = _combo;

	vector<bool> lockGood(tokens, false);
	vector<bool> lockBad(tokens, false);
	int goodPos = 0;
	int badPos = 0;

	for (int i = 0; i < tokens; ++i)
	{
		if (_combo[i] == comboToFind[i])
		{
			//cerr << "position V locked " << i << endl;
			lockGood[i] = true;
			goodPos++;
		}
	}

	for (int iC = 0; iC < tokens; ++iC)
	{
		for (int iTF = 0; iTF < tokens; ++iTF)
		{
			if (lockGood[iTF] == false && lockGood[iC] == false && lockBad[iTF] == false && iC != iTF && comboToFind[iTF] == _combo[iC])
			{
				//cerr << "position X locked " << iC << " > " << iTF << endl;
				lockBad[iTF] = true;
				badPos++;
				break;
			}
		}
	}
	
	comboRestult = Result(goodPos, badPos);
	return comboRestult;
}



/*
	retourne "true" si la combinaison tentée est gagnante
*/
bool Game::win() const
{
	if (comboRestult.getGoodPos() == tokens)
		return true;
	else
		return false;
}