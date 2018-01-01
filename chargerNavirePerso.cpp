#include <cstdlib>
#include <iostream>
#include <fstream>
#include <exception>
#include "string.h"
#include "navire.h"
#include "chargerNavirePerso.h"

using namespace std;

// Le code passé en commentaire a servi à effectuer des tests sur ce programme

/*void afficher_case(Case& C){
  cout << "X: " <<  C.getX() << "Y: " << C.getY() << endl;
}

void afficher_navire(Navire& N){
  cout << "Affichage d'un navire : " << endl;
  cout << "Taille du navire : " << N.getNbCases() << endl;
  for(size_t i=0;i<N.getNbCases();i++)
    afficher_case(N.at(i));
    }*/

void traiterCase(char c, Navire *N, size_t i, size_t j){
  /* if(c == 'X')
     cout << "X trouvé" << endl;*/
  if(c == 'O'){
    // cout << "O trouvé" << endl;
    // cout << " i : " << i << " j : " << j << endl;
    N->ajouterCase(i, j);
  }
}


void definirCouleur(string s, Navire* N){
  if(s == "Rouge")
    N->setCouleur(BRED);
  if(s == "Vert")
    N->setCouleur(BGREEN);
  if(s == "Jaune")
    N->setCouleur(BYELLOW);
  if(s == "Magenta")
    N->setCouleur(BMAGENTA);
  if(s == "Cyan")
    N->setCouleur(BCYAN);
  if(s == "Bleu")
    N->setCouleur(BBLUE);
}

Navire* chargerNavirePerso(){
  string file = "navire.cfg";
  ifstream input(file.c_str());

  if (!input.is_open()) {
    cerr << "Le fichier " << file << " n'a pas pu être ouvert." << endl;
    terminate();
  }

  bool fin = false;
  
  string line;
  Navire* tab= new Navire[5];
  while (!input.eof() && !fin){
    for(int numNav=0; numNav<5;numNav++){
      bool findNavire = false;
      while (!findNavire){
	getline(input,line);
	if(line.substr(0,6) == "Navire")
	  findNavire = true;
      }
      // On prend la ligne suivant la ligne "Navire", qui définit la couleur du navire
      getline(input, line);
      definirCouleur(line, &tab[numNav]);
      // cout << line << endl;
      
      size_t i, j=0;
      while(line != "Fin"){
	getline(input, line);
	if (line != "Fin"){
	  //cout << line << endl;
	  i=0;
	  while(i < line.size()){
	    //cout << line.at(i) << endl;
	    traiterCase(line.at(i), &tab[numNav], i, j);
	    i++;
	  }
	}
	j++;
      }
    }
    fin = true;
    // On finit le parcours du fichier lorsqu'on sort de la boucle for, donc : lorsqu'on a récuperé les 5 navires
  }
  
  input.close();

  /* cout << "Affichage des navires : " << endl;
  for(int i=0;i<5;i++)
  afficher_navire(tab[i]);*/

  return tab;
}
