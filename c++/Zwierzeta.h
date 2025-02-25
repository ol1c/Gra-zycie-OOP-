#pragma once
//plik zawiera wsztstkie klasy Zwierz�t (poza nieobowi�zkow� Cyber Owc�)
#include "Zwierze.h"
#include <string>

 struct Umiejetnosc {
	const int czas = 5;
	int trwanie = 0;
};

 class Swiat;

 //Cz�owiek porusza si� wg instrukcji u�ytkownika
class Czlowiek : public Zwierze
{
	//tarcza alazura
	Umiejetnosc umiejetnosc;
public:
    Czlowiek(const int x, const int y, Swiat* s);
    Czlowiek(const int x, const int y, Swiat* s, const int sila, const int umiejetnosc);
	//podczas akcji cz�owiek wczytuje kierunek i przemieszcza si�
	//u�ytkownik mo�e si� nie ruszy� podaj�c odpowiedni parametr
	Polozenie Akcja() override;
	//podczas kolizji z cz�owiekiem, normalnie organizm wejdzie w walko
	//w sytuacj, gdy cz�owiek ma aktywn� tarcz�, cz�owiek odstrasza organizm
	void Kolizja(Organizm* organizm) override;
	void Rysowanie() override;
	std::string DoNapisu() override;
	std::string DoZapisu() override;
	~Czlowiek();
};

class Wilk :
    public Zwierze
{
public:
	Wilk(const int x, const int y, Swiat* s);
	Wilk(const int x, const int y, Swiat* s, const int sila);
	void Rysowanie() override;
	std::string DoNapisu() override;
	~Wilk();
};

class Owca :
    public Zwierze
{
public:
	Owca(const int x, const int y, Swiat* s);
	Owca(const int x, const int y, Swiat* s, const int sila);
	void Rysowanie() override;
	std::string DoNapisu() override;
	~Owca();
};

//lis nie wywo�a walki z mocniejszym organizmem
class Lis :
    public Zwierze
{
	//metoda sprawdzaj�ca czy na danej pozycji znajduje si� silniejszy organizm
	//zwraca true je�li lis jest silniejszy lub pole jest puste
	//zwraca false je�li organizm na danej pozycji jest silniejszy od lisa
	bool CzyMocniejszy(const Polozenie& p) const;
public:
	Lis(const int x, const int y, Swiat* s);
	Lis(const int x, const int y, Swiat* s, const int sila);
	void Rysowanie() override;
	std::string DoNapisu() override;
	//lis podczas akcji nie porusza si� na miejsce zajmowane przez silniejszy organizm
	Polozenie Akcja() override;
	~Lis();
};

//��w nie zawsze si� rusz, mo�e odstarszy� s�aby organizm
class Zolw :
    public Zwierze
{
public:
	Zolw(const int x, const int y, Swiat* s);
	Zolw(const int x, const int y, Swiat* s, const int sila);
	void Rysowanie() override;
	std::string DoNapisu() override;
	//��w mo�e si� nie ruszy� podczas swojej tury
	Polozenie Akcja() override;
	//��w odstrasza organizmy s�absze ni� 5 (sila < 5)
	void Kolizja(Organizm* organizm) override;
	~Zolw();
};

//antylopa mo�e si� porusza� o 2 jednostyki i ma 50% szans na ucieczk� z walki
class Antylopa :
    public Zwierze
{
public:
	Antylopa(const int x, const int y, Swiat* s);
	Antylopa(const int x, const int y, Swiat* s, const int sila);
	//antylopa mo�e skoczy� o 2 pola zamiast normalnego ruchu
	Polozenie Akcja() override;
	//antylopa ma 50%szans na ucieczk�
	void Kolizja(Organizm* organizm) override;
	void Rysowanie() override;
	std::string DoNapisu() override;
	~Antylopa();
};



