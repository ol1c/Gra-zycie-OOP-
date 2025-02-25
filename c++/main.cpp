#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "Swiat.h"
#include "Organizm.h"
#include "Roslina.h"
#include "Struktury.h"
#include "Zwierze.h"
#include "Zwierzeta.h"

using namespace std;

int main()
{
	srand(time(NULL));
	SetConsoleTitle(L"Oliwier Komorowski 197808");
	SetConsoleOutputCP(CP_UTF8);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    ios::sync_with_stdio(false);

    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    int opcja;
    cout << u8"Witaj w symulacji życia";
    bool gra = true;
    while (gra)
    {
        cout << u8"\n1 - zacznij nowy świat\n2 - wczytaj stan z pliku\n";
        cin >> opcja;
        switch (opcja)
        {
        case 1:
        {
            Swiat swiat;
            swiat.Symulacja();
            gra = false;
            break;
        }
        case 2:
        {
            string nazwa;
            cout << u8"Podaj nazwę pliku do odczytu:\n";
            cin >> nazwa;
            ifstream plik(nazwa);
            while (!plik.is_open())
            {
                cout << u8"Nie można otworzyć pliku!\nPodajn nową nazwę\n0 - wróć do menu";
                cin >> nazwa;
                if (nazwa.size() == 1 && nazwa[0] == '0')
                    break;
            }
            if (nazwa.size() == 1 && nazwa[0] == '0');
            else
            {
                plik.close();
                Swiat swiat(nazwa);
                swiat.Symulacja();
                gra = false;
                break;
            }
        }
        default:
            break;
        }
    }
}