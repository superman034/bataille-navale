#include "regles.h"
#define HAUT_LARG_GRILLE_MIN 10


Regles::Regles(int largGrille, int hautGrille,int nombreJoueurs){
    this->largGrille=largGrille;
    this->hautGrille=hautGrille;
    this->nombreJoueurs=nombreJoueurs;
    this->totalBateaux=5;
}
Regles::Regles(){
    this->largGrille=0;
    this->hautGrille=0;
    this->nombreJoueurs=0;
    this->totalBateaux=5;

}//initialise à 0



int Regles::getLarg(){ return largGrille; }
int Regles::getHaut(){return hautGrille;}
int Regles::getBat(){return totalBateaux;}
int Regles::getJoueurs(){return nombreJoueurs;}
    
void Regles::setRegles(int largGrille, int hautGrille){
    this->largGrille=largGrille;
    this->hautGrille=hautGrille;
    this->totalBateaux=5;
}

bool Regles::testerRegles(){
  if(largGrille>HAUT_LARG_GRILLE_MIN &&
     hautGrille>HAUT_LARG_GRILLE_MIN &&
     nombreJoueurs<5 &&
     nombreJoueurs>1 &&
     totalBateaux==5)
    return true;
  return false;
}


