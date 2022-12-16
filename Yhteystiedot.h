#pragma once
#include <iostream>
using namespace std;

class Yhteystiedot
{
	public:
	
	Yhteystiedot(string n, string o, long p);
	virtual void tulosta();

	string nimi;
	string osoite;
	long pnumero;

protected:

};

