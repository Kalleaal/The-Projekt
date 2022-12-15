#include "Yhteystietokirja.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

Yhteystietokirja::Yhteystietokirja(string tiedosto)
{
	string tiedosonNimi = "ostoslista.txt";
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
			lisaaYhteystieto(Kaveri)
			break;
		case 4:
			lisaaYhteystieto(Kollega)
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

void Yhteystietokirja::lisaaYhteystieto()
{

}

void Yhteystietokirja::tulosta()
{
	int koko = tiedot.size();

	cout << "Inventaario: " << endl;

	// Kydn lpi kaikki tuotteet

	for (int i = 0; i < koko; i++)
	{
		tiedot[i]->tulosta();
	}

}

void Yhteystietokirja::tallennaTiedostoon()
{
	
	ofstream myFile(Lista, fstream);
	if (myFile)
	{
		for (int i = 0; i < tiedot.size(); i++)
		{
			myFile << tiedot[i]->haeNimi() << endl;
			myFile << tiedot[i]->haeKpl() << endl;
		}
	}    myFile.close();
}

void Yhteystietokirja::tyhjennys()
{
	// trunc-moodi avaa tiedoston ja tuhoaa sislln
	ofstream myFile(tiedostonNimi, ofstream::trunc);
	myFile.close();
	// Vektorin tyhjennys
	Yhteystiedot.clear();
}

void Yhteystietokirja::lisaaYhteystieto()
{
	string nimi;
	string osoite;
	string pnumero;

	//Kysytn uuden tuotteen tiedot
	cout << "Anna uuden yhteystiedon nimi, osoite ja puhelinnumero  " << endl;
	cout << "Nimi: ";
	cin >> nimi;
	cout << "Osoite: ";
	cin >> osoite;
	cout << "Puhelinnumero:"
	cin >> pnumero;

	Yhteystiedot* tiedot = new tiedot(nimi, osoite, pnumero);
	yhteystiedot.push_back(tiedot);
}

void Yhteystietokirja::lueTiedosto()
{
	string nimi;
	string osoite;
	string pnumero;
	string steamId;
	string tnumero;


	ifstream myFile;
	myFile.open(tiedostonNimi);
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
		Yhteystiedot* tiedot = new Yhteystiedot(nimi, osoite, atoi(pnumero.c_str()));
			tiedot.push_back(tiedot);
		}
		myFile.close();
	}
	else
	{
		cout << "Virhe tiedoston avaamisessa" << endl;
	}
}

