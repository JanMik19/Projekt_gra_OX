#pragma once
#include "Gracz.h"
#include "ctime"

struct Dane
{
	int index;
	long wynik;
};

class AI : public Gracz
{
public:
	AI();
	AI(char);
	int get_ruch(Kolko_Krzyzyk&);
	Dane minimax(Kolko_Krzyzyk&, char);
	void zacznij_gre(Kolko_Krzyzyk&, Gracz*, Gracz*);
};