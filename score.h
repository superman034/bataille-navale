#ifndef SCORE_H
#define SCORE_H

#include "string.h"
#include <iostream>

void initialiserScore();
void recupNom(std::string *T);
void convertTabStringInt(std::string *T, int *tab);
void recupScore(std::string *T);
std::string convertirInt(int nombre);
void tabScoreIntToString(int *tInt, std::string *tString);
void tabTrie(int *T, std::string *TabNom, int nb, std::string name);
void ajouterScore(int nb, std::string name);

#endif
 

