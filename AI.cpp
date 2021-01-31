#include "AI.h"

AI::AI() {} // konstruktor domyslny

AI::AI(char symbol) : Gracz(symbol) {} // konstruktor parametryczny

int AI::get_ruch(Kolko_Krzyzyk& obj) // przymuje referencje na objekt blazy Kolko_Krzyzyk i wykomuje odpowiednie metody
{
	Dane best; // objekt na strukture "Dane", ktora przechowyje indeks by wrzucac gracza do tablicy, oraz wynik 
	srand(time(0)); 
	if (obj.wektor_ruchy().size() == 9) // jesli jest 9 wolnych miejsc, i jezeli komputer rozpoczyna gre, to pierwszy ruch jest randomowy 
		best.index = rand() % 9;
	else
		best = minimax(obj, get_symbol()); // nastepnie jest wykonywany algorytm funkcji minimax()
	return best.index;
}

Dane AI::minimax(Kolko_Krzyzyk& obj, char gracz) // aglorytm dzialania graczy i ich poruszania sie 
{
	char max_gracz = get_symbol(); // max_gracz - bedzie graczem maksymalizujacym wynik gry (zaczyna od najmniejszego wyniku i bedzie go zwiekszal)
	char inny_gracz = (gracz == 'X') ? 'O' : 'X'; // jezeli jest przepisany konkretny symbol do max_gracz, to kolejny gracz na inny symbol
	
	Dane best, current; // dwa objekty na strukture "Dane" do przypisywania wyniku gry

	if (obj.kto_wygral() == inny_gracz) // inny gracz jest w tym przypadku czlowiek, jesli wygral to zwraca sie minimalny wynik (-score)
	{
		int score = obj.wektor_ruchy().size() + 1;
		if (inny_gracz != max_gracz)
			score = -score;
		best.wynik = score;
		return best;
	}
	else if (!obj.mozliwe_ruchy()) // sprawdzenie czy mozna zrobic ruch, jesli brak miejsca, i gracz (inny_gracz) nie wygral -> czyli remis 
	{
		best.wynik = 0; // 0 - remis
		return best;
	}
	if (gracz == max_gracz) // jezeli max_gracz zaczyna, to zaczyna od ujemnego wyniku i stara sie go zwiekszyc
		best.wynik = -100000000;
	else
		best.wynik = 100000000; // jezeli inny gracz zaczyna, to zaczyna gre od dodatniego wyniku i stara sie go zmniejszyc

	std::vector<int> move_set = obj.wektor_ruchy(); 

	for (int i = 0; i < move_set.size(); i++) // petla w celu "wpychania" graczy na plansze i zwracania wyniku
	{
		obj.wykonal_ruch(move_set[i], gracz);
		current = minimax(obj, inny_gracz); // rekurencja (minimax() wywoluje minimax())
		obj.ustaw_znak(' ', move_set[i]);
		obj.reset_zw();
		current.index = move_set[i];

		if (gracz == max_gracz)
		{
			if (current.wynik > best.wynik)
				best = current;
		}
		else
		{
			if (current.wynik < best.wynik)
				best = current;
		}
	}
	return best;
}

void AI::zacznij_gre(Kolko_Krzyzyk& obj, Gracz* x_gracz, Gracz* o_gracz) // funkcja petli gry
{
	char znak = 'X'; // wstepnie przypisanie wartosci znaku
	int index;

	obj.reset(); // resetowanie tablicy i wyniku gry
	
	while (obj.mozliwe_ruchy()) // dopuki mozna wykonac ruchy -> wykonuje sie petla
	{
		if (znak == 'O') // jesli gracz 'O'
			index = o_gracz->get_ruch(obj); // ruch wykona gracz 'O'
		else
			index = x_gracz->get_ruch(obj); // inaczej -> ruch gracza 'X'

		obj.wykonal_ruch(index, znak); // wstawia gracza ktory spelnik instrukcje if...else
		std::cout << "\nGracz " << znak << " wykonuje ruch na " << index + 1 << std::endl;
		obj.drukuj_tablica(); // drukowanie "odswierzonej" tablicy, wraz z umieszczonym graczem
		std::cout << std::endl;

		if (obj.czy_wygrana(znak)) // jesli wygrana...
		{
			std::cout << "\nGracz " << znak << " wygrywa!"; // ...to wyswietli sie taki komunikat
			break;
		}
		else if (!obj.czy_wygrana(znak) && !obj.mozliwe_ruchy()) // jesli nie ma wygranej i brakuje miejsca do wstawienia gracza...
		{
			std::cout << "\nRemis !"; // ...to wtedy jest remis
			break;
		}
		znak = (znak == 'X') ? 'O' : 'X'; // przelaczanie kolejnosci znakow reprezentowanych graczy - jesli zaczynal 'X' to kolejny bedzie 'O'
	}
}
