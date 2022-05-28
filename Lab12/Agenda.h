#pragma once
#include "Contact.h"
#include <vector>
using namespace std;
class Agenda
{
public:
	vector<Contact*>contacte;
	Contact* gasesteContact(char* nume);
	vector<Contact*> listaPrieteni();
	bool stergeContact(char* name);
	bool AdaugaContact(Contact* contact);
};