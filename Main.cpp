#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Yhteystiedot.h"
#include "Yhteystietokirja.h"
#include <clocale>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleCP(2504);
	SetConsoleOutputCP(2504);

	Yhteystietokirja ytk{ "yhteystiedot.txt" };
	ytk.menu();



}