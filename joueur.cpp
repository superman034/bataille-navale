#include "joueur.h"

Joueur::Joueur(char *nom, int identifiant){
    this->bateauxCoules=0;
    this->score=0;
    this->identifiant=identifiant;
    for (int i=0;i<32;i++){
        this->nom[i]=nom[i];
    }
}


Joueur::~Joueur(){
    for (int i=0;i<32;i++){
        delete this->nom[i];
    }
    delete[] nom;
}

char* Joueur::getNom()const{
    return this->nom;
}

int Joueur::getScore()const{
    return this->score;
}

int Joueur::getCoules()const{
    return this->bateauxCoules;
}

int Joueur::getId()const{
    return this->identifiant;
}

void Joueur::setNom(char* nouvNom){
    for (int i=0;i<32;i++){
        this->nom[i]=nouvNom[i];
    }
}

void Joueur::setCoules0(){
    this->bateauxCoules=0;
    }

void Joueur::addCoules(){
    this->bateauxCoules++;
}

void JoueursetScore(int score){
    this->score++;
}

void Joueur::setScore0(){
    this->score=0;
}




