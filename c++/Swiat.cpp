#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Swiat.h"
#include "Struktury.h"
#include "Organizm.h"
#include "Zwierzeta.h"
#include "Rosliny.h"


using namespace std;

Swiat::Swiat()
{
	int wysokosc, szerokosc;
	cout << "Wymiary mapy:\n";
	cout << "Wysokosc: ";
	cin >> wysokosc;
	cout << "Szerokosc: ";
	cin >> szerokosc;
	while (wysokosc < 4 && szerokosc < 4)
	{
		cout << "Za mala mapa.Podaj jescze raz.\n";
		cout << "Wysokosc: ";
		cin >> wysokosc;
		cout << "Szerokosc: ";
		cin >> szerokosc;
	}
	WyczyscKonsole();
	this->x = wysokosc;
	this->y = szerokosc;
	this->mapa.UstawRozmiar(wysokosc, szerokosc);
	this->logi = "";
	PoczatkowaPopulacja();

}

Swiat::Swiat(const int rozmiar_mapy_x, const int rozmiar_mapy_y)
	:x(rozmiar_mapy_x), y(rozmiar_mapy_y)
{
	WyczyscKonsole();
	this->mapa.UstawRozmiar(rozmiar_mapy_x, rozmiar_mapy_y);
	this->logi = "";
	PoczatkowaPopulacja();
}

Swiat::Swiat(const string nazwa)
{
	ifstream plik(nazwa);
	if (!plik.is_open()) {
		cout << "Nie mo¿na otworzyæ pliku!";
		return;
	}

	int rozmiar_mapy_x, rozmiar_mapy_y;
	WyczyscKonsole();
	
	plik >> rozmiar_mapy_x >> rozmiar_mapy_y;
	this->x = rozmiar_mapy_x;
	this->y = rozmiar_mapy_y;
	this->mapa.UstawRozmiar(rozmiar_mapy_x, rozmiar_mapy_y);
	this->logi = "";
	Polozenie p;
	int sila, gatunek, umiejetnosc;
	Gatunek g;
	while (!plik.eof())
	{
		plik >> gatunek >> p.x >> p.y >> sila;
		switch (gatunek)
		{
		case CZLOWIEK:
		{
			g = CZLOWIEK;
			plik >> umiejetnosc;
			break;
		}
		case WILK:
		{
			g = WILK;
			break;
		}
		case OWCA:
		{
			g = OWCA;
			break;
		}
		case LIS:
		{
			g = LIS;
			break;
		}
		case ZOLW:
		{
			g = ZOLW;
			break;
		}
		case ANTYLOPA:
		{
			g = ANTYLOPA;
			break;
		}
		case TRAWA:
		{
			g = TRAWA;
			break;
		}
		case MLECZ:
		{
			g = MLECZ;
			break;
		}
		case GUARANA:
		{
			g = GUARANA;
			break;
		}
		case WILCZE_JAGODY:
		{
			g = WILCZE_JAGODY;
			break;
		}
		case BARSZCZ_SOSNOWSKIEGO:
		{
			g = BARSZCZ_SOSNOWSKIEGO;
			break;
		}
		}
		if (g == CZLOWIEK)
			DodajOrganizm(g, p.x, p.y, sila, umiejetnosc);
		else
			DodajOrganizm(g, p.x, p.y, sila);
	}
}

void Swiat::Symulacja()
{
	char wejscie;
	bool czy_grac = true;
	while(czy_grac)
	{
		WyczyscLogi();
		RysujSwiat();
		WykonajTure();
		RysujSwiat();
		DodajLog("\nKoniec tury.\nZ - zapis   X - wyjdz   INNE - kontynuuj");
		WyswietlLogi();
		cin >> wejscie;
		switch (wejscie)
		{
		case 'z':
		{
			string nazwa_pliku;
			cout << u8"Podaj nazwê pliku do zapisu:\n";
			cin >> nazwa_pliku;
			ofstream plik(nazwa_pliku);
			if (!plik.is_open()) {
				WyczyscKonsole();
				cout << u8"Nie mo¿na otworzyæ pliku!\nPodaj nazwê jeszcze raz:\n";
				cin >> nazwa_pliku;
			}
			else
			{
				plik << this->x << endl << this->y << endl;
				Element_listy* do_zapisu = this->spis.PierwszyElement();
				Polozenie p;
				int sila, gatunek;
				while (do_zapisu != nullptr)
				{
					plik << do_zapisu->organizm->DoZapisu();
					do_zapisu = do_zapisu->nastepny;
				}
				WyczyscKonsole();
				cout << "Stan zapisany do pliku: " << nazwa_pliku << endl;
				cin >> nazwa_pliku;
			}
			break;
		}
		case 'x':
		{
			czy_grac = false;
			break;
		}
		default:
			break;
		}
	}
}

