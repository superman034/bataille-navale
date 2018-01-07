#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include "grille.h"
#include "window.h"

class Joueur{
 private:
  std::string nom;//
  size_t score; // nb de cases que le joueur a touché
  bool ia;//pour savoir si le joueur est une IA ou pas
  bool out; // pour savoir s'il est en état de continuer la partie ou non
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

  bool getOut() const;
    
  //accesseur en écriture
    
  void setNom(std::string nouvNom);
  void incrScore();
  void setIA();
  
  void setGrille(Grille&);
  void setFenetre(Window&);

  void setOut(bool);

  bool verifOut();
    
};

#endif
