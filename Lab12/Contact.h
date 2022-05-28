#pragma once
enum Tip {
	prieten,
	cunoscut,
	coleg
};
class Contact
{
public:
	char* nume;
	Tip tipClasa;
};