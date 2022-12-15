#pragma once
#include"Yhteystiedot.h"
class Kollega:Yhteystiedot
{
public:
	Kollega(string n, string o, float p, float t);
	void tulosta() override;

protected:
	float tnumero;

};

