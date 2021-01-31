#include "Czlowiek.h"

Czlowiek::Czlowiek() {}

Czlowiek::Czlowiek(char symbol) : Gracz(symbol) {}

int Czlowiek::get_ruch(Kolko_Krzyzyk& obj)
{
	int index;
	bool ruch = false;

	while (!ruch)
	{
		try
		{
			std::cout << std::endl << "Kolej gracza " << get_symbol() << ": ";
			std::cin >> index;
			if (obj.wstaw_znak(index - 1) != ' ')
				throw "Pozycja zajeta!";
			ruch = true;
		}
		catch (const char err[])
		{
			std::cout << std::endl << err;
		}
	}
	return index - 1;
}
