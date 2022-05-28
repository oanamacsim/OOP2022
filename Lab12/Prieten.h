#pragma once
#include "Contact.h"
class Prieten : public virtual Contact
{
public:
	char* dataNastere;
	char* numarTelefon;
	char* adresa;
	Prieten(char* nume, char* dataNastere, char* nrTel, char* adr);
};


Prieten::Prieten(char* name, char* dataNast, char* nrTel, char* adr)
{
	nume = name;
	dataNastere = dataNast;
	numarTelefon = nrTel;
	adresa = adr;
	tipClasa = Tip::prieten;
}