#include "Organizm.h"
#include "Rosliny.h"
#include "Swiat.h"
#include <iostream>
#include <string>

using namespace std;

Trawa::Trawa(const int x, const int y, Swiat* s)
{
	this->gatunek = TRAWA;
	this->inicjatywa = 0;
	this->sila = 0;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->swiat = s;
}

Trawa::Trawa(const int x, const int y, Swiat* s, const int sila)
{
	this->gatunek = TRAWA;
	this->inicjatywa = 0;
	this->sila = sila;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->swiat = s;
}

void Trawa::Rysowanie()
{
	cout << "T";
}

string Trawa::DoNapisu()
{
	return "Trawa[" + to_string(this->polozenie.x) + "][" + to_string(this->polozenie.y) + "]";
}

Trawa::~Trawa()
{
}


Mlecz::Mlecz(const int x, const int y, Swiat* s)
{
	this->gatunek = MLECZ;
	this->inicjatywa = 0;
	this->sila = 0;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->swiat = s;
}

Mlecz::Mlecz(const int x, const int y, Swiat* s, const int sila)
{
	this->gatunek = MLECZ;
	this->inicjatywa = 0;
	this->sila = sila;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->swiat = s;
}

Polozenie Mlecz::Akcja()
{
	//mlecz podejmuje 3 próby rozmno¿enia
	int czy_rozmnozy;
	for (int i = 0; i < 3; i++)
	{

		czy_rozmnozy = rand() % dzielnik;
		switch (czy_rozmnozy)
		{
		case 0:
			this->swiat->DodajOrganizm(MLECZ, this->polozenie.x, this->polozenie.y);
		default:
			break;
		}
	}

	return this->polozenie;
}

void Mlecz::Rysowanie()
{
	cout << "M";
}

string Mlecz::DoNapisu()
{
	return "Mlecz[" + to_string(this->polozenie.x) + "][" + to_string(this->polozenie.y) + "]";
}

Mlecz::~Mlecz()
{
}


Guarana::Guarana(const int x, const int y, Swiat* s)
{
	this->gatunek = GUARANA;
	this->inicjatywa = 0;
	this->sila = 0;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->swiat = s;
}

Guarana::Guarana(const int x, const int y, Swiat* s, const int sila)
{
	this->gatunek = GUARANA;
	this->inicjatywa = 0;
	this->sila = sila;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->swiat = s;
}

void Guarana::Kolizja(Organizm* organizm)
{
	//organizm po zjedzeniu dostaje 3 punkty si³y
	this->swiat->DodajLog(organizm->DoNapisu() + " je " + this->DoNapisu());
	organizm->ZmienSila(boost);
	this->swiat->Walka(this, organizm);
}

void Guarana::Rysowanie()
{
	cout << "G";
}

string Guarana::DoNapisu()
{
	return "Guarana[" + to_string(this->polozenie.x) + "][" + to_string(this->polozenie.y) + "]";
}

Guarana::~Guarana()
{
}


WilczeJagody::WilczeJagody(const int x, const int y, Swiat* s)
{
	this->gatunek = WILCZE_JAGODY;
	this->inicjatywa = 0;
	this->sila = 99;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->swiat = s;
}

WilczeJagody::WilczeJagody(const int x, const int y, Swiat* s, const int sila)
{
	this->gatunek = WILCZE_JAGODY;
	this->inicjatywa = 0;
	this->sila = sila;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->swiat = s;
}

void WilczeJagody::Kolizja(Organizm* organizm)
{
	//Wilcze jagody zabijaj¹ organizm,  które je zjada
	this->swiat->DodajLog(organizm->DoNapisu() + " je " + this->DoNapisu());
	this->swiat->DodajLog(this->DoNapisu() + " zabil/a " + organizm->DoNapisu());
	this->swiat->Zabij(this);
	this->swiat->Zabij(organizm);
}

void WilczeJagody::Rysowanie()
{
	cout << "J";
}

string WilczeJagody::DoNapisu()
{
	return "Wilcze Jagody[" + to_string(this->polozenie.x) + "][" + to_string(this->polozenie.y) + "]";
}

WilczeJagody::~WilczeJagody()
{
}


