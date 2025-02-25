#pragma once
#include "Organizm.h"

//node lity
struct Element_listy {
	bool czy_zyje;
	Organizm *organizm;
	Element_listy *poprzedni;
	Element_listy *nastepny;
};

//obiekt przechowujący organizmy
 class Lista
{
	int ile_organizmow;
	Element_listy *glowa;
	Element_listy *ogon;
public:
	Lista();
	const bool CzyPusta() const;
	//metoda dodaje organizm w odpowiednim miejscu
	//sprawdza wg inicjatywy organizmu
	void DodajOrganizm(Organizm *organizm);
	//metoda zmienia id na -1 organizmu, który umarł
	//na koniec rundy zostanie on usunięty z obiektu
	void ZabijOrganizm(Organizm *organizm);
	//metoda sprząta listę z martwych organizmów
	//usuwa elementy listy i usuwa obiekty organizmów
	void Posprzataj();
	//metoda zwraca wskaźnik do pierwszego elementu (node) listy
	Element_listy* PierwszyElement();
	~Lista();
};

 //obiekt reprezentuje mapę
 //posiada wskaźniki na organizmy na odpowiednich polach
 class Mapa {
	 //dwuwymiarowa tablica wskaźników na organizmy (*array[][])
	Organizm ***macierz;
	//wysokość mapy
	int rozmiar_x;
	//szerokość mapy
	int rozmiar_y;
public:
	Mapa();
	//metoda ustawiająca rozmiar mapy
	//tworzy nową tablicę
	//nie usuwa poprzedniej
	//możliwość memory leak przy złym zastosowaniu
	void UstawRozmiar(const int rozmiar_mapy_x, const int rozmiar_mapy_y);
	//przesuwa wskaźnik organizmu
	//params: 
	// skąd:x,y;
	// dokąd:x,y;
	void Przesun(const int skad_x, const int skad_y, const int dokad_x, const int dokad_y);
	//przesuwa wskaźnik organizmu
	//params: skąd{x,y}, dokąd{x,y}
	void Przesun(const Polozenie skad, const Polozenie dokad);
	//metoda zwraca wskaźnik na organizm stojący na danym polu
	//zwraca nullptr, gdy miejsce jest nie zajęte przez żaden organizm
	Organizm *KtoStoi(const int gdzie_x, const int gdzie_y);
	//dodaje nowy organizm na mapie
	void DodajOrganizm(Organizm *organizm, const int gdzie_x, const int gdzie_y);
	//usuwa organimz z mapy
	//na wskazanym polu ustawia nullptr
	//nie usuwa obiektu organizmu
	void UsunOrganizm(const int gdzie_x, const int gdzie_y);
	//metoda zwraca czy dana pozycja znajduje się na mapie
	bool CzyNaMapie(const int x, const int y) const;
	~Mapa();
};
