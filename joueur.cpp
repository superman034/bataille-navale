#include "joueur.h"
#include <iostream>

Joueur::Joueur(std::string nom, bool ia){
  this->score=0;
  this->nom=nom;
  this->ia=ia;
  out = false;
}

Joueur::Joueur(){

  this->score=0;
  this->nom="";
  this->ia=false;
  out = false;
}

Joueur::~Joueur(){
  
}

std::string Joueur::getNom()const{
  return nom;
}

size_t Joueur::getScore()const{
  return this->score;
}


bool Joueur::getIA()const{return this->ia;}

void Joueur::setNom(std::string nouvNom){
  this->nom=nouvNom;
}

void Joueur::incrScore(){ score+=1; }

void Joueur::setIA(){
  ia=true;}

void Joueur::setGrille(Grille& G){
  this->grille=G;
}

void Joueur::setFenetre(Window& F){
  this->fenetre=F;
}

void Joueur::setOut(bool b){ out=b; }
bool Joueur::getOut() const { return out; }

Grille& Joueur::getGrille(){
  return grille;}

Window& Joueur::getFenetre(){
  return fenetre;}

bool Joueur::verifOut(){
  if (grille.getNbNaviresCoules() == 5){
    out = true;
    return true;
  }
}
