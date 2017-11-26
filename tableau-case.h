#ifndef TABLEAU_CASE_H
#define TABLEAU_CASE_H

#include "case.h"
#include <iostream>

class TableauCase{ // Classe largement inspirée de la classe TableauInt des TD de l'UE et re-adaptée pour le projet
 private:
  Case *_data;
  size_t   _n;
  size_t   _alloc;

  void extend();
 public:

  TableauCase();
  TableauCase(size_t);
  TableauCase(const TableauCase&);
  ~TableauCase();
  
  TableauCase& operator=(const TableauCase&);
  
  Case& at(size_t);
  const Case&  at(size_t) const;

  size_t size()const;

  void push_back(const Case&); // add the cell at the end (possibly extend array)
  
  void erase(int);          // remove the element at the given position
  int  find(const Case&) const; // return the position of the cell or -1
  
};

bool identique(const Case&, const Case&);

#endif
