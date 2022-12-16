#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Yhteystiedot.h"
#include "Kaveri.h"
#include "Kollega.h"
using namespace std;


class Yhteystietokirja
{
public:
	enum YhteystietoTyypit
	{
		Kaveri1,
		Kollega1,
		Muut1
	};

	Yhteystietokirja(string tiedosto);
	void menu();
	void lisaaYhteystieto(YhteystietoTyypit tyyppi);
	virtual void tulosta();
	void tallennaKaveriTiedostoon(Kaveri* ka);
	void tallennaKollegaTiedostoon(Kollega* k);
	void tallennaMuuTiedostoon(Yhteystiedot* y);
	void tyhjennys();
	void lueTiedosto();
	//void etsi();		// Laajennus mahdollisuus.


protected:
	std::vector<Yhteystiedot*>tiedot;


	std::string tiedostonNimi = "yhteystiedot.txt";
};

