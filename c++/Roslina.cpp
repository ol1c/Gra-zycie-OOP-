#include "Roslina.h"
#include "Swiat.h"
#include <iostream>


Polozenie Roslina::Akcja()
{
	//próba rozmno¿enia
	int czy_rozmnozy = rand() % dzielnik;
	switch (czy_rozmnozy)
	{
	case 0:
		this->swiat->DodajOrganizm(this->JakiGatunek(), this->polozenie.x, this->polozenie.y);
	default:
		break;
	}

	//roœlina siê nie przemieszcza wiêc zwraca zajmown¹ ju¿ przez ten organizm pozycjê
	return this->polozenie;
}

void Roslina::Kolizja(Organizm* organizm)
{
	//organizm zjada roœlinê
	this->swiat->DodajLog(organizm->DoNapisu() + " je " + this->DoNapisu());
	//organizm zabija roœlinê
	this->swiat->Walka(this, organizm);
}


Roslina::~Roslina()
{
}