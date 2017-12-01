#include "navire.h"

Navire::Navire() : nbCases(0), tabCases(new Case[0]) {}

// où x et y sont les pos de la première case du navire
Navire::Navire(int n, int x, int y, Color c) : nbCases(n), tabCases(new Case[n]), couleurNavire(c) {
  // On attribue des valeurs à chaque case du navire, car il a été construit avec le constructeur par défaut de la classe Case :
  for(int i=0;i<nbCases;i++){
    tabCases[i].setLibre(false);
    tabCases[i].setOccupee(true);
    // Pas besoin de redéfinir "touchee", il est déjà à false par défaut
    tabCases[i].setX(x);
    tabCases[i].setY(y+i);
  }
};

Navire::Navire(const Navire& N) {
  {
    for(int i=0;i<nbCases;i++){
      tabCases[i]=N.tabCases[i];
    }
  }
}

Navire& Navire::operator=(const Navire& N) {
  if (this!=&N){
    delete[] tabCases;
    couleurNavire=N.couleurNavire;
    etat=N.etat;
    tabCases=new Case[N.nbCases];
    nbCases=N.nbCases;
    
    for(int i=0;i<nbCases;i++){
      tabCases[i]=N.tabCases[i];
    }    
  }
  return *this;
}

Navire::~Navire() { if(tabCases != NULL) delete[] tabCases; }

bool Navire::getEtat() const { return etat; }
int Navire::getNbCases() const { return nbCases; }
Color Navire::getCouleur() const { return couleurNavire; }
  
void Navire::setEtat(bool c) { etat = c; }

void Navire::deplacerNavire(int x, int y) { }

// accesseurs en interrogation
int Navire::nb_cases_touchees() const {int k = 0; for(int i = 0; i < nbCases; i++) { if (tabCases[i].getTouchee() == true) k ++; } return k; }

void Navire::couler() { if (nb_cases_touchees() == nbCases) setEtat(true); }

// permet d'afficher toutes les cases du navire suivant leur position dans la grille.
void Navire::afficher_navire(Window& W, Color col) {
  for(int i=0;i<nbCases;i++)
    tabCases[i].afficher_case(W, col);
}
