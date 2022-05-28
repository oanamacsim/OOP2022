#pragma once
#include "Contact.h"
class Coleg : public virtual Contact
{
public:
	char* numarTelefon;
	char* firma;
	char* adresa;
	Coleg(char* nume, char* nrTel, char* firma, char* adr);

};

Coleg::Coleg(char* name, char* nrTel, char* numeFirma, char* adr)
{
	nume = name;
	tipClasa = Tip::coleg;
	numarTelefon = nrTel;
	firma = numeFirma;
	adresa = adr;
}