#ifndef JEU_H
#define JEU_H
#include "regles.h"
#include "joueur.h"
class Jeu{
    
private:
	int nombreJoueurs,nombreJoueursHumains;
    Joueur *listeJoueurs;//nom,identifiant,ia,score,nombre bateaux coulés
    Regles Reg;//taille grille (on peut ajouter des trucs)
    //Grille *listeGrille;  // liste des grilles de chaque joueurs
    
    
    
    
public:
    
    Jeu(size_t nombreJoueurs,size_t nombreJoueursHumains);
    ~Jeu();
    
    
  
    void creerRegles();//creation de regles avec  une boucle
    //void demarrer();//initialise la partie
    //void arreter();//libère la mémoire
   
   Regles getRegles();
   Joueur getJoueur(int idJoueur);
   int getJoueurs();
   int getJoueursHumains();
   
   
    
    
    
};


#endif
