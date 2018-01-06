#ifndef JEU_H
#define JEU_H
#include <iostream>
#include <fstream>
#include "joueur.h"
#include "window.h"
#include "navire.h"
#include "case.h"
#include "grille.h"

class Jeu{
    
 private:
  size_t nombreJoueurs,nombreJoueursHumains,largFenetre,hautFenetre;
  Joueur* listeJoueurs;//nom,identifiant,ia,score,nombre bateaux coulés
              
 public:
  Jeu();
  ~Jeu();
      
  void demarrer(); 
  
  Joueur& getJoueur(size_t numJoueur);
  size_t getNbJoueurs();
  size_t getNbJoueursHumains();
  
  void setNomsJoueurs();
  void setNbJoueurs();
  void setDimFenetre();
    
  void tirer(Window& fenetreDeTir, Grille grilleDeTir);
  void lancerPartie(Window& joueur, Grille& Joueur, Window& ia, Grille& IA);
  void placerNavire(Window* joueur, Grille* Joueur, Navire* aDeplacer);
  //void selectionnerNavire(Window& flotte, Window* joueur, Grille& Flotte, Grille* Joueur);
  void selectionnerNavire(size_t, Window&, Grille&);
  void init();
   
    
};

#endif
