#pragma once
#include "Yhteystietokirja.h"


class Yhteystiedot
{
	public:
// konstruktori
	Yhteystiedot(string n, string o, float p);
	
	virtual void tulosta();

	protected:
	string nimi;
	string osoite;
	float pnumero;
};

