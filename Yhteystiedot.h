#pragma once
#include <iostream>
using namespace std;

class Yhteystiedot
{
	public:
	
	Yhteystiedot(string n, string o, float p);
	virtual void tulosta();

	string nimi;
	string osoite;
	float pnumero;

protected:

};

