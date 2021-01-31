#include "Czlowiek.h"
#include "AI.h"

int main()
{
	Kolko_Krzyzyk gra; // tworzyny objekt na klase Kolko_Krzyzyk, czyli inicjalizujemy to, co sie tam znajduje (tablice itd...)
	AI wsk; // wczesniej byl wskaznik stad ta nazwa "wsk", ale jest teraz objekt, mozna zamienic na wspaznik i wtedy funkcje "zacznij_gre()" wywolac operatorem "->"
	char kolejnosc, decyzja;

	gra.instrukcja(); // wyswietlenie wstepu i instrukcji
	
	do
	{
		std::cout << "Czy chcesz zaczac jako pierwszy ? (t/n) :";
		std::cin >> kolejnosc;

		if (kolejnosc == 't' || kolejnosc == 'T') // jezeli zaczynamy pierwsi, to czlowiek ma 'X', komputer 'O'
			wsk.zacznij_gre(gra, new Czlowiek('X'), new AI('O')); // zawolanie poprzez objekt klasy "AI"
		else // inaczej to komputer zaczyna jako 'X'
			wsk.zacznij_gre(gra, new AI('X'), new Czlowiek('O')); // zawolanie poprzez objekt klasy "AI", jak wyzej napisano, moze byc tez zawolane popzez wskaznik

		std::cout << "\nChcesz zagracz ponownie? (t/n) : ";
		std::cin >> decyzja;

	} while (decyzja == 't' || decyzja == 'T');

	return 0;
}
