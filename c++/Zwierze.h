#pragma once
#include "Organizm.h"


class Swiat;

class Zwierze : public Organizm
{
public:
	//standardowa metoda akcja dla zwierz¹t
	Polozenie Akcja() override;
	//standardowa metoda kolizja dla zwierz¹t
	void Kolizja(Organizm* organizm) override;
	~Zwierze();
};

