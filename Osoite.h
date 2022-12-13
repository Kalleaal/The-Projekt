#pragma once
#include "Yhteystietokirja.h"
#include <string>

using namespace std;

class Osoite:Yhteystietokirja
{
public:
	Osoite(string nimi, string osoite);
	void print() override;


protected:


};

