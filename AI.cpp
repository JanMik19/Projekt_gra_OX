#include "AI.h"

AI::AI() {}

AI::AI(char symbol) : Gracz(symbol) {}

int AI::get_ruch(Kolko_Krzyzyk& obj)
{
	Dane best;
	srand(time(0));
	if (obj.wektor_ruchy().size() == 9)
		best.index = rand() % 9;
	else
		best = minimax(obj, get_symbol());
	return best.index;
}

Dane AI::minimax(Kolko_Krzyzyk& obj, char gracz)
{
	char max_gracz = get_symbol();
	char inny_gracz = (gracz == 'X') ? 'O' : 'X';
	
	Dane best, current;

	if (obj.kto_wygral() == inny_gracz)
	{
		int score = obj.wektor_ruchy().size() + 1;
		if (inny_gracz != max_gracz)
			score = -score;
		best.wynik = score;
		return best;
	}
	else if (!obj.mozliwe_ruchy())
	{
		best.wynik = 0;
		return best;
	}
	if (gracz == max_gracz)
		best.wynik = -100000000;
	else
		best.wynik = 100000000;

	std::vector<int> move_set = obj.wektor_ruchy();

	for (int i = 0; i < move_set.size(); i++)
	{
		obj.wykonal_ruch(move_set[i], gracz);
		current = minimax(obj, inny_gracz);
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

void AI::zacznij_gre(Kolko_Krzyzyk& obj, Gracz* x_gracz, Gracz* o_gracz)
{
	char znak = 'X';
	int index;

	obj.reset();
	
	while (obj.mozliwe_ruchy())
	{
		if (znak == 'O')
			index = o_gracz->get_ruch(obj);
		else
			index = x_gracz->get_ruch(obj);

		obj.wykonal_ruch(index, znak);
		std::cout << "\nGracz " << znak << " wykonuje ruch na " << index + 1 << std::endl;
		obj.drukuj_tablica();
		std::cout << std::endl;

		if (obj.czy_wygrana(znak))
		{
			std::cout << "\nGracz " << znak << " wygrywa!";
			break;
		}
		else if (!obj.czy_wygrana(znak) && !obj.mozliwe_ruchy())
		{
			std::cout << "\nRemis !";
			break;
		}
		znak = (znak == 'X') ? 'O' : 'X';
	}
}