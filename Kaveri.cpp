#include "Kaveri.h"

Kaveri::Kaveri(string n, string o, float p, string k, int d) 
: Yhteystiedot(n, o, p) 
{
	nickname = k;
	discordId = d;
};


void Kaveri::tulosta()
{
	//cout << "Nimi:     " << nimi << endl;
	//cout << "Osoite    " << osoite << endl;
	//cout << "Pnumero   " << pnumero << endl;
	cout << "Nickname:     " << nickname << endl;
	cout << "Discord ID    " << discordId << endl;

}
