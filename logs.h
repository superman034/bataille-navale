#ifndef LOGS_H
#define LOGS_H

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <time.h>

// Fonction : ajouterAction
// Ajoute une action en fin de ligne dans le fichier logs.txt en ajoutant une variable de temps.

void ajouterAction(std::string action, clock_t temps);

#endif
