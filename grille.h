#ifndef GRILLE_H
#define GRILLE_H
#include "cases.h"
#include <vector>
//#include "bateau.h"
#define N 20

class Grille{


private:

 
    Cases T[N];
  
    int lig, col;


public:

    Grille();
	Grille(int lignes, int colonnes); //constructeur
	
	~Grille();  //destructeur


    // accesseur en écriture
    
	

    bool tireSurCase(int x, int y);  //tire sur la case
    
    //void Coordonnee(bateau& B); // saisie des coordonnées du bateau
    
    // accesseurs en lecture
    
	const int getNumColonnes()const;  //retourne le nombre de colonnes de la grille

	const int getNumLignes()const;  //retourne le nombre de lignes de la grille

    bool caseValide(int x, int y);


};

#endif
