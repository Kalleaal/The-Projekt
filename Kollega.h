#pragma once
#include"Yhteystiedot.h"

class Kollega:public Yhteystiedot
{
public:
	Kollega(string n, string o, double p, double t);
	void tulosta() override;
	double tnumero;
protected:
	

};

