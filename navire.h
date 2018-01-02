#ifndef NAVIRE_H
#define NAVIRE_H

#include "case.h"
#include "window.h"
#include <iostream>

class Navire{  
 private:
  size_t nbCases;
  Case *tabCases; // Un navire est un tableau de cases
  Color couleurNavire;
  bool etat; // true = navire coulé, false si non
  int angle; // Utile pour la rotation
  
 public:
  Navire();
  Navire(size_t);
  Navire(size_t, size_t, size_t, Color); // Par défaut, un navire est initialisé par un tableau dynamique de n cases occupées et non touchées.
  Navire(size_t x, size_t y, Color c); // Constructeur d'un navire personnalisé où l'on envoie que la première case, le reste est ajoutée avec la méthode ajouterCase.
  void ajouterCase(size_t x, size_t y);
  Navire(const Navire&); // Constructeur par copie
  Navire& operator=(const Navire&); // Par affectation
  Navire& operator=(const Navire*);
  bool operator==(const Navire&);
  // bool operator==(const Navire*);
  bool operator!=(const Navire&);
  //bool operator!=(const Navire*);
  
  ~Navire(); // Le destructeur désalloue le tableau dynamique des cases du navire.

  bool getEtat() const; // Si toutes les cases du navire sont touchées, alors le navire coule. Renvoie true si il est coulé.
  size_t getNbCases() const;
  Color getCouleur() const;
  
  void setEtat(bool); // Permet d'affecter une valeur à l'attribut "estCoule". True = Coulé, False = Pas encore coulé
  void setCouleur(Color);

  // Methodes pour gérer le déplacement et la rotation des navires
  void deplacerNavireHaut();
  void deplacerNavireBas();
  void deplacerNavireDroite();
  void deplacerNavireGauche();

  void deplacerNavire(size_t, size_t);
  
  void PivoterNavireHaut();
  void PivoterNavireBas();
  void PivoterNavireGauche();
  void PivoterNavireDroite();

  size_t Y_min_case_navire(); // on recupére l'ordonnée de la first case
  size_t Y_max_case_navire();
  size_t X_min_case_navire();
  size_t X_max_case_navire();

  Case& at(size_t i);
  const Case& at(size_t i) const;
 
  size_t nb_cases_touchees();
  bool estDansNavire(size_t, size_t) const; // Vérifie si deux coordonnées données correspondent à une case d'un navire
  
  bool verifCoule();
  Case* findCase(size_t, size_t);

  // permet d'afficher graphiquement toutes les cases du navire suivant leur position.
  void afficher_navire(Window&, Color, char);
  void supprimer_navire(Window&);
  
};

#endif
