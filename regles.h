#ifndef REGLES_H
#define REGLES_H

class Regles{
private:
    int largGrille,
        hautGrille,
        totalBateaux,// doit etre pair, un joueur aura totalBateaux/2 bateaux
        nombreJoueurs//= à 1 ou 2
        ;
    
    
public:
    // constructeur / destructeurs
    Regles(int largGrille, int hautGrille, int totalBateaux, int nombreJoueurs);
  
    

    int get_nbr_bat_par_joueurs(); //totalBateaux/2
    
};


#endif
