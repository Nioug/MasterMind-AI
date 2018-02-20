#include "stdafx.h"

#include "MindAI.h"


MindAI::MindAI(int _mode, int _attempts, int _colors, int _tokens)
{
	mode = _mode;
	list = new MindList(_colors, _tokens);
	game = new Game(_mode, _colors, _tokens);
	attempts = _attempts;
}


MindAI::~MindAI()
{
	delete list;
}


Game* MindAI::getGame() const
{
	return game;
}


MindList* MindAI::getList() const
{
	return list;
}


Combo MindAI::tryInitCombos()		
// retourne la preimière combinaison puis l'efface
{
	Combo temp = list->getInitCombos()->at(0);
	list->popFrontInit();
	return temp;
}


Combo MindAI::tryCombo()	
// retourne la combinaison suivante de la liste avec la priorité la plus faible
{
	int size = list->getAllCombos()->size();
	for (int iPrior = 0; iPrior < MAX_PRIOR; iPrior++)
	{
		if (iPrior == 1)
			continue;

		for (int iVect = 0; iVect < size; iVect++)
		{
			if (list->getAllCombos()->at(iVect).getPriority() == iPrior)
			{
				//cerr << " // selected : " << list->getAllCombos()->at(iVect) << " - P: " << list->getAllCombos()->at(iVect).getPriority() << endl;
				return list->getAllCombos()->at(iVect);
			}
		}
	}
	return NULL;
}


void MindAI::setComboToFind(Combo _combo)
{
	game->setcomboToFind(_combo);
}


int MindAI::launch()
// lance la résolution automatique en fonction du mode et retourne le nombre de tentative restantes pour la victoire
{
	/* INITIALISATION DES VARIABLES */
	int tokensFound = 0;
	int size = list->getInitCombos()->size();


	/* ENCODAGE DE LA COMBINAISON (MODE) */
	if (mode == COMBO)
		game->setcomboToFind(catchCombo());


	/* BOUCLE D'INITIALISATION */
	for (size_t i = 0; i < size; i++)
	{
		// INITIALISATION DE LA COMBINAISON
		Combo init = tryInitCombos();		


		// JEU AVEC CETTE COMBINAISON
		playIt(init);
		

		// CONDITION DE VICTOIRE
		if (game->win())
			return attempts;


		// MISE A JOUR DE LA LISTE DES COMBINAISONS POSSIBLES
		updateList();		


		// Si 4 jetons sont trouvés on quitte la boucle d'intitialisation
		tokensFound += int(game->getResult());
		if (tokensFound == game->getTokens())				
			break;
	}


	/* SUGGESTION DES COMBINAISONS EN FONCTION DE LEUR PRIORITE */
	while (attempts >= 0 && !game->win())
	{
		// INITIALISATION DE LA COMBINAISON
		Combo toTry = tryCombo();
		if (toTry == NULL)
		{
			cerr << "Error: no combo matches" << endl;
			return 0;
		}


		// JEU AVEC CETTE COMBINAISON
		playIt(toTry);


		// CONDITION DE VICTOIRE
		if (game->win())
			break;


		// MISE A JOUR DE LA LISTE DES COMBINAISONS POSSIBLES
		updateList();
	}

	return attempts;
}


void MindAI::playIt(Combo _combo)
// Lance un jeu avec la combinaison et diminue le nombre de tentatives
{
	game->play(_combo);
	cout << endl << "# " << 11 - attempts << ": " << _combo;

	if (mode == RESULT)
	{
		cout << endl;
		game->setResult(catchResult());
	}
	else
	{
		cout << " / " << game->getResult() << endl;		
	}
	attempts--;
}




Result MindAI::resultCompare(Combo comboToFind) const
// retourne le résultat d'une combinaison sur la combinaison tentée
{
	// INITIALISATION DES VARIABLES
	vector<bool> lockGood(game->getTokens(), false);
	vector<bool> lockBad(game->getTokens(), false);
	int goodPos = 0;
	int badPos = 0;
	int tokens = game->getTokens();



	// VERIFICATION DES PIONS BIEN MIS
	for (size_t i = 0; i < tokens; ++i)
	{
		if (game->getTriedCombo()[i] == comboToFind[i])
		{
			//cerr << "position V locked " << i << endl;
			lockGood[i] = true;
			goodPos++;
		}
	}



	// VERIFICATION DES PIONS MAL MIS
	for (size_t iC = 0; iC < tokens; ++iC)
	{
		for (int iTF = 0; iTF < tokens; ++iTF)
		{
			if (lockGood[iTF] == false && lockGood[iC] == false && lockBad[iTF] == false && iC != iTF && comboToFind[iTF] == game->getTriedCombo()[iC])
			{
				//cerr << "position X locked " << iC << " > " << iTF << endl;
				lockBad[iTF] = true;
				badPos++;
				break;
			}
		}
	}
	//cerr << comboToFind << " - V:" << goodPos << " X:" << badPos;
	
	return Result(goodPos, badPos);
}




void MindAI::updateList()
// efface de la liste toutes les combinaisons incompatibles avec le résultat obtenu
{
	for (size_t i = 0; i < list->getAllCombos()->size(); i++)
	{
		if (game->getResult() != resultCompare(list->getAllCombos()->at(i)))
		{
			list->remove(list->getAllCombos()->at(i));
			i--;
		}
	}
}



Result MindAI::catchResult()
// l'utilisateur encode un résultat pour une combinaison suggérée
{
	int result[2] = { 0 };
	do
	{		
		cout << "V : ";
		cin >> result[0];
		cout << "X : ";
		cin >> result[1];

		if (result[0] + result[1] > DEFAULT_TOKENS)
			cout << "// erreur de resultat" << endl;

	} while (result[0] + result[1] > DEFAULT_TOKENS);

	return Result(result);
}


Combo MindAI::catchCombo()
// l'utilisateur définit la combinaison à trouver
{
	Combo c;
	do
	{
		cout << "Votre combinaison : ";
		cin >> c;
	} while (!validCombo(c));
	
	return c;

}


bool MindAI::validCombo(Combo _combo)
{
	bool valid = false;

	if (_combo.getSize() == 4)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (_combo[i] > 0 && _combo[i] < 9)
			{
				valid = true;
			}
			else
			{
				valid = false;
				break;
			}
		}
	}
	return valid;
}