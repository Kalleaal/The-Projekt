
#include "Yhteystiedot.h"




Yhteystiedot::Yhteystiedot(string n, string o, double p )
{
	nimi = n;
	osoite = o;
	pnumero = p;

}

void Yhteystiedot::tulosta()
{
	cout << "Nimi:     " << nimi << endl;
	cout << "Osoite    " << osoite << endl;
	cout << "Pnumero   " << pnumero << endl;
}

