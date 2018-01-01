#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
using namespace std;

// Fonction : initialisation;
// Crée le fichier action.log s'il n'existe pas, s'il existe, il le recrée (en effacant l'ancien); On fais sa si on recommencee la partie.

void initialisation(){ 
    ofstream fichier("action.log");
    if(!fichier.is_open())
      {
	cout<<"Le fichier n'a pas pu s'ouvrir."<<endl;
	return;
      }
}

// Fonction : ajouterAction
// Ajoute une action en fin de ligne dans le fichier action.log en affichant le temps ou l'action a été ajouté.

void ajouterAction(string action, clock_t temps) {
    ofstream fichier("action.log", std::ios_base::app | std::ios_base::out);
    if(!fichier.is_open())
      {
	cout<<"Le fichier n'a pas pu s'ouvrir."<<endl;
	return;
      }
      temps=clock();
    fichier<<action<<" à "
	   <<(double)temps/CLOCKS_PER_SEC
	   <<" secondes"<< endl;
  
}

int main () {
  clock_t temps=clock(); //Temps depuis le début de la partie (à 0 secondes)
  ajouterAction("nano", temps);

  ajouterAction("tereoi", temps);

  
  return 0;
}
    
