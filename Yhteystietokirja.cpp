#include "Yhteystietokirja.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

Yhteystietokirja::Yhteystietokirja(string tiedosto)
{
	string tiedostonNimi = "yhteystiedot.txt";
	lueTiedosto();
}

void Yhteystietokirja::menu()
{
	int valinta;
	do
	{
		cout << "Yhteystietokirja Ohjelma\n";
		cout << "(1) Tulosta yhteystiedot				\n";
		cout << "(2) Uusi yhteystieto					\n";
		cout << "(3) Uusi kaverin yhteystieto 			\n";
		cout << "(4) Uusi kollegan yhteystieto			\n";
		cout << "(5) Poista kaikki tiedot				\n";
		cout << "(0) Lopeta ohjelma ja tallenna\n";
		cin >> valinta;
		switch (valinta)
		{
		case 1:
			tulosta;
			break;
		case 2:
			lisaaYhteystieto(Muut);
			break;
		case 3:
			lisaaYhteystieto(Kaveri);
			break;
		case 4:
			lisaaYhteystieto(Kollega);
			break;
		case 5:
			tyhjennys;
			break;
		case 0:
			tallennaTiedostoon;
		}

		if (valinta != 0)
		{
			cout << "Paina anykey jatkaaksesi." << "\n";
			cin.ignore();
			cin.get();
			system("cls");
		}

	} while (valinta != 0);

}

void Yhteystietokirja::lisaaYhteystieto(YhteystietoTyypit tyyppi)
{

}

void Yhteystietokirja::tulosta()
{
	int koko = tiedot.size();

	cout << "Yhteystiedot " << endl;

	for (int i = 0; i < koko; i++)
	{
		tiedot[i]->tulosta();
	}

}

void Yhteystietokirja::tallennaTiedostoon()
{
	
	ofstream myFile("yhteystiedot.txt");
	if (myFile)
	{
		
		myFile << tulosta ;
		
		
	}myFile.close();
}

void Yhteystietokirja::tyhjennys()
{
	// trunc-moodi avaa tiedoston ja tuhoaa sislln
	ofstream myFile("yhteystiedot.txt", ofstream::trunc);
	myFile.close();
	// Vektorin tyhjennys
	Yhteystiedot&clear();
}

void Yhteystietokirja::lisaaYhteystieto(YhteystietoTyypit tyyppi)
{
	string nimi;
	string osoite;
	float pnumero;

	//Kysytn uuden tuotteen tiedot
	cout << "Anna uuden yhteystiedon nimi, osoite ja puhelinnumero  " << endl;
	cout << "Nimi: ";
	cin >> nimi;
	cout << "Osoite: ";
	cin >> osoite;
	cout << "Puhelinnumero:";
	cin >> pnumero;

	Yhteystiedot* tiedotz = new Yhteystiedot(nimi, osoite, pnumero);
	tiedot.push_back(tiedotz);
}

void Yhteystietokirja::lueTiedosto()
{
	string nimi;
	string osoite;
	string pnumero;
	string steamId;
	string tnumero;


	ifstream myFile;
	myFile.open("yhteystiedot.txt");
	if (myFile)
	{
		while (myFile.peek() != EOF)
		{
			//Luetaan tiedostoa rivi kerrallaan
			//Listn teksti vektoriin
			getline(myFile, nimi);
			getline(myFile, osoite);
			getline(myFile, pnumero);
			getline(myFile, steamId);
			getline(myFile, tnumero);
		Yhteystiedot* tiedotz = new Yhteystiedot(nimi, osoite, atoi(pnumero.c_str()));
			tiedot.push_back(tiedotz);
		}
		myFile.close();
	}
	else
	{
		cout << "Virhe tiedoston avaamisessa" << endl;
	}
}

