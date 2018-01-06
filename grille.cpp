#include "grille.h"
#include <stdlib.h> // Pour la fonction rand()
#include <iostream>

using namespace std;

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

Grille& Grille::operator=(const Grille& nouv){
  if (this!=&nouv){
    nbNaviresCoules=nouv.nbNaviresCoules;
    tabCases=nouv.tabCases;
    for (int i=0;i<5;i++){
      tabNavires[i]=nouv.tabNavires[i];
    }
  }
  return *this;
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
  if (i < 5){
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

size_t Grille::findNavire(const Navire& N){
  for(size_t i=0;i<5;i++){
    if (tabNavires[i] == N) // On utilise la surcharge d'opérateur == de la classe Navire
      return i;
  }
  return -1;
}

Navire& Grille::getNavire(size_t i){
  return tabNavires[i];
}

/*bool Grille::appartientAGrille(size_t x, size_t y) {
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
  
    }*/

bool Grille::appartientATabCases(size_t x, size_t y) {
  if (tabCases.size() > 0)
    return (tabCases.find(Case(x, y)) != -1);
  return false;
}

bool Grille::appartientAUnNavire(size_t x, size_t y){
  for(size_t i=0;i<5;i++){
    if (tabNavires[i].getNbCases() > 0){
      if (tabNavires[i].estDansNavire(x, y) == true)
	return true;
    }
  }
  return false;
}

bool Grille::appartientAGrille(size_t x, size_t y){
  return (appartientATabCases(x, y) || appartientAUnNavire(x, y));
}

bool Grille::peutDeplacer(Navire* N, string sens){
  size_t x, y;
  
  if(sens == "droite"){
    for(size_t i=0; i<N->getNbCases(); i++){
      x = N->at(i).getX()+1;
      y = N->at(i).getY();
      if (appartientAUnNavire(x, y) == true && (aQuelNavireAppartientCase(x,y) != N))
	return false;
    }
    return true;
  }

  if(sens == "gauche"){
    for(size_t i=0; i< N->getNbCases(); i++){
      x = N->at(i).getX()-1;
      y = N->at(i).getY();
      if (appartientAUnNavire(x, y) == true && (aQuelNavireAppartientCase(x,y) != N))
	return false;
    }
    return true;
  }

  if(sens == "haut"){
    for(size_t i=0; i<N->getNbCases(); i++){

      x = N->at(i).getX();
      y = N->at(i).getY()-1;
      if (appartientAUnNavire(x, y) == true && (aQuelNavireAppartientCase(x,y) != N))
	return false;
    }
    return true;
  }

  if(sens == "bas"){
    for(size_t i=0; i<N->getNbCases(); i++){
      x = N->at(i).getX();
      y = N->at(i).getY()+1;
      if (appartientAUnNavire(x, y) == true && (aQuelNavireAppartientCase(x,y) != N))
	return false;
    }
    return true;
  }
  
  return false; // Sens non reconnu
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

size_t Grille::getNbNaviresCoules() {
  calculNbNaviresCoules();
  return nbNaviresCoules;
}

void Grille::calculNbNaviresCoules() {
  size_t cpt = 0;
  for (size_t i=0; i<5; i++)
    if (tabNavires[i].verifCoule() == true)
      cpt++;
  nbNaviresCoules = cpt;
  
}

void Grille::afficher_tabNavires(Window& W){
  // Affichage des 5 navires
  for(size_t i=0;i<5;i++)
    tabNavires[i].afficher_navire(W, tabNavires[i].getCouleur(), SN);
}

void Grille::afficher_tabCases(Window& W) {
  // Affichage des cases hors navires
  if (tabCases.size() > 0)
    for(size_t i=0;i<=tabCases.size();i++){
      if (tabCases.at(i).getLibre() == false && tabCases.at(i).getOccupee() == true)
	tabCases.at(i).afficher_case(W, WBLACK, 'X');
      else
	tabCases.at(i).afficher_case(W, WBLACK, 'O');
    }
}

// permet d'afficher la grille complète soit : les 5 navires + le tableau de cases contenant les tirs manqués
void Grille::afficher_grille(Window& W) {
  afficher_tabNavires(W);
  afficher_tabCases(W);
}


