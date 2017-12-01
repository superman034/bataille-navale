#ifndef GRILLE_H
#define GRILLE_H

#include "tableau-case.h"
#include "navire.h"
#include "window.h"

class Grille{


private:

  // Une grille est constituée d'un tableau statique de 5 navires  et d'un autre tableau dynamique de cases correspondant aux tirs qui n'ont pas atteint un navire
  
  Navire tabNavires[5];
  TableauCase tabCases;

public:

  Grille(const Navire&, const Navire&, const Navire&, const Navire&, const Navire&); // constructeur

  bool tireSurCase(int x, int y);
  bool caseValide(int x, int y);
  void ajouterCase(const Case&);
  void afficher_grille(Window&);
    
};

#endif
