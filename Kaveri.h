#pragma once
#include "Yhteystiedot.h"


class Kaveri:public Yhteystiedot
{
public:
	Kaveri(string n, string o, long p, string k, int d);
	void tulosta() override;


	string nickname;
	int discordId;

protected:



};

