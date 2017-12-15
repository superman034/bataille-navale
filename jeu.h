
#ifndef JEU_H
#define JEU_H
#include "regles.h"
#include "navire.h"
#include "joueur.h"
class Jeu{
    
private:
    Navire **listeNaviresJ1, **listeNaviresJ2;
    Joueur **listeJoueurs;
    
    
    
public:
    
    Jeu(Regles Reg,Navire **listeNaviresJ1,Navire **listeNaviresJ2);
    ~Jeu();
    
    
    bool testerRegles(Regles *Reg);
    Regles creerRegles();//creation de regles avec  une boucle
    void demarrer();//initialise la partie
    void arreter();//libère la mémoire
    
    
    
};


#endif
