#include "Czlowiek.h"

Czlowiek::Czlowiek() {} // kostruktor domyslny

Czlowiek::Czlowiek(char symbol) : Gracz(symbol) {} // kosntruktor parametryczny

int Czlowiek::get_ruch(Kolko_Krzyzyk& obj)
{
	int index;
	bool ruch = false;

	while (!ruch) // petla - jezeli mozna dokonac ruch to wykona sie petla
	{
		try
		{
			std::cout << std::endl << "Kolej gracza " << get_symbol() << ": ";
			std::cin >> index;
			if (obj.wstaw_znak(index - 1) != ' ')
				throw "Pozycja zajeta!"; // rzucenie wyjatkiem
			ruch = true;
		}
		catch (const char err[])
		{
			std::cout << std::endl << err; // lapanie wyjatku 
		}
	}
	return index - 1;
}
