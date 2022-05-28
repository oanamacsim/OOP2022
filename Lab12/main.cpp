#include <iostream>
#include "Agenda.h"
#include"Prieten.h"
#include "Cunoscut.h"
#include "Coleg.h"
using namespace std;

int main()
{
	Agenda exemplu;

	char nume[] = "Mihai";
	char nume2[] = "Andrei";
	char ziNastere[] = "13mai1994";
	char adresa[] = "Strada Lazar nr55";
	char nrTelefon[] = "0000000000";
	char firma[] = "BitDefender";
	Contact* A = new Prieten(nume, ziNastere, nrTelefon, adresa);
	Contact* B = new Prieten(nume2, ziNastere, nrTelefon, adresa);
	Contact* C = new Cunoscut(nume, nrTelefon);
	Contact* D = new Cunoscut(nume, nrTelefon);
	Contact* E = new Coleg(nume, nrTelefon, firma, adresa);
	Contact* F = new Coleg(nume, nrTelefon, firma, adresa);

	exemplu.AdaugaContact(A);
	exemplu.AdaugaContact(B);
	exemplu.AdaugaContact(C);
	exemplu.AdaugaContact(D);
	exemplu.AdaugaContact(E);
	exemplu.AdaugaContact(F);

	cout << exemplu.gasesteContact(nume)->nume << '\n';
	vector<Contact*>lista = exemplu.listaPrieteni();
	cout << "Lista Prieteni:\n";
	for (auto it : lista)
		cout << it->nume << '\n';
}