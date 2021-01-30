#include "Czlowiek.h"
#include "AI.h"

int main()
{
	Kolko_Krzyzyk gra;
	AI wsk;
	char kolejnosc, decyzja;

	gra.instrukcja();
	
	do
	{
		std::cout << "Czy chcesz zaczac jako pierwszy ? (t/n) :";
		std::cin >> kolejnosc;

		if (kolejnosc == 't' || kolejnosc == 'T')
			wsk.zacznij_gre(gra, new Czlowiek('X'), new AI('O'));
		else
			wsk.zacznij_gre(gra, new AI('X'), new Czlowiek('O'));

		std::cout << "\nChcesz zagracz ponownie? (t/n) : ";
		std::cin >> decyzja;

	} while (decyzja == 't' || decyzja == 'T');

	return 0;
}