#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include "grille.h"
#include "window.h"

class Joueur{
 private:
  std::string nom;//
  size_t score; //nbr de bateau perdus, et score = nombre de parties gagnées par le joueur
  bool ia;//pour savoir si le joueur est une IA ou pas
  Grille grille;
  Window fenetre;

 public:
  //constructeurs / destructeurs
 
  Joueur(std::string nom,bool ia);// on met batcoul et score a 0
  Joueur();
  ~Joueur();
  //accesseurs en lecture
  std::string getNom() const;
  size_t getScore () const;
  bool getIA() const;
  
  Grille& getGrille();
  Window& getFenetre();
    
  //accesseur en écriture
    
  void setNom(std::string nouvNom);
  void setScore(size_t);
  void setIA();
  
  void setGrille(Grille&);
  void setFenetre(Window&);
    
};

#endif
