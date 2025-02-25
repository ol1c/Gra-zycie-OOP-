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
	//metoda wykonujê akcjê organizmu
	//zwraca nowe polo¿onie organizmu
	virtual Polozenie Akcja() = 0;
	//metoda wywo³ywana kiedy inny organizm stanie na pole zajête przez ten organizm
	virtual void Kolizja(Organizm* organizm) = 0;
	//metoda, która rysuje reprezenracje organizmu na mapie
	virtual void Rysowanie() = 0;
	//metoda zwraca stringa z nazw¹ gatunku organizmu i jego polo¿eniem
	virtual std::string DoNapisu() = 0;
	//metoda zwraca enum jakiego gatunku jest organizm
	const Gatunek JakiGatunek() const;
	//metoda zwraca si³ê organizmu
	const int JakaSila() const;
	//metoda umo¿liwia zmianê si³y
	//si³a += param
	void ZmienSila(const int s);
	//metoda zwraca inicjatywê organizmu
	const int JakaInicjatywa() const;
	//metoda zwraca pozycjê organizmu
	const Polozenie JakaPozycja() const;
	//metoda zmienia pole zawieraj¹ce dane o po³o¿eniu organizmu
	void Przesun(const Polozenie p);
	//metoda u¿ywana do zapisu stanu organizmu
	virtual std::string DoZapisu();
	virtual ~Organizm();
};