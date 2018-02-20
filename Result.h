#pragma once

#ifndef RESULT_H
#define RESULT_H

#define SIZE 2


//
// class Result stocke le résultat d'une combinaison de MasterMind
// elle indique la quantité de pions correctement et incorrectement placés
//

#include <iostream>
using namespace std;

enum pos {GOOD, BAD, NONE};

class Result
{
public:
	Result(int goodPos = 0, int badPos = 0);
	Result(int result[SIZE]);

	int getGoodPos() const;							// retourne le nombre de pions bien placés
	int getBadPos() const;							// retourne le nombre de pions mal placés

	void setGood(int goodPos);						// définit le nombre de pions bien placés
	void setBad(int badPos);						// définit le nombre de pions mal placés
	void setResult(int result[SIZE]);				// définit un résultat sur base d'un talbeau 
	void setResult(int _good, int _bad);			// définit un résultat sur base des pions bien et mal placés

	operator int();									// opérateur de conversion qui renvoie le nombre de pions (bien et mal placés)

private:
	int result[SIZE];								// le résultat est stocké dans un tableau à 2 caractères
};


// SURCHARGE DES OPERATEURS
ostream& operator<<(ostream&, Result);
bool operator==(const Result &r1, const Result &r2);
bool operator!=(const Result &r1, const Result &r2);


#endif // !RESULT_H
