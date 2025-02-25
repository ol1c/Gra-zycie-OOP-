#pragma once 
#include <string>

enum Gatunek {
	CZLOWIEK,
	WILK,
	OWCA,
	LIS,
	ZOLW,
	ANTYLOPA,
	TRAWA,
	MLECZ,
	GUARANA,
	WILCZE_JAGODY,
	BARSZCZ_SOSNOWSKIEGO
};

struct Polozenie
{
	int x;
	int y;
};

class Swiat;

 class Organizm {
protected:
	int sila;
	int inicjatywa;
	Polozenie polozenie;
	Gatunek gatunek;
	Swiat* swiat;
public:
	//metoda wykonuj� akcj� organizmu
	//zwraca nowe polo�onie organizmu
	virtual Polozenie Akcja() = 0;
	//metoda wywo�ywana kiedy inny organizm stanie na pole zaj�te przez ten organizm
	virtual void Kolizja(Organizm* organizm) = 0;
	//metoda, kt�ra rysuje reprezenracje organizmu na mapie
	virtual void Rysowanie() = 0;
	//metoda zwraca stringa z nazw� gatunku organizmu i jego polo�eniem
	virtual std::string DoNapisu() = 0;
	//metoda zwraca enum jakiego gatunku jest organizm
	const Gatunek JakiGatunek() const;
	//metoda zwraca si�� organizmu
	const int JakaSila() const;
	//metoda umo�liwia zmian� si�y
	//si�a += param
	void ZmienSila(const int s);
	//metoda zwraca inicjatyw� organizmu
	const int JakaInicjatywa() const;
	//metoda zwraca pozycj� organizmu
	const Polozenie JakaPozycja() const;
	//metoda zmienia pole zawieraj�ce dane o po�o�eniu organizmu
	void Przesun(const Polozenie p);
	//metoda u�ywana do zapisu stanu organizmu
	virtual std::string DoZapisu();
	virtual ~Organizm();
};