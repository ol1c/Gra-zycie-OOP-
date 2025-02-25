#include "Organizm.h"
#include "Swiat.h" 
#include <iostream>

using namespace std;



const Gatunek Organizm::JakiGatunek() const
{
	return this->gatunek;
}

const int Organizm::JakaSila() const
{
	return this->sila;
}

void Organizm::ZmienSila(const int s)
{
	this->sila += s;
}

const int Organizm::JakaInicjatywa() const
{
	return this->inicjatywa;
}

const Polozenie Organizm::JakaPozycja() const
{
	return this->polozenie;
}

void Organizm::Przesun(const Polozenie p)
{
	this->polozenie.x = p.x;
	this->polozenie.y = p.y;
}

string Organizm::DoZapisu()
{
	return (to_string(this->gatunek) + " " + to_string(this->polozenie.x) + " " + to_string(this->polozenie.y) + " " + to_string(this->sila) + "\n");
}

Organizm::~Organizm()
{
}