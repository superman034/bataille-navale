#ifndef GRILLE_H
#define GRILLE_H

#include "tableau-case.h"
#include "navire.h"
#include "window.h"
#include <string.h>
#include <iostream>

class Grille{


private:

  // Une grille est constituée d'un tableau statique dynamique de navires  et d'un autre tableau dynamique de cases correspondant aux tirs qui n'ont pas attesize_t un navire
  
  Navire tabNavires[5];
  TableauCase tabCases;
  size_t nbNaviresCoules;

public:
  Grille();
  Grille(const Navire&, const Navire&, const Navire&, const Navire&, const Navire&); // constructeur

  void ajouterNavire(const Navire&, Window&);
  void enleverNavire(size_t, Window&);
  size_t findNavire(const Navire*);
  size_t findNavire(const Navire&);
  Navire& getNavire(size_t);
  void ajouterCase(const Case&);
  Navire* aQuelNavireAppartientCase(size_t, size_t);
  
  void tirCase(Window& W);
  // Permet de tirer au hasard sur une case de la grille
  
  bool appartientAUnNavire(size_t, size_t);
  bool appartientATabCases(size_t, size_t);
  bool appartientAGrille(size_t, size_t); // Permet de vérifier à partir de coordonnées x et y si la case est dans la grille ou non

  bool peutDeplacer(Navire*, std::string);
  
  void afficher_tabNavires(Window&);
  void afficher_tabCases(Window&);
  void afficher_grille(Window&);

  size_t getNbNaviresCoules();
  void calculNbNaviresCoules();
    
};

#endif
