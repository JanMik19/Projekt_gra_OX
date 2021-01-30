#pragma once
#include "Kolko_Krzyzyk.h"

class Gracz
{
	char symbol;
public:
	Gracz();
	Gracz(char);
	char get_symbol();
	virtual int get_ruch(Kolko_Krzyzyk&) = 0;
};