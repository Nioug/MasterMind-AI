#include "stdafx.h"

#include "MindAI.h"


MindAI::MindAI(int _attempts, int _colors, int _tokens)
{
	list = MindList(_colors, _tokens);
	game = Game(_colors, _tokens);
	attempts = _attempts;
	listSize = list.getAllCombos().size();
	removed = 0;
}


Game MindAI::getGame() const
{
	return game;
}

MindList MindAI::getList() const
{
	return list;
}


Combo MindAI::tryInitCombos()		
// retourne la preimière combinaison puis l'efface
{
	Combo temp = list.getInitCombos().at(0);
	list.popFrontInit();
	return temp;
}


Combo MindAI::tryCombo()	
// retourne la combinaison suivante de la liste avec la priorité la plus faible
{
	int size = list.getAllCombos().size();
	for (int iVect = 0; iVect < size; iVect++)
	{
		for (int iPrior = 0; iPrior < MAX_PRIOR; iPrior++)
		{
			if (iPrior == 1)
				continue;

			if (list.getAllCombos().at(iVect).getPriority() == iPrior)
			{
				// cerr << " / selected : " << iPrior << endl;
				return list.getAllCombos().at(iVect);
			}
		}
	}
	return NULL;
}


bool MindAI::play()
{
	int tokensFound = 0;
	int size = list.getInitCombos().size();
	for (int i = 0; i < size; i++)
	{
		Combo init = tryInitCombos();		

		game.play(init);
		cout << endl << "# " << 11 - attempts << ": " << init << " / " << game.getResult() << endl;
		
		updateList();		
		attempts--;

		if (game.win())
			return true;

		if (tokensFound == game.getTokens())
		{
			// cerr << "// 4 tokens found" << endl;
			break;
		}
	}

	//cerr << endl << "end init";

	while (attempts >= 0 && !game.win())
	{
		Combo toTry = tryCombo();
		game.play(toTry);
		cout << endl << "# " << 11 - attempts << ": " << toTry << " / " << game.getResult() << endl;

		updateList();
		attempts--;
	}

	if (game.win())
		return true;
	else
		return false;
}


Result MindAI::resultCompare(Combo comboToFind) const
{
	vector<bool> lockGood(game.getTokens(), false);
	vector<bool> lockBad(game.getTokens(), false);
	int goodPos = 0;
	int badPos = 0;

	int tokens = game.getTokens();

	for (int i = 0; i < tokens; ++i)
	{
		if (game.getTriedCombo().getAt(i) == comboToFind[i])
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
			if (lockGood[iTF] == false && lockGood[iC] == false && lockBad[iTF] == false && iC != iTF && comboToFind[iTF] == game.getTriedCombo().getAt(iC))
			{
				//cerr << "position X locked " << iC << " > " << iTF << endl;
				lockBad[iTF] = true;
				badPos++;
				break;
			}
		}
	}
	//cerr << comboToFind << " - V:" << goodPos << "/X:" << badPos;
	
	return Result(goodPos, badPos);
}


void MindAI::updateList()
// retire les combinaisons impossible de la liste en fonction du résultat d'une combinaison
{
	int size = list.getAllCombos().size();
	for (int i = 0; i < size; i++)
	{
		if (game.getResult() != resultCompare(list.getAllCombos().at(i)))
		{
			list.remove(list.getAllCombos().at(i));
			//list.getAllCombos().erase(list.getAllCombos().begin() + i);
			i--;
			size--;
			//list.getAllCombos().at(i).setPriority(DISABLED);
			//cerr << "|";
		}
	}
}