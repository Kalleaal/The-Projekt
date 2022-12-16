#include "Kollega.h"



Kollega::Kollega(string n, string o, long p, long t) : Yhteystiedot(n, o, p) 
{
	tnumero = t;
};


void Kollega::tulosta()
{
	cout << "Nimi:     " << nimi << endl;
	cout << "Osoite:    " << osoite << endl;
	cout << "Pnumero:   " << pnumero << endl;
	cout << "Tyonumero:     " << tnumero << endl <<endl;
}
