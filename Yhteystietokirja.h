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

	void menu();
	void lisaaYhteystieto();
	virtual void tulosta();
	void tallennaTiedostoon();
	void tyhjennys();
	void lueTiedosto();
	//void etsi();		// Laajennus mahdollisuus.

	enum YhteystietoTyypit
	{
		Kaveri,
		Kollega,
		Muut
	};

protected:
	vector<Yhteystiedot*>tiedot;

};