void Swiat::PoczatkowaPopulacja()
{
	DodajOrganizm(CZLOWIEK, rand() % this->x, rand() % this->y);
	DodajOrganizm(WILK, rand() % this->x, rand() % this->y);
	DodajOrganizm(WILK, rand() % this->x, rand() % this->y);
	DodajOrganizm(ZOLW, rand() % this->x, rand() % this->y);
	DodajOrganizm(ZOLW, rand() % this->x, rand() % this->y);
	DodajOrganizm(OWCA, rand() % this->x, rand() % this->y);
	DodajOrganizm(OWCA, rand() % this->x, rand() % this->y);
	DodajOrganizm(OWCA, rand() % this->x, rand() % this->y);
	DodajOrganizm(LIS, rand() % this->x, rand() % this->y);
	DodajOrganizm(LIS, rand() % this->x, rand() % this->y);
	DodajOrganizm(ANTYLOPA, rand() % this->x, rand() % this->y);
	DodajOrganizm(ANTYLOPA, rand() % this->x, rand() % this->y);
	DodajOrganizm(ANTYLOPA, rand() % this->x, rand() % this->y);
	DodajOrganizm(TRAWA, rand() % this->x, rand() % this->y);
	DodajOrganizm(TRAWA, rand() % this->x, rand() % this->y);
	DodajOrganizm(MLECZ, rand() % this->x, rand() % this->y);
	DodajOrganizm(GUARANA, rand() % this->x, rand() % this->y);
	DodajOrganizm(GUARANA, rand() % this->x, rand() % this->y);
	DodajOrganizm(WILCZE_JAGODY, rand() % this->x, rand() % this->y);
	DodajOrganizm(WILCZE_JAGODY, rand() % this->x, rand() % this->y);
	DodajOrganizm(BARSZCZ_SOSNOWSKIEGO, rand() % this->x, rand() % this->y);
}


void Swiat::RysujSwiat()
{
	WyczyscKonsole();
	for (int j = 0; j <= this->y * 2 + 2; j++)
		cout << "=";
	for (int i = 0; i < this->x; i++)
	{
		cout << "\n+";
		for (int j = 0; j < this->y; j++)
		{
			cout << " ";
			if (mapa.KtoStoi(i, j) == nullptr)
				cout << " ";
			else
				mapa.KtoStoi(i, j)->Rysowanie();
		}
		cout << " +";
	}
	cout << "\n";
	for (int j = 0; j <= this->y * 2 + 2; j++)
		cout << "=";


}


void Swiat::WykonajTure()
{
	Element_listy* obslugiwany_organizm = this->spis.PierwszyElement();
	Polozenie przemieszczenie;
	Organizm* organizm_2;
	while (obslugiwany_organizm != nullptr)
	{
		//jeœli organizm ¿yje to wykonuje swoj¹ ture
		if (obslugiwany_organizm->czy_zyje == true)
		{
			//wykonanie akcji, która zwraca nowe po³o¿enie organizmu
			przemieszczenie = obslugiwany_organizm->organizm->Akcja();
			organizm_2 = this->mapa.KtoStoi(przemieszczenie.x, przemieszczenie.y);
			//jeœli ktoœ stoi na tym miejscu i nie jest to ten sam organizm
			//dochodzi do kolizji z 2 organizmem
			if (organizm_2 != nullptr && organizm_2 != obslugiwany_organizm->organizm)
			{
				//wywo³anie kolizji
				organizm_2->Kolizja(obslugiwany_organizm->organizm);
			}
			//przesuniêcie organizmu na wskazane po³o¿enie
			else
			{
				//cout << obslugiwany_organizm->organizm->JakaPozycja().x << " " << obslugiwany_organizm->organizm->JakaPozycja().y << " -> " << przemieszczenie.x << " " << przemieszczenie.y << "\n";

				this->mapa.Przesun(obslugiwany_organizm->organizm->JakaPozycja(), przemieszczenie);
				obslugiwany_organizm->organizm->Przesun(przemieszczenie);
			}
			//RysujSwiat();
		}

		obslugiwany_organizm = obslugiwany_organizm->nastepny;
	}
	this->spis.Posprzataj();
}


