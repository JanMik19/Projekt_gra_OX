#include "Kolko_Krzyzyk.h"

Kolko_Krzyzyk::Kolko_Krzyzyk()
{
	reset_tablica();
	reset_zw();
}

Kolko_Krzyzyk::~Kolko_Krzyzyk()
{
	for (int i = 0; i < wymiar; i++)
		delete[] tablica[i];
	delete[] tablica;
}

void Kolko_Krzyzyk::reset_tablica()
{
	wymiar = 3;
	tablica = new char* [wymiar];

	for (int i = 0; i < wymiar; ++i)
	{
		tablica[i] = new char[wymiar]; 

		for (int j = 0; j < wymiar; ++j)
			tablica[i][j] = ' ';
	}
}

void Kolko_Krzyzyk::reset_zw() { zwyciezca = '0'; } 

void Kolko_Krzyzyk::reset()
{
	reset_tablica();
	reset_zw();
}

void Kolko_Krzyzyk::drukuj_tablica()
{
	for (int i = 0; i <= 6; i += 3)
		std::cout << std::endl << " " << wstaw_znak(i) << " | " << wstaw_znak(i + 1) << " | " << wstaw_znak(i + 2);
}

void Kolko_Krzyzyk::drukuj_index()
{
	for (int i = 1; i <= 7; i += 3)
		std::cout << std::endl << " " << i << " | " << i + 1 << " | " << i + 2;
}

void Kolko_Krzyzyk::instrukcja()
{
	std::cout << "----Gra Kolko i krzyzyk----\n";
	std::cout << "---------------------------\n";
	std::cout << "wybierz odpowiednie pole...\n";
	std::cout << "\n 1 | 2 | 3 \n";
	std::cout << " 2 | 5 | 6 \n";
	std::cout << " 7 | 8 | 9 \n";
	std::cout << "\nGracz X rozpoczyna gre\n";
}

char Kolko_Krzyzyk::wstaw_znak(int i) { return tablica[i / 3][i % 3]; }

void Kolko_Krzyzyk::ustaw_znak(char symbol, int i)
{
	if (symbol == 'X' || symbol == 'O' || symbol == ' ')
		tablica[i / 3][i % 3] = symbol;
}

bool Kolko_Krzyzyk::mozliwe_ruchy()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (tablica[i][j] == ' ')
				return true;
	return false;
}

std::vector<int> Kolko_Krzyzyk::wektor_ruchy()
{
	std::vector<int> possible_moves;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (tablica[i][j] == ' ')
				possible_moves.push_back(3 * i + j);
	return possible_moves;
}

bool Kolko_Krzyzyk::czy_wygrana(char symbol)
{
	for (int i = 0; i < 3; i++)
	{
		if (tablica[i][0] == tablica[i][1] && tablica[i][1] == tablica[i][2] && tablica[i][1] == symbol)
			return true;
	}

	for (int i = 0; i < 3; i++)
	{
		if (tablica[0][i] == tablica[1][i] && tablica[1][i] == tablica[2][i] && tablica[1][i] == symbol)
			return true;
	}

	if (tablica[0][0] == tablica[1][1] && tablica[1][1] == tablica[2][2] && tablica[1][1] == symbol)
		return true;

	if (tablica[0][2] == tablica[1][1] && tablica[1][1] == tablica[2][0] && tablica[1][1] == symbol)
		return true;

	return false;
}

char Kolko_Krzyzyk::kto_wygral() { return zwyciezca; }

bool Kolko_Krzyzyk::wykonal_ruch(int index, char symbol)
{
	int i = index / 3, j = index % 3;

	if (tablica[i][j] == ' ')
		tablica[i][j] = symbol;

	if (czy_wygrana(symbol))
	{
		zwyciezca = symbol;
		return true;
	}
	else
		return false;
}