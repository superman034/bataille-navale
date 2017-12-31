#include "joueur.h"

Joueur::Joueur(std::string nom, size_t identifiant,bool ia){
    this->bateauxCoules=0;
    this->score=0;
    this->identifiant=identifiant;
    this->nom=nom;
    this->ia=ia;
}

Joueur::Joueur(){
    this->bateauxCoules=0;
    this->score=0;
    this->identifiant=-1;
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

size_t Joueur::getCoules()const{
    return this->bateauxCoules;
}

size_t Joueur::getId()const{
    return this->identifiant;
}

bool Joueur::getIA()const{return this->ia;}

void Joueur::setNom(std::string nouvNom){
   this->nom=nouvNom;
}

void Joueur::setCoules0(){
    this->bateauxCoules=0;
    }

void Joueur::addCoules(){
    this->bateauxCoules++;
}

void Joueur::addScore(){
    this->score++;
}

void Joueur::setScore0(){
    this->score=0;
}

void Joueur::setIA(){
ia=true;}

//void Joueur::setGrille(Grille grille){}

Grille Joueur::getGrille(){
return grille;}




