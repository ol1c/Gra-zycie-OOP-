#include "Organizm.h"
#include "Zwierzeta.h"
#include "Swiat.h"
#include <iostream>
#include <string>

using namespace std;

Czlowiek::Czlowiek(const int x, const int y, Swiat* s)
{
	this->sila = 5;
	this->inicjatywa = 4;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->gatunek = CZLOWIEK;
	this->swiat = s;
}

Czlowiek::Czlowiek(const int x, const int y, Swiat* s, const int sila, const int umiejetnosc)
{
	this->sila = sila;
	this->inicjatywa = 4;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->gatunek = CZLOWIEK;
	this->swiat = s;
	this->umiejetnosc.trwanie = umiejetnosc;
}

Polozenie Czlowiek::Akcja()
{
	//obs³uga stanu umiejêtnoœci
	//[6,10] umiejêtnoœæ trwa
	//[1,5] umiejêtnoœæ nieaktywna, nie mo¿na jej uruchomiæ
	//[0] umiejêtnoœæ gotowa do u¿ytku
	if (umiejetnosc.trwanie != 0)
		umiejetnosc.trwanie--;

	Polozenie p = polozenie;
	char kierunek;
	//zczytuje kierunek WSAD
	//ewentualna opcja U, czyli umiejêtnoœæ
	//dowolny inny przycisk oznacza pominiêcie ruchu
	cout << "\nWSAD - poruszanie\nU - umiejetnosc\nINNY - pomin\n";
	cin >> kierunek;

	//jeœli u¿yto umiejêtnoœci mo¿na jeszcze siê ruszyæ
	if (kierunek == 'u')
	{
		//aktywacja umiêtnoœci
		if (umiejetnosc.trwanie == 0)
		{
			//trwanie = 2 * czas
			//czas = 5 tur
			//5 tur trwanie umiejêtnoœci
			//5 tur umiejêtnoœæ nie aktywna
			this->umiejetnosc.trwanie = this->umiejetnosc.czas * 2;
			cout << "\nWSAD - poruszanie\nINNY - pomin\n";
			cin >> kierunek;
		}
		while (kierunek == 'u')
		{
			cout << "Umiejetnosc nie dostepna\n";
			cin >> kierunek;
		}
	}

	switch (kierunek)
	{
		//góra
	case 'w':
	{
		p.x--;
		break;
	}
	//dó³
	case 's':
	{
		p.x++;
		break;
	}
	//lewo
	case 'a':
	{
		p.y--;
		break;
	}
	//prawo
	case 'd':
	{
		p.y++;
		break;
	}
	default:
		break;
	}
	//if (p.x < 0 || p.x >= this->swiat->JakiX() || p.y < 0 || p.y >= this->swiat->JakiY())
	if (!this->swiat->CzyNaMapie(p.x, p.y))
		p = this->polozenie;

	return p;
}

void Czlowiek::Kolizja(Organizm* organizm)
{
	//jeœli dojdzie do kolizji dwóch tych samych gatunków 
	//powstanie nowy organizm tego samego gatunku
	if (this->gatunek == organizm->JakiGatunek())
		this->swiat->DodajOrganizm(this->gatunek, this->polozenie.x, this->polozenie.y);
	else
	{
		//jeœli umiejêtnoœæ aktywna odpycha
		if (this->umiejetnosc.trwanie > this->umiejetnosc.czas)
		{
			this->swiat->PrzesunLosowo(organizm, this->JakaPozycja());
			this->swiat->DodajLog(this->DoNapisu() + " przesunal " + organizm->DoNapisu());
		}
		//jeœli umiejêtnoœæ nieaktywna to walka
		else
		{
			this->swiat->Walka(this, organizm);
		}
	}
}

void Czlowiek::Rysowanie()
{
	//gdy umiejêtnoœæ aktywna wyœwietla '$'
	if (this->umiejetnosc.trwanie > this->umiejetnosc.czas)
	{
		cout << '$';
	}
	//gdy nieaktywna wyœwietla '@'
	else
	{
		cout << '@';
	}
}

string Czlowiek::DoNapisu()
{
	return "Czlowiek[" + to_string(this->polozenie.x) + "][" + to_string(this->polozenie.y) + "]";
}

string Czlowiek::DoZapisu()
{
	return (to_string(this->gatunek) + " " + to_string(this->polozenie.x) + " " + to_string(this->polozenie.y) + " " + to_string(this->sila) + " " + to_string(this->umiejetnosc.trwanie) + "\n");
}

Czlowiek::~Czlowiek()
{
}


Wilk::Wilk(const int x, const int y, Swiat* s)
{
	this->sila = 9;
	this->inicjatywa = 5;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->gatunek = WILK;
	this->swiat = s;
}

Wilk::Wilk(const int x, const int y, Swiat* s, const int sila)
{
	this->sila = sila;
	this->inicjatywa = 5;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->gatunek = WILK;
	this->swiat = s;
}

void Wilk::Rysowanie()
{
	cout << "W";
}

std::string Wilk::DoNapisu()
{
	return "Wilk[" + to_string(this->polozenie.x) + "][" + to_string(this->polozenie.y) + "]";
}

Wilk::~Wilk()
{
}


Owca::Owca(const int x, const int y, Swiat* s)
{
	this->sila = 4;
	this->inicjatywa = 4;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->gatunek = OWCA;
	this->swiat = s;
}

