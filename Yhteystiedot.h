#pragma once
#include <iostream>
using namespace std;

class Yhteystiedot
{
	public:
	
	Yhteystiedot(string n, string o, double p);
	virtual void tulosta();

	string nimi;
	string osoite;
	double pnumero;

protected:

};

