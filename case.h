#ifndef CASE_H
#define CASE_H

#include "window.h"
#include <iostream>

class Case{

 private:
  size_t X,Y;
  bool libre;
  bool occupee;
  bool touchee;
  
 public:

  Case();     //Constructeur
  Case(size_t, size_t);
  Case(size_t, size_t, bool, bool, bool);
  bool operator==(const Case&);
  bool operator!=(const Case&);

  // Accesseurs en lecture

  size_t getX() const;
  size_t getY() const;
  bool getLibre() const;
  bool getOccupee() const;
  bool getTouchee() const;

  // Accesseurs en écriture

  void setY(size_t);
  void setX(size_t);
  void setLibre(bool B);
  void setOccupee(bool B);
  void setTouchee(bool B);
    
  void afficher_case(Window&, Color, char);
  void supprimer_case(Window& W);
};

#endif