void Swiat::DodajOrganizm(const Gatunek& gatunek, const int x, const int y)
{
	int nowy_x = x, nowy_y = y;
	
	//sprawdza czy jest miejsce na mapie w skazanym po³o¿eniu
	//lub w otoczeniu
	if (mapa.CzyNaMapie(x, y) && mapa.KtoStoi(x, y) == nullptr);
	else if (mapa.CzyNaMapie(x + 1, y + 1) && mapa.KtoStoi(x + 1, y + 1) == nullptr)
	{
		nowy_x++;
		nowy_y++;
	}
	else if (mapa.CzyNaMapie(x + 1, y - 1) && mapa.KtoStoi(x + 1, y - 1) == nullptr)
	{
		nowy_x++;
		nowy_y--;
	}
	else if (mapa.CzyNaMapie(x + 1, y) && mapa.KtoStoi(x + 1, y) == nullptr)
	{
		nowy_x--;
	}
	else if (mapa.CzyNaMapie(x, y + 1) && mapa.KtoStoi(x, y + 1) == nullptr)
	{
		nowy_y++;
	}
	else if (mapa.CzyNaMapie(x, y - 1) && mapa.KtoStoi(x , y - 1) == nullptr)
	{
		nowy_y--;
	}
	else if (mapa.CzyNaMapie(x - 1, y + 1) && mapa.KtoStoi(x - 1, y + 1) == nullptr)
	{
		nowy_x--;
		nowy_y++;
	}
	else if (mapa.CzyNaMapie(x - 1, y) && mapa.KtoStoi(x - 1, y) == nullptr)
	{
		nowy_x--;
	}
	else if (mapa.CzyNaMapie(x - 1, y - 1) && mapa.KtoStoi(x - 1, y - 1) == nullptr)
	{
		nowy_x--;
		nowy_y--;
	}
	//jeœli nie znaleziono miejsca ustawia koordynaty na -1
	else
	{
		nowy_x = -1;
		nowy_y = -1;
	}

	//jeœli znaleziono miejsce dodaje organizm
	if(nowy_x != -1 && nowy_y != -1)
	{
		Organizm* nowy_organizm;
		switch (gatunek)
		{
		case CZLOWIEK:
		{
			nowy_organizm = new Czlowiek(nowy_x, nowy_y, this);
			break;
		}
		case WILK:
		{
			nowy_organizm = new Wilk(nowy_x, nowy_y, this);
			break;
		}
		case OWCA:
		{
			nowy_organizm = new Owca(nowy_x, nowy_y, this);
			break;
		}
		case LIS:
		{
			nowy_organizm = new Lis(nowy_x, nowy_y, this);
			break;
		}
		case ZOLW:
		{
			nowy_organizm = new Zolw(nowy_x, nowy_y, this);
			break;
		}
		case ANTYLOPA:
		{
			nowy_organizm = new Antylopa(nowy_x, nowy_y, this);
			break;
		}
		default:
		{
			nowy_organizm = new Antylopa(nowy_x, nowy_y, this);
			break;
		}
		case TRAWA:
		{
			nowy_organizm = new Trawa(nowy_x, nowy_y, this);
			break;
		}
		case MLECZ:
		{
			nowy_organizm = new Mlecz(nowy_x, nowy_y, this);
			break;
		}
		case GUARANA:
		{
			nowy_organizm = new Guarana(nowy_x, nowy_y, this);
			break;
		}
		case WILCZE_JAGODY:
		{
			nowy_organizm = new WilczeJagody(nowy_x, nowy_y, this);
			break;
		}
		case BARSZCZ_SOSNOWSKIEGO:
		{
			nowy_organizm = new BarszczSosnowskiego(nowy_x, nowy_y, this);
			break;
		}
		}
		this->mapa.DodajOrganizm(nowy_organizm, nowy_x, nowy_y);
		this->spis.DodajOrganizm(nowy_organizm);
		string log = "Nowy organizm: ";
		log += nowy_organizm->DoNapisu();
		DodajLog(log);
	}
	else
	{
		DodajLog("Brak miejsca aby dodac organizm");
	}
}


