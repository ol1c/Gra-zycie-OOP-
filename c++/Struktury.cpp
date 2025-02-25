#include "Struktury.h"
#include <iostream>

const bool Lista::CzyPusta() const
{
	if (this->glowa == nullptr && this->ogon == nullptr)
		return true;
	else
		return false;
}

Lista::Lista()
	: ile_organizmow(0), glowa(nullptr), ogon(nullptr)
{
}

void Lista::DodajOrganizm(Organizm* organizm)
{
	//dodanie pierwszego organizmu
	if (CzyPusta())
	{
		Element_listy* nowy_element = new Element_listy;
		this->glowa = nowy_element;
		this->ogon = nowy_element;
		ile_organizmow++;
		nowy_element->czy_zyje = true;
		nowy_element->organizm = organizm;
		nowy_element->poprzedni = nullptr;
		nowy_element->nastepny = nullptr;
	}
	else
	{
		Element_listy* element = this->glowa;
		//szuka miejsca w liœcie na nowy organizm
		//szuka 1 organizmu o mniejszej inicjatywie
		while (element->organizm->JakaInicjatywa() >= organizm->JakaInicjatywa())
		{
			element = element->nastepny;
			if (element == nullptr)
				break;
		}
		Element_listy* nowy_element = new Element_listy;
		ile_organizmow++;
		nowy_element->czy_zyje = true;
		nowy_element->organizm = organizm;
		//jeœli element == nullptr
		//dodaje nowy na koñcu
		if (element == nullptr)
		{
			nowy_element->nastepny = nullptr;
			nowy_element->poprzedni = this->ogon;
			this->ogon->nastepny = nowy_element;
			this->ogon = nowy_element;
		}
		//dodaje w œrodku listy przed 'element'
		else
		{
			nowy_element->nastepny = element;
			nowy_element->poprzedni = element->poprzedni;
			if (nowy_element->poprzedni == nullptr)
				this->glowa = nowy_element;
			else
				element->poprzedni->nastepny = nowy_element;
			element->poprzedni = nowy_element;
		}

	}
}

void Lista::ZabijOrganizm(Organizm* organizm)
{
	Element_listy* element_do_usuniecia = this->glowa;
	//szuka organizmu w liœcie
	while (element_do_usuniecia->organizm != organizm)
	{
		element_do_usuniecia = element_do_usuniecia->nastepny;
		if (element_do_usuniecia == nullptr)
			break;
	}
	//jeœli znaleziono organizm ustawia mu status czy_zyje na false
	if (element_do_usuniecia != nullptr)
	{
		element_do_usuniecia->czy_zyje = false;
	}
}

void Lista::Posprzataj()
{
	Element_listy* wskaznik = this->glowa;
	Element_listy* element_do_usuniecia;
	while (wskaznik != nullptr)
	{
		//szuka organizmu do usuniêcia
		while (wskaznik->czy_zyje == true)
		{
			wskaznik = wskaznik->nastepny;
			if (wskaznik == nullptr)
				break;
		}
		//jeœli znaleziono organizm to go usuwa
		if (wskaznik != nullptr)
		{
			if (wskaznik->poprzedni == nullptr)
			{
				this->glowa = wskaznik->nastepny;

				wskaznik->nastepny->poprzedni = wskaznik->poprzedni;
			}
			else if (wskaznik->nastepny == nullptr)
			{
				this->ogon = wskaznik->poprzedni;

				wskaznik->poprzedni->nastepny = wskaznik->nastepny;
			}
			else
			{
				wskaznik->poprzedni->nastepny = wskaznik->nastepny;
				wskaznik->nastepny->poprzedni = wskaznik->poprzedni;
			}
			element_do_usuniecia = wskaznik;
			wskaznik = wskaznik->nastepny;
			delete element_do_usuniecia;
		}
	}

}

Element_listy* Lista::PierwszyElement()
{
	return this->glowa;
}

Lista::~Lista()
{
	Element_listy* element = this->glowa;
	while (element != nullptr)
	{
		this->glowa = element->nastepny;
		delete element;
		element = this->glowa;
	}
}


Mapa::Mapa()
	: rozmiar_x(0), rozmiar_y(0)
{
	//mapa na starcie nie ma ¿adnego rozmiaru wiêc tablica jest pustym wskaŸnikiem
	this->macierz = nullptr;
}

void Mapa::UstawRozmiar(const int rozmiar_mapy_x, const int rozmiar_mapy_y)
{
	this->rozmiar_x = rozmiar_mapy_x;
	this->rozmiar_y = rozmiar_mapy_y;
	this->macierz = new Organizm * *[rozmiar_mapy_x];
	for (int i = 0; i < rozmiar_mapy_x; i++)
	{
		this->macierz[i] = new Organizm * [rozmiar_mapy_y];
		for (int j = 0; j < rozmiar_mapy_y; j++)
		{
			this->macierz[i][j] = nullptr;
		}
	}
}

void Mapa::Przesun(const int skad_x, const int skad_y, const int dokad_x, const int dokad_y)
{
	if (skad_x == dokad_x && skad_y == dokad_y);
	else
	{
		this->macierz[dokad_x][dokad_y] = this->macierz[skad_x][skad_y];
		this->macierz[skad_x][skad_y] = nullptr;
	}
}

void Mapa::Przesun(const Polozenie skad, const Polozenie dokad)
{
	if (skad.x == dokad.x && skad.y == dokad.y);
	else
	{
		this->macierz[dokad.x][dokad.y] = this->macierz[skad.x][skad.y];
		this->macierz[skad.x][skad.y] = nullptr;
	}
}

Organizm* Mapa::KtoStoi(const int gdzie_x, const int gdzie_y)
{
	return this->macierz[gdzie_x][gdzie_y];
}

void Mapa::DodajOrganizm(Organizm* organizm, const int gdzie_x, const int gdzie_y)
{
	this->macierz[gdzie_x][gdzie_y] = organizm;
}

void Mapa::UsunOrganizm(const int gdzie_x, const int gdzie_y)
{
	this->macierz[gdzie_x][gdzie_y] = nullptr;
}

bool Mapa::CzyNaMapie(const int x, const int y) const
{
	if (x >= 0 && x < rozmiar_x)
		if (y >= 0 && y < rozmiar_y)
			return true;

	return false;
}

Mapa::~Mapa()
{
	for (int i = 0; i < this->rozmiar_x; i++)
		delete[] this->macierz[i];
	delete[] this->macierz;
}
