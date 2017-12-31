#ifndef JEU_H
#define JEU_H
#include "regles.h"
#include "joueur.h"
#include "grille.h"

class Jeu{
    
 private:

  Joueur *listeJoueurs;
  Regles Reg;
    
 public:
    
  Jeu(size_t nombreJoueurs, size_t nombreJoueursHumains);
  ~Jeu();
  
  void creerRegles();//creation de regles avec  une boucle
  //void demarrer();//initialise la partie
  //void arreter();//libère la mémoire
   
  Regles getRegles();
  Joueur getJoueur(int idJoueur);

    
};


#endif
