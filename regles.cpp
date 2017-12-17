#include "regles.h"
#define HAUT_LARG_GRILLE_MIN 10


Regles::Regles(int largGrille, int hautGrille){
    this->largGrille=largGrille;
    this->hautGrille=hautGrille;
    
}
Regles::Regles(){
    this->largGrille=0;
    this->hautGrille=0;

}//initialise à 0



int Regles::getLarg(){return largGrille;}
int Regles::getHaut(){return hautGrille;}

    
void Regles::setRegles(int largGrille, int hautGrille){
    this->largGrille=largGrille;
    this->hautGrille=hautGrille;
}

bool Regles::testerRegles(){
    if(largGrille>HAUT_LARG_GRILLE_MIN &&
    hautGrille>HAUT_LARG_GRILLE_MIN)
    return true;
    return false;
}