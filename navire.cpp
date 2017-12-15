#include "navire.h"
#include <iostream>

Navire::Navire() : nbCases(0), tabCases(NULL), couleurNavire(WBLACK), etat(false) {}

// où x et y sont les pos de la première case du navire
Navire::Navire(size_t n, size_t x, size_t y, Color c) : nbCases(n), tabCases(new Case[n]), couleurNavire(c), etat(false) {
  // Ce constructeur construit le navire de haut en bas
  // On attribue des valeurs à chaque case du navire, car il a été construit avec le constructeur par défaut de la classe Case :
  for(size_t i=0;i<nbCases;i++){
    tabCases[i].setLibre(false);
    tabCases[i].setOccupee(true);
    // Pas besoin de redéfinir "touchee", il est déjà à false par défaut
    tabCases[i].setX(x);
    tabCases[i].setY(y+i);
  }
}

Navire::Navire(const Navire& N) : nbCases(N.nbCases), tabCases(new Case[N.nbCases]), couleurNavire(N.couleurNavire), etat(N.etat){
    for(size_t i=0;i<nbCases;i++){
      tabCases[i]=N.tabCases[i];
    }
}

Navire& Navire::operator=(const Navire& N) {
  if (this!=&N){
    delete[] tabCases;
    tabCases=new Case[N.nbCases];
    couleurNavire=N.couleurNavire;
    etat=N.etat;
    nbCases=N.nbCases;
    
    for(size_t i=0;i<nbCases;i++){
      tabCases[i]=N.tabCases[i];
    }    
  }
  return *this;
}

Navire& Navire::operator=(const Navire* N) {
  if (this!=N){
    delete[] tabCases;
    tabCases=new Case[N->nbCases];
    couleurNavire=N->couleurNavire;
    etat=N->etat;
    nbCases=N->nbCases;
    
    for(size_t i=0;i<nbCases;i++){
      tabCases[i]=N->tabCases[i];
    }    
  }
  return *this;
}

bool Navire::operator==(const Navire& N) {
  if(this!=&N){
    if(couleurNavire == N.couleurNavire && etat == N.etat && nbCases == N.nbCases){
      for(size_t i=0;i<nbCases;i++){
	if(tabCases[i] != N.tabCases[i]) // On utilise la surcharge d'opérateur != de la classe Case
	  return false;
      }
      return true;
    }
    
    else
      return false;
	
  }
  else
    return true;
}

bool Navire::operator!=(const Navire& N1){
  return !(*this == N1);
}


Navire::~Navire() { if(tabCases != NULL) delete[] tabCases; }

bool Navire::getEtat() const { return etat; }
size_t Navire::getNbCases() const { return nbCases; }
Color Navire::getCouleur() const { return couleurNavire; }
  
void Navire::setEtat(bool c) { etat = c; }
void Navire::setCouleur(Color col) { couleurNavire = col; }


void Navire::deplacerNavireHaut() {
  for(size_t i=0;i< this->nbCases;i++)
    tabCases[i].setY( tabCases[i].getY()-1);
}
void Navire::deplacerNavireBas() {
  for(size_t i=0;i< this->nbCases;i++)
    tabCases[i].setY( tabCases[i].getY()+1);
}
void Navire::deplacerNavireDroite() {
  for(size_t i=0;i< this->nbCases;i++)
    tabCases[i].setX( tabCases[i].getX()+1);
}
void Navire::deplacerNavireGauche() {
  for(size_t i=0;i< this->nbCases;i++)
    tabCases[i].setX( tabCases[i].getX()-1);
}
void Navire::PivoterNavireGauche(){
  size_t sauv=0;
  for(size_t i=0;i< this->nbCases;i++){
    sauv=tabCases[i].getX();
    tabCases[i].setX( tabCases[i].getY());
    tabCases[i].setY( sauv);
  }
}

void Navire::PivoterNavireDroite(){
  size_t sauv=0;
  for(size_t i=0;i< this->nbCases;i++){
    sauv=tabCases[i].getX();
    tabCases[i].setX( tabCases[i].getY());
    tabCases[i].setY( sauv);
  }
}

size_t Navire::Y_min_case_navire(){
  size_t minY=0;
  minY= tabCases[0].getY();
  for(size_t i=1;i< this->nbCases;i++)
    if(tabCases[i].getY()<= minY){
      minY=tabCases[i].getY();}

  return minY;
}

size_t Navire::Y_max_case_navire(){
  size_t maxY=0;
  maxY= tabCases[0].getY();
  for(size_t i=1;i< this->nbCases;i++)
    if(tabCases[i].getY()>= maxY){
      maxY=tabCases[i].getY();}

  return maxY;
}


size_t Navire::X_min_case_navire(){
  size_t minX=0;
  minX= tabCases[0].getX();
  for(size_t i=1;i< this->nbCases;i++)
    if(tabCases[i].getX()<= minX){
      minX=tabCases[i].getX();}

  return minX;
}

size_t Navire::X_max_case_navire(){
  size_t maxX=0;
  maxX= tabCases[0].getY();
  for(size_t i=1;i< this->nbCases;i++)
    if(tabCases[i].getX()>= maxX){
      maxX=tabCases[i].getX();}

  return maxX;
}

// accesseur en size_terrogation
size_t Navire::nb_cases_touchees() const {size_t k = 0; for(size_t i = 0; i < nbCases; i++) { if (tabCases[i].getTouchee() == true) k ++; } return k; }

Case& Navire::at(size_t i)      {return tabCases[i];}
const Case& Navire::at(size_t i) const  {return tabCases[i];}

Case* Navire::findCase(size_t X, size_t Y) {
  for(int i=0; i<nbCases;i++){
    if (tabCases[i].getX() == X && tabCases[i].getY() == Y)
      return &tabCases[i];
  }
  return NULL;
}

bool Navire::estDansNavire(size_t x, size_t y) const {
  for(size_t i=0;i<nbCases;i++){
    if (tabCases[i].getX() == x && tabCases[i].getY() == y)
      return true;
  }
  return false;
}

bool Navire::verifCoule() { if (nb_cases_touchees() == nbCases) {setEtat(true); return true; } else return false; }

// permet d'afficher toutes les cases du navire suivant leur position dans la grille.
void Navire::afficher_navire(Window& W, Color col, char p) {
  for(size_t i=0;i<nbCases;i++){
    if (tabCases[i].getTouchee() == true)
      tabCases[i].afficher_case(W, col, 'X');
    else
      tabCases[i].afficher_case(W, col, p);
  }
}

// Méthode pour supprimer graphiquement un navire de la fenêtre
void Navire::supprimer_navire(Window& W){
for(size_t i=0;i<nbCases;i++)
    tabCases[i].supprimer_case(W);
}

