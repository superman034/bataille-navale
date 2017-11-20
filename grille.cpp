#include "grille.h"
#include <iostream>
#include <string>
using namespace std;


Grille::Grille() {
    
    
    
    
}

Grille::Grille(int lignes, int colonnes) {
    
    
}




// accesseur en lecture

const int Grille::getNumColonnes()const{
    return col;
}

const int Grille::getNumLignes()const{
    return lig;
}
bool caseValide(int x, int y){
    if((x>0 && x<= (Grille::getNumColonnes()) && (y>0 && y<=(Grille::getNumLignes()) ))
    {return true;}
    else{return false;}
}

// accesseur en écriture
bool Grille::tireSurCase(int x, int y){
    if(caseValide(x,y)){
        Cases::setTouchee(x,y,true);
        return true;
    }
    else{return false;}
    
}
