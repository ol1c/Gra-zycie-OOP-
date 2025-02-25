#include "Roslina.h"
#include "Swiat.h"
#include <iostream>


Polozenie Roslina::Akcja()
{
	//pr�ba rozmno�enia
	int czy_rozmnozy = rand() % dzielnik;
	switch (czy_rozmnozy)
	{
	case 0:
		this->swiat->DodajOrganizm(this->JakiGatunek(), this->polozenie.x, this->polozenie.y);
	default:
		break;
	}

	//ro�lina si� nie przemieszcza wi�c zwraca zajmown� ju� przez ten organizm pozycj�
	return this->polozenie;
}

void Roslina::Kolizja(Organizm* organizm)
{
	//organizm zjada ro�lin�
	this->swiat->DodajLog(organizm->DoNapisu() + " je " + this->DoNapisu());
	//organizm zabija ro�lin�
	this->swiat->Walka(this, organizm);
}


Roslina::~Roslina()
{
}