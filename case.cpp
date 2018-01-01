#include "case.h"
#include <iostream>

// Constructeurs

Case::Case() :  X(0), Y(0), libre(true), occupee(false), touchee(false) {}

Case::Case(size_t x, size_t y) :  X(x), Y(y), libre(true), occupee(false), touchee(false) {}

Case::Case(size_t x, size_t y, bool l, bool o, bool t) :  X(x), Y(y), libre(l), occupee(o), touchee(t) {}
// Libre true, occupee false pour les cases en dehors des navires
// Libre false, occupee true pour les cases de navire
// On initialise toujours touchee à false

bool Case::operator==(const Case& C){
  return (X==C.X && Y==C.Y && libre==C.libre && occupee==C.occupee && touchee==C.touchee);
}

bool Case::operator!=(const Case& C) {
  return !(*this==C);
}

// Accesseurs en lecture

size_t Case::getX() const { return X; }
size_t Case::getY() const { return Y; }
bool Case::getLibre() const { return libre; }
bool Case::getOccupee() const { return occupee; }
bool Case::getTouchee() const { return touchee; }

// Acesseurs en écriture
 
void Case::setY(size_t y) { Y = y; }
void Case::setX(size_t x) { X = x; }
void Case::setLibre(bool B) { libre = B; }
void Case::setOccupee(bool B) { occupee = B; }
void Case::setTouchee(bool B) { touchee = B; }

void Case::afficher_case(Window& W, Color col, char p) {
  /*if (touchee == true)
    W.print(X, Y, "X", col);
  else if (libre == true) // Case en dehors d'un navire
    W.print(X, Y, "O", col);
    else*/
    W.print(X, Y, p, col);
}

void Case::supprimer_case(Window& W){
  W.print(X, Y, ' ');
}