Owca::Owca(const int x, const int y, Swiat* s, const int sila)
{
	this->sila = sila;
	this->inicjatywa = 4;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->gatunek = OWCA;
	this->swiat = s;
}

void Owca::Rysowanie()
{
	cout << "O";
}

std::string Owca::DoNapisu()
{
	return "Owca[" + to_string(this->polozenie.x) + "][" + to_string(this->polozenie.y) + "]";
}

Owca::~Owca()
{
}


Lis::Lis(const int x, const int y, Swiat* s)
{
	this->sila = 3;
	this->inicjatywa = 7;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->gatunek = LIS;
	this->swiat = s;
}

Lis::Lis(const int x, const int y, Swiat* s, const int sila)
{
	this->sila = sila;
	this->inicjatywa = 7;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->gatunek = LIS;
	this->swiat = s;
}

bool Lis::CzyMocniejszy(const Polozenie& p) const
{
	Organizm* przeciwnik;
	przeciwnik = this->swiat->KtoStoi(p.x, p.y);
	if (przeciwnik == nullptr || przeciwnik->JakaSila() < this->sila)
		return true;
	else
		return false;
}

Polozenie Lis::Akcja()
{
	Polozenie p = polozenie;
	int kierunek = rand() % 4;
	//lis nie poruszy siê na pole zajmowane przez mocniejszego przeciwnika
	for (int i = 0; i < 4; i++)
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
		else if (CzyMocniejszy(p))
			break;
		
		kierunek = (++kierunek) % 4;
	}

	return p;
}

void Lis::Rysowanie()
{
	cout << "L";
}

std::string Lis::DoNapisu()
{
	return "Lis[" + to_string(this->polozenie.x) + "][" + to_string(this->polozenie.y) + "]";
}

Lis::~Lis()
{
}


Zolw::Zolw(const int x, const int y, Swiat* s)
{
	this->sila = 2;
	this->inicjatywa = 1;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->gatunek = ZOLW;
	this->swiat = s;
}

Zolw::Zolw(const int x, const int y, Swiat* s, const int sila)
{
	this->sila = sila;
	this->inicjatywa = 1;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->gatunek = ZOLW;
	this->swiat = s;
}

Polozenie Zolw::Akcja()
{
	Polozenie p = polozenie;
	int czy_ruszy = rand() % 4;
	//¿ó³w ma 75% szans na to siê nie ruszy
	switch (czy_ruszy)
	{
	case 0:
	{
		int kierunek = rand() % 4;
		while (true)
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
		break;
	}
	default:
		break;
	}

	return p;
}

void Zolw::Kolizja(Organizm* organizm)
{
	//jeœli dojdzie do kolizji dwóch tych samych gatunków 
	//powstanie nowy organizm tego samego gatunku
	if (this->gatunek == organizm->JakiGatunek())
		this->swiat->DodajOrganizm(this->gatunek, this->polozenie.x, this->polozenie.y);
	else
	{
		//¿ó³w mo¿e odbiæ atak organizmu, kyórego si³a jest mniejsza ni¿ 5
		if (organizm->JakaSila() < 5)
			this->swiat->PrzesunLosowo(organizm, this->JakaPozycja());
		else
			this->swiat->Walka(this, organizm);
	}
}

void Zolw::Rysowanie()
{
	cout << "Z";
}

std::string Zolw::DoNapisu()
{
	return "Zolw[" + to_string(this->polozenie.x) + "][" + to_string(this->polozenie.y) + "]";
}

Zolw::~Zolw()
{
}


Antylopa::Antylopa(const int x, const int y, Swiat* s)
{
	this->sila = 4;
	this->inicjatywa = 4;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->gatunek = ANTYLOPA;
	this->swiat = s;
}

Antylopa::Antylopa(const int x, const int y, Swiat* s, const int sila)
{
	this->sila = sila;
	this->inicjatywa = 4;
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->gatunek = ANTYLOPA;
	this->swiat = s;
}

Polozenie Antylopa::Akcja()
{
	Polozenie p = polozenie;
	int kierunek = rand() % 8;
	//antylopa mo¿e poruszyæ siê o 2 pola w danym kierunku
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
		case 4:
		{
			p.x += 2;
			break;
		}
		case 5:
		{
			p.x -= 2;
			break;
		}
		case 6:
		{
			p.y += 2;
			break;
		}
		case 7:
		{
			p.y -= 2;
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

void Antylopa::Kolizja(Organizm* organizm)
{
	//jeœli dojdzie do kolizji dwóch tych samych gatunków 
	//powstanie nowy organizm tego samego gatunku
	if (this->gatunek == organizm->JakiGatunek())
		this->swiat->DodajOrganizm(this->gatunek, this->polozenie.x, this->polozenie.y);
	else
	{
		//antylopa ma 50% szans na ucieczkê z walki
		int ucieczka = rand() % 2;
		switch (ucieczka)
		{
		case 0:
			this->swiat->Walka(this, organizm);
		default:
			break;
		}
	}
}

void Antylopa::Rysowanie()
{
	cout << "A";
}

std::string Antylopa::DoNapisu()
{
	return "Antylopa[" + to_string(this->polozenie.x) + "][" + to_string(this->polozenie.y) + "]";
}

Antylopa::~Antylopa()
{
}
