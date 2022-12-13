#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


class Yhteystietokirja
{
public:

	void menu();
	void lisaaYhteystieto();
	virtual void print();
	void tallennaTiedostoon();
	void tyhjenn();
	void UusiOstos();
	void lueTiedosto();
	//void etsi();		// Laajennus mahdollisuus.


protected:
	vector<Yhteystietokirja*>Yhteystiedot;

};

