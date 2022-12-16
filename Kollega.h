#pragma once
#include"Yhteystiedot.h"

class Kollega:public Yhteystiedot
{
public:
	Kollega(string n, string o, long p, long t);
	void tulosta() override;
	long tnumero;
protected:
	

};

