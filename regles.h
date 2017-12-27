#ifndef REGLES_H
#define REGLES_H

class Regles{
 private:
  int largGrille,
    hautGrille,
    totalBateaux,//(par joueurs) =5
    nombreJoueurs;//=2à4
    
    
 public:
  // constructeur / destructeurs
  Regles(int largGrille, int hautGrille, int nombreJoueurs);
  Regles();
  
    
  int getLarg();
  int getHaut();
  int getBat();
  int getJoueurs();
    
  void setRegles(int largGrille, int hautGrille);//changer les regles
    
  bool testerRegles();
    
};


#endif
