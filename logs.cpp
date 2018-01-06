#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include "logs.h"

// Fonction : ajouterAction
// Ajoute une action en fin de ligne dans le fichier action.log en affichant le temps ou l'action a été ajouté.

void ajouterAction(std::string action, clock_t temps) {
  std::ofstream fichier("logs.txt", std::ios_base::app | std::ios_base::out);
    if(!fichier.is_open())
      {
	std::cerr<<"Le fichier n'a pas pu s'ouvrir."<<std::endl;
	return;
      }
      temps=clock();
    fichier<<action<<" à "
	   <<(double)temps/CLOCKS_PER_SEC
	   <<" secondes"<< std::endl;
  
}

/*
int main () {
  clock_t temps=clock(); //Temps depuis le début de la partie (à 0 secondes)
  ajouterAction("test", temps);
  return 0;
}
*/
