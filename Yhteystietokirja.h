#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Yhteystiedot.h"

using namespace std;


class Yhteystietokirja
{
public:
	enum YhteystietoTyypit
	{
		Kaveri,
		Kollega,
		Muut
	};

	Yhteystietokirja(string tiedosto);
	void menu();
	void lisaaYhteystieto(YhteystietoTyypit tyyppi);
	virtual void tulosta();
	void tallennaTiedostoon();
	void tyhjennys();
	void lueTiedosto();
	//void etsi();		// Laajennus mahdollisuus.


protected:
	vector<Yhteystiedot*>tiedot;

};

