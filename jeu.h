#ifndef JEU_H
#define JEU_H
#include <iostream>
#include <fstream>
#include <string>
#include "joueur.h"
#include "window.h"
#include "navire.h"
#include "case.h"
#include "grille.h"

class Jeu{
    
 private:
  size_t nombreJoueurs,nombreJoueursHumains,largFenetre,hautFenetre;
  Joueur* listeJoueurs;
  clock_t temps;
              
 public:
  Jeu();
  ~Jeu();
      
  void demarrer(std::string); 
  
  Joueur& getJoueur(size_t numJoueur);
  size_t getNbJoueurs();
  size_t getNbJoueursHumains();
  
  void setNomsJoueurs();
  void setNbJoueurs();
  void setDimFenetre();
    
  void tirer(size_t);
  void lancerPartie();
  void placerNavire(Window*, Grille*, Navire*);
  void selectionnerNavire(size_t, Window&, Grille&);
  void init(std::string);
   
    
};

#endif
