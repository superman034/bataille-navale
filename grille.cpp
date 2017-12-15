#include "grille.h"
#include <stdlib.h> // Pour la fonction rand()
#include <iostream>

#define SN '-'

Grille::Grille() : tabCases(0), nbNaviresCoules(0) {
  for(size_t i=0; i<5; i++)
    tabNavires[i] = Navire();
}

Grille::Grille(const Navire& N1, const Navire& N2, const Navire& N3, const Navire& N4, const Navire& N5) : tabCases(0), nbNaviresCoules(0) {
  tabNavires[0] = N1;
  tabNavires[1] = N2;
  tabNavires[2] = N3;
  tabNavires[3] = N4;
  tabNavires[4] = N5;
}

void Grille::ajouterCase(const Case& c) {
  tabCases.push_back(c);
}

void Grille::ajouterNavire(const Navire& N, Window& W) {
  size_t i = 0;
  bool trouveNavireVide = false;
  while(trouveNavireVide == false && i<5){
    if (tabNavires[i].getNbCases() == 0){ // On cherche le premier navire vide dans la grille donc le premier qui a un nb de cases égal à 0
      tabNavires[i] = N;
      tabNavires[i].setCouleur(N.getCouleur());
      tabNavires[i].afficher_navire(W, tabNavires[i].getCouleur(), SN);
      trouveNavireVide = true;
    }
    i++;
  }
}

void Grille::enleverNavire(size_t i, Window& W) {
  if (i >= 0 && i < 5){
    tabNavires[i].supprimer_navire(W); // On supprime graphiquement le navire de la fenetre
    tabNavires[i] = Navire(); // On le remplace par un navire vide par défaut, avec un nombre de cases égal à 0
  }
}

Navire* Grille::aQuelNavireAppartientCase(size_t x, size_t y){
  for(size_t i=0; i<5;i++){
    if (tabNavires[i].estDansNavire(x, y) == true)
      return &tabNavires[i];
  }
  return NULL;
}

size_t Grille::findNavire(const Navire* N){
  for(size_t i=0;i<5;i++){
    if (tabNavires[i] == *N) // On utilise la surcharge d'opérateur == de la classe Navire
      return i;
  }
  return -1;
}

bool Grille::appartientAGrille(size_t x, size_t y) {
  for(size_t i=0;i<5;i++){
    if (tabNavires[i].getNbCases() > 0){
      if (tabNavires[i].estDansNavire(x, y) == true)
      return true;
    }
  }

  if (tabCases.size() > 0)
    return (tabCases.find(Case(x, y)) != -1);
  
  else // Si pas de correspondance entre les navires ni dans le tableau de cases, alors on retourne false
    return false;
  
}

bool Grille::appartientATabCases(size_t x, size_t y) {
  if (tabCases.size() > 0)
    return (tabCases.find(Case(x, y)) != -1);
}

void Grille::tirCase(Window& W){ // Algorithme de tir à améliorer
  size_t i, j;
  bool valide = false;
  
  do{
    i=rand()%W.getLargeur();
    j=rand()%W.getHauteur();
    if (appartientATabCases(i, j) == false){
      Navire* N1 = aQuelNavireAppartientCase(i,j);
      if (N1 != NULL){
	Case* C1 = N1->findCase(i,j);
	if (C1->getTouchee() == false){
	  C1->setTouchee(true);
	  valide = true;
	}
      }
      else{
	ajouterCase(Case(i,j));
	valide = true;
      }
    }
  } while(valide != true);
}

size_t Grille::getNbNaviresCoules() { calculNbNaviresCoules(); return nbNaviresCoules; }
void Grille::calculNbNaviresCoules() {
  size_t cpt = 0;
  for (int i=0; i<5; i++)
    if (tabNavires[i].verifCoule() == true)
      cpt++;
  nbNaviresCoules = cpt;
  
}

// permet d'afficher la grille complète soit : les 5 navires + le tableau de cases contenant les tirs manqués
void Grille::afficher_grille(Window& W) {
  // Affichage des 5 navires
  for(size_t i=0;i<5;i++)
    tabNavires[i].afficher_navire(W, tabNavires[i].getCouleur(), SN);

  // Affichage des cases hors navires
  if (tabCases.size() > 0)
    for(size_t i=0;i<=tabCases.size();i++)
      tabCases.at(i).afficher_case(W, WBLACK, 'O');
}
