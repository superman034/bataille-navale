#ifndef NAVIRE_H
#define NAVIRE_H

#include "case.h"
#include "window.h"

class Navire{  
 private:
  Color couleurNavire;
  int nbCases;
  bool etat; // true = navire coulé, false si non
  Case *tabCases; // Un navire est un tableau de cases
  
 public:
  Navire();
  Navire(int, int, int, Color); // Par défaut, un navire est initialisé par un tableau dynamique de n cases occupées et non touchées.
  Navire(const Navire&); // Constructeur par copie
  Navire& operator=(const Navire&); // Par affectation
  Navire& operator=(const Navire*);
  bool operator==(const Navire&);
  bool operator!=(const Navire&);
  ~Navire(); // Le destructeur désalloue le tableau dynamique des cases du navire.

  bool getEtat() const; // Si toutes les cases du navire sont touchées, alors le navire coule. Renvoie true si il est coulé.
  int getNbCases() const;
  Color getCouleur() const;
  
  void setEtat(bool); // Permet d'affecter une valeur à l'attribut "estCoule". True = Coulé, False = Pas encore coulé
  void setCouleur(Color);

  // Methodes pour gérer le déplacement et la rotation des navires
  void deplacerNavireHaut(Window&);
  void deplacerNavireBas(Window&);
  void deplacerNavireDroite(Window&);
  void deplacerNavireGauche(Window&);

  void PivoterNavireGauche(Window&);
  void PivoterNavireDroite(Window&);

  int Y_min_case_navire(); // on recupére l'ordonnée de la first case
  int Y_max_case_navire();
  int X_min_case_navire();
  int X_max_case_navire();

  Case& at(int i);
  const Case& at(int i) const;
 
  int nb_cases_touchees()    const;
  bool estDansNavire(int, int) const; // Vérifie si une case donnée est dans un navire
  
  void verifCoule();

  // permet d'afficher toutes les cases du navire suivant leur position dans la grille.
  void afficher_navire(Window&, Color, char);
  void supprimer_navire(Window&);
  
};

#endif
