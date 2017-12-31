#include "jeu.h"
#define HAUT_LARG_GRILLE_MIN 10

Jeu::Jeu(size_t nombreJoueurs,size_t nombreJoueursHumains){
   
    listeJoueurs=new Joueur[nombreJoueurs]();
    
  
    if(nombreJoueurs==2){
    	if(nombreJoueursHumains==0){
    	listeJoueurs[0].setNom("IA_1");
    	listeJoueurs[0].setIA();
    	listeJoueurs[1].setNom("IA_2");
    	listeJoueurs[1].setIA();
    	}
    	
    	else if(nombreJoueursHumains==1){
    	std::cout<<"Entrez votre nom"<<std::endl;
    	std::string nomJoueur_1;
    	std::cin>>nomJoueur_1;
    	
    	listeJoueurs[0].setNom("nomJoueur");
    	listeJoueurs[1].setNom("IA_1");
    	listeJoueurs[1].setIA();
    	}
    	
    	else if(nombreJoueursHumains==2){
    	std::cout<<"Joueur 1, entrez votre nom"<<std::endl;
    	std::string nomJoueur_1;
    	std::cin>>nomJoueur_1;
    	std::cout<<"Joueur 2, entrez votre nom"<<std::endl;
    	std::string nomJoueur_2;
    	std::cin>>nomJoueur_2;
    	
 
    	
    	listeJoueurs[0].setNom(nomJoueur_1);
    	listeJoueurs[1].setNom(nomJoueur_2);
    	}
    
    }
    
    else if(nombreJoueurs==3){
    
    
    }//etape 4
    
    else if(nombreJoueurs==4){
    
    
    }//etape 4

 
}



Jeu::~Jeu(){
   delete[] listeJoueurs; 
}


void Jeu::creerRegles(){
    int largGrille=0, hautGrille=0;
   
   
        
        
    do{
        std::cout<<"entrez la largeur de la grille (minimum 5) : "<<std::endl;
        std::cin>>largGrille;
            if(largGrille<5)
                std::cout<<"vous avez entré une valeur inférieure à 5"<<std::endl;}
    while(largGrille<5);
            
            
    do{
         std::cout<<"entrez la hauteur de la grille (minimum 5) : "<<std::endl;
                std::cin>>hautGrille;
                if(hautGrille<5)
                std::cout<<"vous avez entré une valeur inférieure à 5"<<std::endl;}
    while(hautGrille<5);

    

Reg.setRegles(largGrille,hautGrille);


}

//void demarrer(){} a faire

//void arreter(){} a faire



Regles Jeu::getRegles(){
	return Reg;}

Joueur Jeu::getJoueur(int idJoueur){
return listeJoueurs[idJoueur-1];
}