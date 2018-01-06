#include "joueur.h"
#include <iostream>

Joueur::Joueur(std::string nom, bool ia){
  this->score=0;
  this->nom=nom;
  this->ia=ia;
}

Joueur::Joueur(){

  this->score=0;
  this->nom="";
  this->ia=false;
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

void Joueur::setScore(size_t score){
  this->score=score;
}

void Joueur::setIA(){
  ia=true;}

void Joueur::setGrille(Grille& G){
  this->grille=G;
}

void Joueur::setFenetre(Window& F){
  this->fenetre=F;
}

Grille& Joueur::getGrille(){
  return grille;
}

Window& Joueur::getFenetre(){
  return fenetre;
}
