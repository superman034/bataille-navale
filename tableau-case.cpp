#include "tableau-case.h"
#include <iostream>

TableauCase::TableauCase() : _data(NULL), _n(0), _alloc(0) {}

TableauCase::TableauCase(size_t n) : _data(new Case[n]), _n(n), _alloc(n) {}

TableauCase::TableauCase(const TableauCase& T) : _data(new Case[T._n]), _n(T._n), _alloc(_n)
{
  for(size_t i=0;i<_n;i++){
    _data[i]=T._data[i];
  }
}
TableauCase::~TableauCase(){ delete[] _data;}
  
TableauCase& TableauCase::operator=(const TableauCase& T)
{
  if (this!=&T){
    delete[] _data;
    _data=new Case[T._n];
    _n=T._n;
    _alloc=_n;
    for(size_t i=0;i<_n;i++){
      _data[i]=T._data[i];
    }    
  }
  return *this;
}


Case& TableauCase::at(size_t i)      {return _data[i];}
const Case& TableauCase::at(size_t i) const  {return _data[i];}

size_t TableauCase::size()const {return _n;}



void TableauCase::extend(){
  if (_n<_alloc) return;
  _alloc=2*_n;
  Case* tmp=new Case[_alloc];
  for(size_t i=0;i<_n;i++){tmp[i]=_data[i];}
  delete[] _data;
  _data=tmp;
}

void TableauCase::push_back(const Case& C){
  extend();
  _data[_n]=C;
  _n++;
}

void TableauCase::erase(int idx){
  if (idx>=0 && idx<(int)_n){
    for(size_t i=idx;i<_n-1;i++)
      _data[i]=_data[i+1];
    _n--;
  }  
}
  

int TableauCase::find(const Case& C) const{
  for (size_t i=0;i<_n;i++)    
    if (identique(C,_data[i])) return i;       	
  return -1;
}

class f{
  size_t _n; Case *_data;
  Case* find(const Case &C) {
    for (size_t i=0;i<_n;i++)    
      if (identique(C,_data[i])) return _data+i;		
    return NULL;
  }
};

bool identique(const Case& C1,const Case& C2){
  return (C1.getX()==C2.getX()) && (C1.getY()==C2.getY());// && (C1.getLibre()==C2.getLibre()) && (C1.getOccupee()==C2.getOccupee()) && (C1.getTouchee()==C2.getTouchee()); 
}
