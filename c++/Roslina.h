#pragma once 
#include "Organizm.h"

class Roslina :
    public Organizm
{
protected:
	//szansa na rozmnożenie
	//1 / dzielnik
	//1/50
	const int dzielnik = 50;
public:
	//podstawowa metoda akcja roślin
	Polozenie Akcja() override;
	//podstawowa metoda kolizja roślin
	void Kolizja(Organizm* organizm) override;
	~Roslina();
};

