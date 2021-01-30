#pragma once
#include <vector>
#include <iostream>

class Kolko_Krzyzyk
{
	char** tablica;
	char zwyciezca;
	int wymiar;
public:
	Kolko_Krzyzyk();
	~Kolko_Krzyzyk();
	void reset_tablica();
	void reset_zw();
	void reset();
	void drukuj_tablica();
	void drukuj_index();
	void instrukcja();
	char wstaw_znak(int);
	void ustaw_znak(char, int);
	bool mozliwe_ruchy();
	std::vector<int> wektor_ruchy();
	bool czy_wygrana(char);
	char kto_wygral();
	bool wykonal_ruch(int, char);
};