#ifndef CASE_H
#define CASE_H

#include "window.h"

class Case{

 private:
  bool libre;
  bool touchee;
  bool occupee;

  int X,Y;

 public:

  Case();     //Constructeur
  Case(int, int);
  bool operator==(const Case&);
  bool operator!=(const Case&);

  // Accesseurs en lecture

  int getX() const;
  int getY() const;
  bool getLibre() const;
  bool getOccupee() const;
  bool getTouchee() const;

  // Accesseurs en écriture

  void setY(int);
  void setX(int);
  void setLibre(bool B);
  void setOccupee(bool B);
  void setTouchee(bool B);
    
  void afficher_case(Window&, Color, char);
  void supprimer_case(Window& W);
};

#endif
