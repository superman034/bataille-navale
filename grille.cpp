#include "grille.h"

Grille::Grille(const Navire& N1, const Navire& N2, const Navire& N3, const Navire& N4, const Navire& N5) {
  tabNavires[0] = N1;
  tabNavires[1] = N2;
  tabNavires[2] = N3;
  tabNavires[3] = N4;
  tabNavires[4] = N5;
}
 
									     /*bool Grille::caseValide(int x, int y){
   if((x>0 && x<= (getNbColonnes()) && (y>0 && y<=(getNbLignes()) )))
     {return true;}
     else{return false;}
     }

// accesseur en écriture
bool Grille::tireSurCase(int x, int y){
    if(caseValide(x,y)){
      Case* ptr=at(x,y);
      ptr->setTouchee(true);
        return true;
    }
    else{return false;}
    
    }*/

void Grille::ajouterCase(const Case& c) {
  tabCases.push_back(c);
}

// permet d'afficher la grille complète soit : les 5 navires + le tableau de cases contenant les tirs manqués
void Grille::afficher_grille(Window& W) {
  // Affichage des 5 navires
  for(int i=0;i<5;i++)
    tabNavires[i].afficher_navire(W, tabNavires[i].getCouleur());

  // Affichage des cases hors navires
  if (int k=tabCases.size() > 0)
    for(int i=0;i<k;i++)
      tabCases.at(i).afficher_case(W, WBLACK);
}
