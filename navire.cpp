#include "navire.h"

Navire::Navire() : nbCases(0), tabCases(NULL), couleurNavire(WBLACK) {}

// où x et y sont les pos de la première case du navire
Navire::Navire(int n, int x, int y, Color c) : nbCases(n), tabCases(new Case[n]), couleurNavire(c) {
  // Ce constructeur construit le navire de haut en bas
  // On attribue des valeurs à chaque case du navire, car il a été construit avec le constructeur par défaut de la classe Case :
  for(int i=0;i<nbCases;i++){
    tabCases[i].setLibre(false);
    tabCases[i].setOccupee(true);
    // Pas besoin de redéfinir "touchee", il est déjà à false par défaut
    tabCases[i].setX(x);
    tabCases[i].setY(y+i);
  }
}

Navire::Navire(const Navire& N) : tabCases(new Case[N.nbCases]), couleurNavire(N.couleurNavire), etat(N.etat), nbCases(N.nbCases) {
    for(int i=0;i<nbCases;i++){
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
    
    for(int i=0;i<nbCases;i++){
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
    
    for(int i=0;i<nbCases;i++){
      tabCases[i]=N->tabCases[i];
    }    
  }
  return *this;
}

bool Navire::operator==(const Navire& N) {
  if(this!=&N){
    if(couleurNavire == N.couleurNavire && etat == N.etat && nbCases == N.nbCases){
      for(int i=0;i<nbCases;i++){
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
int Navire::getNbCases() const { return nbCases; }
Color Navire::getCouleur() const { return couleurNavire; }
  
void Navire::setEtat(bool c) { etat = c; }
void Navire::setCouleur(Color col) { couleurNavire = col; }


void Navire::deplacerNavireHaut(Window& W) {
  supprimer_navire(W); // Suppresion graphique
  for(int i=0;i< this->nbCases;i++)
    tabCases[i].setY( tabCases[i].getY()-1);
  afficher_navire(W, couleurNavire, '_'); // Affichage graphique de la nouvelle position
}
void Navire::deplacerNavireBas(Window& W) {
  supprimer_navire(W);
  for(int i=0;i< this->nbCases;i++)
    tabCases[i].setY( tabCases[i].getY()+1);
  afficher_navire(W, couleurNavire, '_');
}
void Navire::deplacerNavireDroite(Window& W) {
  supprimer_navire(W);
  for(int i=0;i< this->nbCases;i++)
    tabCases[i].setX( tabCases[i].getX()+1);
  afficher_navire(W, couleurNavire, '_');
}
void Navire::deplacerNavireGauche(Window& W) {
  supprimer_navire(W); 
  for(int i=0;i< this->nbCases;i++)
    tabCases[i].setX( tabCases[i].getX()-1);
  afficher_navire(W, couleurNavire, '_');
}
void Navire::PivoterNavireGauche(Window& W){
  supprimer_navire(W);
  int sauv=0;
  for(int i=0;i< this->nbCases;i++){
    sauv=tabCases[i].getX();
    tabCases[i].setX( tabCases[i].getY());
    tabCases[i].setY( sauv);
  }
  afficher_navire(W, couleurNavire, '_');
}

void Navire::PivoterNavireDroite(Window& W){
  supprimer_navire(W);
  int sauv=0;
  for(int i=0;i< this->nbCases;i++){
    sauv=tabCases[i].getX();
    tabCases[i].setX( tabCases[i].getY());
    tabCases[i].setY( sauv);
  }
  afficher_navire(W, couleurNavire, '_');
}

int Navire::Y_min_case_navire(){
  int minY=0;
  minY= tabCases[0].getY();
  for(int i=1;i< this->nbCases;i++)
    if(tabCases[i].getY()<= minY){
      minY=tabCases[i].getY();}

  return minY;
}

int Navire::Y_max_case_navire(){
  int maxY=0;
  maxY= tabCases[0].getY();
  for(int i=1;i< this->nbCases;i++)
    if(tabCases[i].getY()>= maxY){
      maxY=tabCases[i].getY();}

  return maxY;
}


int Navire::X_min_case_navire(){
  int minX=0;
  minX= tabCases[0].getX();
  for(int i=1;i< this->nbCases;i++)
    if(tabCases[i].getX()<= minX){
      minX=tabCases[i].getX();}

  return minX;
}

int Navire::X_max_case_navire(){
  int maxX=0;
  maxX= tabCases[0].getY();
  for(int i=1;i< this->nbCases;i++)
    if(tabCases[i].getX()>= maxX){
      maxX=tabCases[i].getX();}

  return maxX;
}

// accesseur en interrogation
int Navire::nb_cases_touchees() const {int k = 0; for(int i = 0; i < nbCases; i++) { if (tabCases[i].getTouchee() == true) k ++; } return k; }

Case& Navire::at(int i)      {return tabCases[i];}
const Case& Navire::at(int i) const  {return tabCases[i];}

bool Navire::estDansNavire(int x, int y) const {
  for(int i=0;i<nbCases;i++){
    if (tabCases[i].getX() == x && tabCases[i].getY() == y)
      return true;
  }
  return false;
}

void Navire::verifCoule() { if (nb_cases_touchees() == nbCases) setEtat(true); }

// permet d'afficher toutes les cases du navire suivant leur position dans la grille.
void Navire::afficher_navire(Window& W, Color col, char p) {
  for(int i=0;i<nbCases;i++)
    tabCases[i].afficher_case(W, col, p);
}

// Méthode pour supprimer graphiquement un navire de la fenêtre
void Navire::supprimer_navire(Window& W){
for(int i=0;i<nbCases;i++)
    tabCases[i].supprimer_case(W);
}

