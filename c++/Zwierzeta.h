#pragma once
//plik zawiera wsztstkie klasy Zwierz¹t (poza nieobowi¹zkow¹ Cyber Owc¹)
#include "Zwierze.h"
#include <string>

 struct Umiejetnosc {
	const int czas = 5;
	int trwanie = 0;
};

 class Swiat;

 //Cz³owiek porusza siê wg instrukcji u¿ytkownika
class Czlowiek : public Zwierze
{
	//tarcza alazura
	Umiejetnosc umiejetnosc;
public:
    Czlowiek(const int x, const int y, Swiat* s);
    Czlowiek(const int x, const int y, Swiat* s, const int sila, const int umiejetnosc);
	//podczas akcji cz³owiek wczytuje kierunek i przemieszcza siê
	//u¿ytkownik mo¿e siê nie ruszyæ podaj¹c odpowiedni parametr
	Polozenie Akcja() override;
	//podczas kolizji z cz³owiekiem, normalnie organizm wejdzie w walko
	//w sytuacj, gdy cz³owiek ma aktywn¹ tarczê, cz³owiek odstrasza organizm
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

//lis nie wywo³a walki z mocniejszym organizmem
class Lis :
    public Zwierze
{
	//metoda sprawdzaj¹ca czy na danej pozycji znajduje siê silniejszy organizm
	//zwraca true jeœli lis jest silniejszy lub pole jest puste
	//zwraca false jeœli organizm na danej pozycji jest silniejszy od lisa
	bool CzyMocniejszy(const Polozenie& p) const;
public:
	Lis(const int x, const int y, Swiat* s);
	Lis(const int x, const int y, Swiat* s, const int sila);
	void Rysowanie() override;
	std::string DoNapisu() override;
	//lis podczas akcji nie porusza siê na miejsce zajmowane przez silniejszy organizm
	Polozenie Akcja() override;
	~Lis();
};

//¿ó³w nie zawsze siê rusz, mo¿e odstarszyæ s³aby organizm
class Zolw :
    public Zwierze
{
public:
	Zolw(const int x, const int y, Swiat* s);
	Zolw(const int x, const int y, Swiat* s, const int sila);
	void Rysowanie() override;
	std::string DoNapisu() override;
	//¿ó³w mo¿e siê nie ruszyæ podczas swojej tury
	Polozenie Akcja() override;
	//¿ó³w odstrasza organizmy s³absze ni¿ 5 (sila < 5)
	void Kolizja(Organizm* organizm) override;
	~Zolw();
};

//antylopa mo¿e siê poruszaæ o 2 jednostyki i ma 50% szans na ucieczkê z walki
class Antylopa :
    public Zwierze
{
public:
	Antylopa(const int x, const int y, Swiat* s);
	Antylopa(const int x, const int y, Swiat* s, const int sila);
	//antylopa mo¿e skoczyæ o 2 pola zamiast normalnego ruchu
	Polozenie Akcja() override;
	//antylopa ma 50%szans na ucieczkê
	void Kolizja(Organizm* organizm) override;
	void Rysowanie() override;
	std::string DoNapisu() override;
	~Antylopa();
};



