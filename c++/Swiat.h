#pragma once
#include "Struktury.h"
#include <string>

enum Gatunek;

//obiekt zawierające wszelkie dane dotyczące symulowanego świata
 class Swiat {
	 //obiekt reprezentujący mapę
	 //przechowuje wskaźniki na organizmy
	Mapa mapa;
	//obiekt przechowujący wszystkie organizmy
	//w kolejności według inicjatywy i wieku
	Lista spis;
	//wysokość mapy
	int x;
	//szerokość mapy
	int y;
	//pole przechowujące wszelkie logi z danej tury
	std::string logi;

	//prywatna metoda
	//czyści konsolę
	void WyczyscKonsole() const;
	//metoda ustawiająca początkową populację
	void PoczatkowaPopulacja();
	//metoda rusująca świat (mapę)
	void RysujSwiat();
	//metoda symulująca jedną turę
	void WykonajTure();
	//metoda umożliwiająca wyświetlenie logów
	void WyswietlLogi() const;
	//metoda czyszcząca logi
	void WyczyscLogi();
	//metoda umożliwia dodanie organizmu
	//jako parametr podaje się enum gatunku
	//współrzędne położenia nowego organizmu
	//oraz jego siłę
	//*metoda używana tylko przy odczycie stanu świata z pliku
	void DodajOrganizm(const Gatunek& gatunek, const int& x, const int& y, const int& sila);
	//metoda umożliwia dodanie organizmu
	//jako parametr podaje się enum gatunku
	//współrzędne położenia nowego organizmu
	//jego siłę
	//oraz informacje o umiejetnosci (czas użycia)
	//*metoda używana tylko przy odczycie stanu świata z pliku
	//*metoda używana tylko dla człowieka
	void DodajOrganizm(const Gatunek& gatunek, const int& x, const int& y, const int& sila, const int& umiejetnosc);
public:
	//konstruktor tworzy nowy świat
	//który rozmiary mapy wczytuje z klawiatury
	//i ustawia początkową populację wg metody PoczatkowaPoluacja()
	Swiat();
	//konstruktor tworzy nowy świat
	//który rozmiary mapy wczytuje z parametrów
	//i ustawia początkową populację wg metody PoczatkowaPoluacja()
	Swiat(const int rozmiar_mapy_x, const int rozmiar_mapy_y);
	//konstruktor tworzy nowy świat
	//wszelkie dane o mapie i organizmach są wczytywane z pliku
	//nazwa pliku podawana jest w parametrze
	Swiat(const std::string nazwa);
	//metoda umożliwia dodanie organizmu
	//jako parametr podaje się enum gatunku
	//i współrzędne położenia nowego organizmu
	//metoda sprawdza czy jest miejsce
	//jeśli podane pole jest zajęte sprawdza pola obok (+-1 pole)
	//jeśli nie ma wolnego miesca w sąsiectwie dodaje wpis do logów
	void DodajOrganizm(const Gatunek& gatunek, const int x, const int y);
	//metoda umożliwia kompletną symulację świata
	void Symulacja();
	//metoda zwraca wskaźnik na organizm stojący na danym polu
	//zwraca nullptr, kiedy pole jest puste
	Organizm* KtoStoi(const int gdzie_x, const int gdzie_y);
	//metoda umożliwia dodanie logu
	void DodajLog(const std::string log);
	//metoda symuluję walkę dwóch organizmów
	//1 parametr to wkaźnik na atakowany organizm
	//2 parametr to wskaźnik na atakujący organizm
	void Walka(Organizm* organimz_1, Organizm* organizm_2);
	//zwraca wysokość mapy
	int JakiX() const;
	//zwraca szerokość mapy
	int JakiY() const;
	//metoda przesuwa wskazany organizm na losowe pole w sąsiectwie podanego położenia
	void PrzesunLosowo(Organizm* organizm, Polozenie p);
	//metoda zabija wskazywany przez parametr organizm
	void Zabij(Organizm* organizm);
	//metoda sprawdza czy podane położenie znajduje się na mapie
	//true tak
	//false nie
	bool CzyNaMapie(const int x, const int y) const;
	~Swiat();
};