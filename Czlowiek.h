#pragma once
#include "Gracz.h"

class Czlowiek : public Gracz
{
public:
	Czlowiek();
	Czlowiek(char);
	int get_ruch(Kolko_Krzyzyk&);
};