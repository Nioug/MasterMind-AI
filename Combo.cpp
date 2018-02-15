#include "stdafx.h"

#include "Combo.h"


/*
	Constructors
	Le constructeur par défaut crée une combinaison de 4 pions avec la valeur 1
*/
Combo::Combo(int _size)
{
	for (int i = 0; i < _size; ++i)
		combo.push_back(1);
}

Combo::Combo(vector<int> _combo)
{
	for (auto elt : _combo)
		combo.push_back(elt);
}

Combo::Combo(int _combo[], int _size)
{
	for (int i = 0; i < _size; ++i)
		combo.push_back(_combo[i]);
}




/*
	Getters
*/
vector<int>	Combo::getVector() const	{ return combo;			}

int Combo::getSize() const				{ return combo.size();	}

int Combo::getAt(int _index) const
{
	if (_index < combo.size())
		return combo[_index]; 
	else
		throw INDEX_ERROR;
}


/*
	Setters
*/
void Combo::setAt(int _integer, int _index)
{
	if (_index < combo.size())
		combo[_index] = _integer;
	else
		throw INDEX_ERROR;
}



/*
	retourne une string avec un caractère séparateur optionnel (par défaut sans espace)
*/
string Combo::toString(char separator) const
{
	string str = "";
	string sep = "";

	if (separator != DEFAULT_SEPARATOR)
		sep = separator;


	for (int i = 0; i < combo.size(); ++i)
	{
		str += string(to_string(this->getAt(i)));
		if (i < combo.size() - 1)
			str += sep;
	}
	return str;
}



/*
	Surcharge des operateur
*/
ostream& operator<<(ostream& sortie, Combo _combo)
{
	return sortie << _combo.toString();
}


istream& operator>>(istream& in, Combo &_combo)
{
	string input;
	in >> input;

	vector<int> temp;

	for (int i = 0; i < input.size(); ++i)
	{
		int put = stoi(string(to_string(input[i]))) - 48;

		if (put < 0 || put > 9)
			temp.push_back(0);

		temp.push_back(put);
	}
	_combo = Combo(temp);

	return in;
}


bool operator==(const Combo &c1, const Combo &c2)
{
	bool result = false;

	if (c1.getSize() != c2.getSize())
		return false;

	for (int i = 0; i < c1.getSize(); ++i)
	{
		if (c1[i] == c2[i])
			result = true;
		else
			return false;
	}
	return result;
}


int Combo::operator[](int index) const
{
	if (index < this->getSize())
		return this->getAt(index);
	else
		throw INDEX_ERROR;
}
