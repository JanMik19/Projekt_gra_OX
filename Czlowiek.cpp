#include "Czlowiek.h"

Czlowiek::Czlowiek() {} // kostruktor domyslny

Czlowiek::Czlowiek(char symbol) : Gracz(symbol) {} // kosntruktor parametryczny

int Czlowiek::get_ruch(Kolko_Krzyzyk& obj)
{
	int index;
	bool ruch = false;

	do // petla - jezeli mozna dokonac ruch to wykona sie petla
	{
		std::cout << std::endl << "Kolej gracza " << get_symbol() << ": ";
		std::cin >> index;
		
		try
		{
			if (!cin.good())
			{
				system("cls");
				std::cout << std::endl << "Zly znak wstawiono!!! Koniec programu";
				exit(1);
			}
			else if (obj.wstaw_znak(index - 1) != ' ')
				throw "Pozycja zajeta!"; // rzucenie wyjatkiem
			ruch = true;
		}
		catch (const char a[])
		{
			std::cout << std::endl << a; // lapanie wyjatku 
		}
	} while (!ruch && cin.good());
	return index - 1;
}
