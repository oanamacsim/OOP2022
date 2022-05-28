#pragma once
#include "Contact.h"
class Cunoscut : public virtual Contact
{
public:
	char* numarTelefon;
	Cunoscut(char* name, char* numarTelefon);
};

Cunoscut::Cunoscut(char* name, char* nrTel) {
	nume = name;
	numarTelefon = nrTel;
	tipClasa = Tip::cunoscut;
}