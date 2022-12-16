#include "Yhteystietokirja.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Yhteystiedot.h"
#include "Kaveri.h"
#include "Kollega.h"
using namespace std;

Yhteystietokirja::Yhteystietokirja(string tiedosto)
{
	tiedostonNimi = tiedosto;
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
			lueTiedosto();
			break;
		case 2:
			lisaaYhteystieto(Muut1);
			break;
		case 3:
			lisaaYhteystieto(Kaveri1);
			break;
		case 4:
			lisaaYhteystieto(Kollega1);
			break;
		case 5:
			tyhjennys();
			break;
		case 0:
			break;
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


void Yhteystietokirja::tulosta()
{
	int koko = tiedot.size();

	cout << "Yhteystiedot " << endl;

	for (int i = 0; i < koko; i++)
	{
		tiedot[i]->tulosta();
	}

}

void Yhteystietokirja::tallennaKaveriTiedostoon(Kaveri* ka)
{
	ofstream myFile(tiedostonNimi,std::ios::app);
	
	if (myFile)
	{
	/*	myFile << ka->nimi << "\n" << ka->osoite << "\n" << ka->pnumero << "\n" << ka->nickname << "\n" << ka->discordId << endl << endl;*/
		myFile << "Nimi:			" << ka->nimi << endl;
		myFile << "Osoite			" << ka->osoite << endl;
		myFile << "Pnumero			" << ka->pnumero << endl;
		myFile << "Nickname:		" << ka->nickname << endl;
		myFile << "Discord ID		" << ka->discordId << endl << endl;

	}myFile.close();

}

void Yhteystietokirja::tallennaKollegaTiedostoon(Kollega* k)
{
	ofstream myFile(tiedostonNimi, std::ios::app);

	if (myFile)
	{
		/*myFile << k->nimi << "\n" << k->osoite << "\n" << k->pnumero << "\n" << k->tnumero << endl << endl;*/
		myFile << "Nimi:			" << k->nimi << endl;
		myFile << "Osoite			" << k->osoite << endl;
		myFile << "Pnumero			" << k->pnumero << endl;
		myFile << "Tyonumero		" << k->tnumero << endl << endl;

	}myFile.close();

}

void Yhteystietokirja::tallennaMuuTiedostoon(Yhteystiedot* y)
{
	ofstream myFile(tiedostonNimi, std::ios::app);

	if (myFile)
	{
		/*myFile << y->nimi << "\n" << y->osoite << "\n" << y->pnumero << endl << endl;*/
		
		myFile << "Nimi:			" << y->nimi << endl;
		myFile << "Osoite			" << y->osoite << endl;
		myFile << "Pnumero			" << y->pnumero << endl << endl;

	}myFile.close();

}

void Yhteystietokirja::tyhjennys()
{
	
	ofstream myFile(tiedostonNimi);
	myFile << "";
	tiedot.clear();
	
}

void Yhteystietokirja::lisaaYhteystieto(YhteystietoTyypit tyyppi)
{
	string nimi;
	string osoite;
	long pnumero;

	
	cout << "Anna uuden yhteystiedon nimi, osoite ja puhelinnumero  " << endl;
	cout << "Nimi: ";
	cin >> nimi;
	cout << "Osoite: ";
	cin.ignore();
	getline (cin,osoite);
	cout << "Puhelinnumero:";
	cin >> pnumero;
	cin.ignore();


	if (tyyppi == Kollega1)
	{

		long tnumero;
		
		cout << "Tyopuhelinnumero ";
		cin >> tnumero;

		// Uusi olio
		Kollega* Kollega1 = new Kollega(nimi, osoite, pnumero, tnumero);
		// Listn vektoriin
		tiedot.push_back(Kollega1);

		tallennaKollegaTiedostoon(Kollega1);
	}
	else if (tyyppi == Kaveri1)
	{
		
		string nickname;
		int discordId;


		cout << "Anna kaverin nickname:" << endl;
		cin >> nickname;
		cout << "ja Discord id: " << endl;
		cin >> discordId;



		// Uusi UrheiluV olio
		Kaveri* kaveri1 = new Kaveri(nimi, osoite, pnumero, nickname, discordId);
		// Listn vektoriin
		tiedot.push_back(kaveri1);
		tallennaKaveriTiedostoon(kaveri1);
	}
	else if (tyyppi == Muut1)
	{
		Yhteystiedot* tiedotz = new Yhteystiedot(nimi, osoite, pnumero);
		tiedot.push_back(tiedotz);
		tallennaMuuTiedostoon(tiedotz);
	}



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
			Yhteystiedot* tiedotz = new Yhteystiedot(nimi, osoite, atof(pnumero.c_str()));
			tiedot.push_back(tiedotz);
		}
		myFile.close();
		tulosta();
	}
	else
	{
		cout << "Virhe tiedoston avaamisessa" << endl;
	}
}

