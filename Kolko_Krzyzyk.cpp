#include "Kolko_Krzyzyk.h"

Kolko_Krzyzyk::Kolko_Krzyzyk() // konstruktor wywoluje dwie funkcje - inicjalizacja tablicy oraz stanu gry
{
	reset_tablica();
	reset_zw();
}

Kolko_Krzyzyk::~Kolko_Krzyzyk() // usuwanie tablicy 
{
	for (int i = 0; i < wymiar; i++)
		delete[] tablica[i];
	delete[] tablica;
}

void Kolko_Krzyzyk::reset_tablica() // alokacja pamieci do tabli 2D i inicjalizacja jako tablica pustych znakow ' '
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

void Kolko_Krzyzyk::reset_zw() { zwyciezca = '0'; } // stan poczatkowy - brak zwyciezcy

void Kolko_Krzyzyk::reset() // resetuje do stanu poczatkowego tablice oraz kasuje wynik gry (do braku zwyciezcy)
{
	reset_tablica();
	reset_zw();
}

void Kolko_Krzyzyk::drukuj_tablica() // drukuje tablice na ekran
{
	for (int i = 0; i <= 6; i += 3)
		std::cout << std::endl << " " << wstaw_znak(i) << " | " << wstaw_znak(i + 1) << " | " << wstaw_znak(i + 2);
}

void Kolko_Krzyzyk::drukuj_index() // index tablicy + 1  
{
	for (int i = 1; i <= 7; i += 3)
		std::cout << std::endl << " " << i << " | " << i + 1 << " | " << i + 2;
}

void Kolko_Krzyzyk::instrukcja() // krotki wstep, instrukcja
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

void Kolko_Krzyzyk::ustaw_znak(char symbol, int i) // wstawia symbol na odpowiednie miejsce
{
	if (symbol == 'X' || symbol == 'O' || symbol == ' ')
		tablica[i / 3][i % 3] = symbol;
}

bool Kolko_Krzyzyk::mozliwe_ruchy() // sprawdza czy mozna w dane pole wstawic symbol gracza
{ 
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (tablica[i][j] == ' ')
				return true; // true - mozna wykonac ruch
	return false; // false - nie mozna
}

std::vector<int> Kolko_Krzyzyk::wektor_ruchy() // tworzy liste mozliwych do wykonania pozycji
{
	std::vector<int> mozliwe_pozycje;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (tablica[i][j] == ' ')
				mozliwe_pozycje.push_back(3 * i + j);
	return mozliwe_pozycje;
}

bool Kolko_Krzyzyk::czy_wygrana(char symbol)
{
	// sprawdzenie wierszy tablicy
	for (int i = 0; i < 3; i++)
	{
		if (tablica[i][0] == tablica[i][1] && tablica[i][1] == tablica[i][2] && tablica[i][1] == symbol)
			return true;
	}
	
	// sprawdzenie kolumn tablicy
	for (int i = 0; i < 3; i++)
	{
		if (tablica[0][i] == tablica[1][i] && tablica[1][i] == tablica[2][i] && tablica[1][i] == symbol)
			return true;
	}
	
	// sprawdzenie obu przekatnych tablicy
	if (tablica[0][0] == tablica[1][1] && tablica[1][1] == tablica[2][2] && tablica[1][1] == symbol)
		return true;

	if (tablica[0][2] == tablica[1][1] && tablica[1][1] == tablica[2][0] && tablica[1][1] == symbol)
		return true;

	return false; // false - brak wygranej, true - jest wygrana
}

char Kolko_Krzyzyk::kto_wygral() { return zwyciezca; }

bool Kolko_Krzyzyk::wykonal_ruch(int index, char symbol)
{
	int i = index / 3, j = index % 3;

	if (tablica[i][j] == ' ') // sprawdzenie czy pozycha jest pusta, jesli jest przepisuje w pole symbol gracza
		tablica[i][j] = symbol;

	if (czy_wygrana(symbol)) // sprawdza czy gracz wygral
	{
		zwyciezca = symbol;
		return true; // true - wygral
	}
	else
		return false; // false - brak wygranej
}