BarszczSosnowskiego::BarszczSosnowskiego(const int x, const int y, Swiat* s)
{
	this->gatunek = BARSZCZ_SOSNOWSKIEGO;
	this->inicjatywa = 0;
	this->sila = 10;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->swiat = s;
}

BarszczSosnowskiego::BarszczSosnowskiego(const int x, const int y, Swiat* s, const int sila)
{
	this->gatunek = BARSZCZ_SOSNOWSKIEGO;
	this->inicjatywa = 0;
	this->sila = sila;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->swiat = s;
}

Polozenie BarszczSosnowskiego::Akcja()
{
	//barszcz sosnowskiego zabija wysztkie organizmy wokó³ niego
	Organizm* organizm;
	if ((organizm = this->swiat->KtoStoi(this->polozenie.x - 1, this->polozenie.y + 1)) != nullptr)
	{
		this->swiat->DodajLog(this->DoNapisu() + " zabil/a " + organizm->DoNapisu());
		this->swiat->Zabij(organizm);
	}
	if ((organizm = this->swiat->KtoStoi(this->polozenie.x - 1, this->polozenie.y)) != nullptr)
	{
		this->swiat->DodajLog(this->DoNapisu() + " zabil/a " + organizm->DoNapisu());
		this->swiat->Zabij(organizm);
	}
	if ((organizm = this->swiat->KtoStoi(this->polozenie.x - 1, this->polozenie.y - 1)) != nullptr)
	{
		this->swiat->DodajLog(this->DoNapisu() + " zabil/a " + organizm->DoNapisu());
		this->swiat->Zabij(organizm);
	}
	if ((organizm = this->swiat->KtoStoi(this->polozenie.x, this->polozenie.y - 1)) != nullptr)
	{
		this->swiat->DodajLog(this->DoNapisu() + " zabil/a " + organizm->DoNapisu());
		this->swiat->Zabij(organizm);
	}
	if ((organizm = this->swiat->KtoStoi(this->polozenie.x + 1, this->polozenie.y - 1)) != nullptr)
	{
		this->swiat->DodajLog(this->DoNapisu() + " zabil/a " + organizm->DoNapisu());
		this->swiat->Zabij(organizm);
	}
	if ((organizm = this->swiat->KtoStoi(this->polozenie.x + 1, this->polozenie.y)) != nullptr)
	{
		this->swiat->DodajLog(this->DoNapisu() + " zabil/a " + organizm->DoNapisu());
		this->swiat->Zabij(organizm);
	}
	if ((organizm = this->swiat->KtoStoi(this->polozenie.x + 1, this->polozenie.y + 1)) != nullptr)
	{
		this->swiat->DodajLog(this->DoNapisu() + " zabil/a " + organizm->DoNapisu());
		this->swiat->Zabij(organizm);
	}
	if ((organizm = this->swiat->KtoStoi(this->polozenie.x, this->polozenie.y + 1)) != nullptr)
	{
		this->swiat->DodajLog(this->DoNapisu() + " zabil/a " + organizm->DoNapisu());
		this->swiat->Zabij(organizm);
	}

	int czy_rozmnozy = rand() % dzielnik;
	switch (czy_rozmnozy)
	{
	case 0:
		this->swiat->DodajOrganizm(BARSZCZ_SOSNOWSKIEGO, this->polozenie.x, this->polozenie.y);
	default:
		break;
	}
	

	return this->polozenie;
}

void BarszczSosnowskiego::Kolizja(Organizm* organizm)
{
	//barszcz sosnowskiego zabija organizm, który go zjada
	this->swiat->DodajLog(organizm->DoNapisu() + " je " + this->DoNapisu());
	this->swiat->DodajLog(this->DoNapisu() + " zabil/a " + organizm->DoNapisu());
	this->swiat->Zabij(organizm);
	this->swiat->Zabij(this);
}

void BarszczSosnowskiego::Rysowanie()
{
	cout << "B";
}

string BarszczSosnowskiego::DoNapisu()
{
	return "Barszcz Sosnowskiego[" + to_string(this->polozenie.x) + "][" + to_string(this->polozenie.y) + "]";
}

BarszczSosnowskiego::~BarszczSosnowskiego()
{
}