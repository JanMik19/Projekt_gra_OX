#include "Gracz.h"

Gracz::Gracz() : symbol(' ') {}

Gracz::Gracz(char sym) : symbol(sym) {}

char Gracz::get_symbol() { return symbol; }