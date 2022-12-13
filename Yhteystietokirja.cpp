#include "Yhteystietokirja.h"
#include <iostream>
#include <fstream>

using namespace std;

void Yhteystietokirja::menu()
{
	int valinta;
	do
	{
		cout << "Yhteystietokirja Ohjelma\n";
		cout << "(1)	\n";
		cout << "(2)	\n";
		cout << "(3)	\n";
		cout << "(0) Lopeta ohjelma\n";
		cin >> valinta;



		switch (valinta)
		{
		case 1:
			
			break;

		case 2:
			
			break;

		case 3:
			
			break;

		case 0:
		

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

void Yhteystietokirja::print()
{
	std::cout << "Nimi:" << nimi << endl;
	std::cout << "Osoite: " << osoite << endl;
	std::cout << "Puhelin Numero:  " << " \n";

}

void Yhteystietokirja::tallennaTiedostoon()
{
	
	ofstream myFile(Lista, fstream);
	if (myFile)
	{
		for (int i = 0; i < Yhteystietokirja.size(); i++)
		{
			myFile << ostokset[i]->haeNimi() << endl;
			myFile << ostokset[i]->haeKpl() << endl;
		}
	}    myFile.close();
}

void Yhteystietokirja::tyhjenn()
{
	// trunc-moodi avaa tiedoston ja tuhoaa sislln
	ofstream myFile(tiedostonNimi, ofstream::trunc);
	myFile.close();
	// Vektorin tyhjennys
	ostokset.clear();
}

void Yhteystietokirja::UusiOstos()
{
	string nimi;
	int kpl;

	//Kysytn uuden tuotteen tiedot
	cout << "Anna uuden tuotteen nimi ja kpl mr: " << endl;
	cout << "Nimi: ";
	cin >> nimi;
	cout << "Kappalemr: ";
	cin >> kpl;

	Ostos* ostos = new Ostos(nimi, kpl);
	ostokset.push_back(ostos);
}

void Yhteystietokirja::lueTiedosto()
{
	string nimi;
	string kpl;

	ifstream myFile;
	myFile.open(tiedostonNimi);
	if (myFile)
	{
		while (myFile.peek() != EOF)
		{
			//Luetaan tiedostoa rivi kerrallaan
			//Listn teksti vektoriin
			getline(myFile, nimi);
			getline(myFile, kpl);

			Ostos* uusiostos = new Ostos(nimi, atoi(kpl.c_str()));
			ostokset.push_back(uusiostos);
		}
		myFile.close();
	}
	else
	{
		cout << "Virhe tiedoston avaamisessa" << endl;
	}
}

Yhteystietokirja::Yhteystietokirja (string tiedosto)
{
	string tiedosonNimi = "ostoslista.txt";
	lueTiedosto();
}