void Swiat::DodajOrganizm(const Gatunek& gatunek, const int& x, const int& y, const int& sila)
{
	Organizm* nowy_organizm;
	switch (gatunek)
	{
	case WILK:
	{
		nowy_organizm = new Wilk(x, y, this, sila);
		break;
	}
	case OWCA:
	{
		nowy_organizm = new Owca(x, y, this, sila);
		break;
	}
	case LIS:
	{
		nowy_organizm = new Lis(x, y, this, sila);
		break;
	}
	case ZOLW:
	{
		nowy_organizm = new Zolw(x, y, this, sila);
		break;
	}
	case ANTYLOPA:
	{
		nowy_organizm = new Antylopa(x, y, this, sila);
		break;
	}
	default:
	{
		nowy_organizm = new Antylopa(x, y, this, sila);
		break;
	}
	case TRAWA:
	{
		nowy_organizm = new Trawa(x, y, this, sila);
		break;
	}
	case MLECZ:
	{
		nowy_organizm = new Mlecz(x, y, this, sila);
		break;
	}
	case GUARANA:
	{
		nowy_organizm = new Guarana(x, y, this, sila);
		break;
	}
	case WILCZE_JAGODY:
	{
		nowy_organizm = new WilczeJagody(x, y, this, sila);
		break;
	}
	case BARSZCZ_SOSNOWSKIEGO:
	{
		nowy_organizm = new BarszczSosnowskiego(x, y, this, sila);
		break;
	}
	}
	this->mapa.DodajOrganizm(nowy_organizm, x, y);
	this->spis.DodajOrganizm(nowy_organizm);
	string log = "Nowy organizm: ";
	log += nowy_organizm->DoNapisu();
	
}


void Swiat::DodajOrganizm(const Gatunek& gatunek, const int& x, const int& y, const int& sila, const int& umiejetnosc)
{
		Organizm* nowy_organizm = new Czlowiek(x, y, this, sila, umiejetnosc);
		
		this->mapa.DodajOrganizm(nowy_organizm, x, y);
		this->spis.DodajOrganizm(nowy_organizm);
		string log = "Nowy organizm: ";
		log += nowy_organizm->DoNapisu();
		DodajLog(log);
	
}


Organizm* Swiat::KtoStoi(const int gdzie_x, const int gdzie_y)
{
	return this->mapa.KtoStoi(gdzie_x, gdzie_y);
}


int Swiat::JakiX() const
{
	return this->x;
}


int Swiat::JakiY() const
{
	return this->y;
}


void Swiat::WyczyscKonsole() const
{
	system("cls");
}


void Swiat::WyswietlLogi() const
{
	cout << this->logi << "\n";
}


void Swiat::WyczyscLogi()
{
	this->logi = "";
}


void Swiat::DodajLog(const string log)
{
	this->logi += "\n";
	this->logi += log;
}


void Swiat::Walka(Organizm* organizm_1, Organizm* organizm_2)
{
	Polozenie p;
	string log = "";
	if (organizm_1->JakaSila() > organizm_2->JakaSila())
	{
		log += organizm_1->DoNapisu();
		log += " zabil/a ";
		log += organizm_2->DoNapisu();
		p = organizm_2->JakaPozycja();
		this->mapa.UsunOrganizm(p.x, p.y);
		this->spis.ZabijOrganizm(organizm_2);
		DodajLog(log);

	}
	else
	{
		log += organizm_2->DoNapisu();
		log += " zabil/a ";
		log += organizm_1->DoNapisu();
		p = organizm_1->JakaPozycja();
		this->mapa.UsunOrganizm(p.x, p.y);
		this->spis.ZabijOrganizm(organizm_1);
		DodajLog(log);
	}
}


void Swiat::PrzesunLosowo(Organizm* organizm, Polozenie p)
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
		if (!this->mapa.CzyNaMapie(p.x, p.y))
			p = organizm->JakaPozycja();
		else if (this->mapa.KtoStoi(p.x, p.y) != nullptr)
		{
			if (this->mapa.KtoStoi(p.x, p.y) != organizm)
			{
				p = organizm->JakaPozycja();
				break;
			}
			else
				kierunek = (++kierunek) % 4;
		}
		else
			break;
	}

	this->mapa.Przesun(organizm->JakaPozycja(), p);
}


void Swiat::Zabij(Organizm* organizm)
{
	//pobranie pozycji organizmu
	Polozenie p = organizm->JakaPozycja();
	//ustawienie nullptr na mapie
	this->mapa.UsunOrganizm(p.x, p.y);
	//zabija organizm w liœcie
	//czy_zyje = false
	this->spis.ZabijOrganizm(organizm);
}


bool Swiat::CzyNaMapie(const int x, const int y) const
{
	return this->mapa.CzyNaMapie(x, y);
}


Swiat::~Swiat()
{
	WyczyscKonsole();
}