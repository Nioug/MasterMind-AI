#pragma once

#ifndef RESULT_H
#define RESULT_H

#define SIZE 2


//
// class Result stocke le r�sultat d'une combinaison de MasterMind
// elle indique la quantit� de pions correctement et incorrectement plac�s
//

#include <iostream>
using namespace std;

enum pos {GOOD, BAD, NONE};

class Result
{
public:
	Result(int goodPos = 0, int badPos = 0);
	Result(int result[SIZE]);

	int getGoodPos() const;							// retourne le nombre de pions bien plac�s
	int getBadPos() const;							// retourne le nombre de pions mal plac�s

	void setGood(int goodPos);						// d�finit le nombre de pions bien plac�s
	void setBad(int badPos);						// d�finit le nombre de pions mal plac�s
	void setResult(int result[SIZE]);				// d�finit un r�sultat sur base d'un talbeau 
	void setResult(int _good, int _bad);			// d�finit un r�sultat sur base des pions bien et mal plac�s

	operator int();									// op�rateur de conversion qui renvoie le nombre de pions (bien et mal plac�s)

private:
	int result[SIZE];								// le r�sultat est stock� dans un tableau � 2 caract�res
};


// SURCHARGE DES OPERATEURS
ostream& operator<<(ostream&, Result);
bool operator==(const Result &r1, const Result &r2);
bool operator!=(const Result &r1, const Result &r2);


#endif // !RESULT_H
