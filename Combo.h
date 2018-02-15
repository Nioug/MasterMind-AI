#pragma once

//
// Cet objet contient une combinaison de mastermind dans un vector
//

#include <iostream>
#include <vector>
#include <string>

#define INDEX_ERROR 1
#define SIZE_ERROR 2

#define DEFAULT_SIZE 4
#define DEFAULT_SEPARATOR 0

using namespace std;

class Combo
{
public:
	Combo(int size = DEFAULT_SIZE);
	Combo(vector<int> combo);
	Combo(int combo[], int size);

	vector<int> getVector() const;
	int getSize() const;
	int getAt(int _index) const;
	void setAt(int _integer, int _index);
	string toString(char separator = DEFAULT_SEPARATOR) const;

	int operator[](int index) const;

private:
	vector<int> combo;
};

ostream& operator<<(ostream& output, Combo combo);
istream& operator>>(istream& input, Combo &combo);
bool operator==(const Combo &c1, const Combo &c2);