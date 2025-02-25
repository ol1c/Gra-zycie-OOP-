#pragma once
//plik zawiera wsztstkie klasy Roœlin
#include "Roslina.h"
#include <string>

class Swiat;

class Trawa :public Roslina
{
public:
	Trawa(const int x, const int y, Swiat* s);
	Trawa(const int x, const int y, Swiat* s, const int sila);
	void Rysowanie() override;
	std::string DoNapisu() override;
	~Trawa();
};

//mlecz podejmuje 3 próby 
class Mlecz :public Roslina
{
public:
	Mlecz(const int x, const int y, Swiat* s);
	Mlecz(const int x, const int y, Swiat* s, const int sila);
	Polozenie Akcja() override;
	void Rysowanie() override;
	std::string DoNapisu() override;
	~Mlecz();
};

//po zjedzeiu Guarany organizm dostaje +3 punktów si³y na sta³e
class Guarana :public Roslina
{
	const int boost = 3;
public:
	Guarana(const int x, const int y, Swiat* s);
	Guarana(const int x, const int y, Swiat* s, const int sila);
	void Kolizja(Organizm* organizm) override;
	void Rysowanie() override;
	std::string DoNapisu() override;
	~Guarana();
};

//ka¿dy organizm, który zje wilcze jagody umiera
class WilczeJagody :public Roslina
{
public:
	WilczeJagody(const int x, const int y, Swiat* s);
	WilczeJagody(const int x, const int y, Swiat* s, const int sila);
	void Kolizja(Organizm* organizm) override;
	void Rysowanie() override;
	std::string DoNapisu() override;
	~WilczeJagody();
};

//barsz sosnowskiego jest truj¹cy
//zabija ka¿dy organizm, który go zje lub stoi w pobli¿u
class BarszczSosnowskiego :public Roslina
{
public:
	BarszczSosnowskiego(const int x, const int y, Swiat* s);
	BarszczSosnowskiego(const int x, const int y, Swiat* s, const int sila);
	Polozenie Akcja() override;
	void Kolizja(Organizm* organizm) override;
	void Rysowanie() override;
	std::string DoNapisu() override;
	~BarszczSosnowskiego();
};