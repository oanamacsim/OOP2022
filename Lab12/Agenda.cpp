#include "Agenda.h"
#define CRT_SECURE_NO_WARNINGS
#include <string.h>
Contact* Agenda::gasesteContact(char* nume) {
	for (int i = 0; i < contacte.size(); i++)
		if (strcmp(contacte[i]->nume, nume) == 0)
			return contacte[i];
	return nullptr;
}

vector<Contact*> Agenda::listaPrieteni() {
	vector<Contact*>toReturn;
	for (int i = 0; i < contacte.size(); i++)
		if (contacte[i]->tipClasa == Tip::Prieten)
			toReturn.push_back(contacte[i]);
	return toReturn;
}

bool Agenda::stergeContact(char* nume) {
	for (int i = 0; i < contacte.size(); i++)
		if (strcmp(contacte[i]->nume, nume) == 0)
		{
			contacte.erase(contacte.begin() + i);
			return true;
		}
	return false;
}

bool Agenda::AdaugaContact(Contact* contact) {
	contacte.push_back(contact);
	return true;
}