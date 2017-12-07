#ifndef GRILLE_H
#define GRILLE_H

#include "tableau-case.h"
#include "navire.h"
#include "window.h"

class Grille{


private:

  // Une grille est constituée d'un tableau statique dynamique de navires  et d'un autre tableau dynamique de cases correspondant aux tirs qui n'ont pas atteint un navire
  
  Navire tabNavires[5];
  TableauCase tabCases;

public:
  Grille();
  Grille(const Navire&, const Navire&, const Navire&, const Navire&, const Navire&); // constructeur

  void ajouterNavire(const Navire&, Color);
  void enleverNavire(int, Window&);
  int findNavire(const Navire&);
  void ajouterCase(const Case&);
  Navire& aQuelNavireAppartientCase(int, int);
  
  bool appartientAGrille(int, int); // Permet de vérifier à partir de coordonnées x et y si la case est dans la grille ou non
  void afficher_grille(Window&);
    
};

#endif
