#include "regles.h"


Regles::Regles(int largGrille, int hautGrille, int totalBateaux, int nombreJoueurs){
    this->largGrille=largGrille;
    this->hautGrille=hautGrille;
    this->nombreJoueurs=nombreJoueurs;
    this->totalBateaux=totalBateaux;
}


int Regles::get_nbr_bat_par_joueurs(){
    return (totalBateaux/2);
}


