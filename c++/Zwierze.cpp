#include <iostream>
#include "Zwierze.h"
#include "Swiat.h"


using namespace std;





Polozenie Zwierze::Akcja()
{
	//zwierze mo¿e siê poruszyæ w losowym kierunku o 1 pole
	Polozenie p = polozenie;
	int kierunek = rand() % 4;
	while(true)
	{
		switch (kierunek)
		{
		case 0:
		{
			p.x++;
			break;
		}
		case 1:
		{
			p.x--;
			break;
		}
		case 2:
		{
			p.y++;
			break;
		}
		case 3:
		{
			p.y--;
			break;
		}
		}
		//if (p.x < 0 || p.x >= this->swiat->JakiX() || p.y < 0 || p.y >= this->swiat->JakiY())
		if (!this->swiat->CzyNaMapie(p.x, p.y))
		{
			p = polozenie;
			break;
		}
		else
			break;
	}
	return p;
}


void Zwierze::Kolizja(Organizm* organizm)
{
	//jeœli dojdzie do kolizji dwóch tych samych gatunków 
	//powstanie nowy organizm tego samego gatunku
	if (this->gatunek == organizm->JakiGatunek())
		this->swiat->DodajOrganizm(this->gatunek, this->polozenie.x, this->polozenie.y);
	//w innym przypadku dojdzie do walki
	else
		this->swiat->Walka(this, organizm);
}

Zwierze::~Zwierze()
{
}