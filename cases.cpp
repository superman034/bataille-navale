#include "cases.h"
#include <iostream>
#include <string>
using namespace std;



Cases::Cases () {
    this->X=0;
    this->Y=0;
    libre=true;
    occupee=false;
    touchee=false;
}

Cases::Cases (int X, int Y, bool bateau){
    if(bateau){
        this->X=X;
        this->Y=Y;
        libre=false;
        occupee=true;
        touchee=false;}
        
        
    }
    else{
    this->X=X;
    this->Y=Y;
    libre=true;
    occupee=false;
        touchee=false;}
}

void Cases::setCoordonnees(int x,int y){
    this->X=x;
    this->Y=y;
}

/*void Cases::setEtatCase(etatCase nouvelEtat){
    etatCase.libre=nouvelEtat.libre;
    etatCase.touchee=nouvelEtat.touchee;
    etatCase.occupee=nouvelEtat.occupee;
}*/

void Cases::setLibre(int x, int y, bool B){
    this->libre=B;
}

void Cases::setOccupee(int x, int y, bool B){
    this->occupee=B;
}

void Cases::setTouchee(int x, int y, bool B){
    this->touchee=B;
}


