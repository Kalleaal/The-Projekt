#pragma once
#include "Yhteystiedot.h"


class Kaveri:public Yhteystiedot
{
public:
	Kaveri(string n, string o, float p, string k, int d);
	void tulosta() override;

protected:
	string nickname;
	int discordId;


};

