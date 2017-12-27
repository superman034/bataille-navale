#ifndef CHARGER_NAVIRE_PERSO_H
#define CHARGER_NAVIRE_PERSO_H

#include "navire.h"
#include "string.h"
#include <iostream>

void traiterCase(char, Navire *, size_t, size_t);
void definirCouleur(std::string, Navire*);
Navire* chargerNavirePerso();

#endif
