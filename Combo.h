#pragma once

#ifndef COMBO_H
#define COMBO_H

//
// Cet objet contient une combinaison de mastermind dans un vector
//

#include <iostream>
#include <vector>
#include <string>

#define INDEX_ERROR 1
#define SIZE_ERROR 2

#define DEFAULT_SIZE 4
#define DEFAULT_SEPARATOR ""

using namespace std;

class Combo
{
public:
	Combo(int size = DEFAULT_SIZE);
	Combo(vector<int> combo);
	Combo(int combo[], int size);
	Combo(string combo);

	vector<int> getVector() const;							// retourne le vector
	int getSize() const;									// retourne la taille du vector
	int getAt(int i) const;										// retourne la valeur à un index
	void setAt(int _integer, int _index);

	int getPriority() const;								// retourne la priorité d'une combinaison
	void setPriority(int);									// définit la priorité d'une combinaison

	string toString(string separator = DEFAULT_SEPARATOR) const;

	int operator[](int index) const;						// surcharge de l'opérateur d'indexation

private:
	vector<int> combo;
	int priority;
};


// SURCHARGE DES OPERATEURS
ostream& operator<<(ostream& output, Combo combo);
istream& operator>>(istream& input, Combo &combo);
bool operator==(const Combo &c1, const Combo &c2);


#endif // !COMBO_H
