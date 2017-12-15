#include "jeu.h"

// a faire
Jeu::Jeu(char* nomJoueur1, char* nomJoueur2){
    this->Reg=NULL;
    listeNaviresJ1=new Navire*[5];
    listeNaviresJ2=new Navire*[5];
    
    listejoueurs= new Joueur*[2];
    listejoueurs1[0]=Joueur(nomJoueur1, 1);
    listeJoueurs2[1]=Joueur(nomJoueur2, 2);
 
}
Jeu::Jeu(char* nomJoueur){
    char*
    this->Reg=NULL;
    listeNaviresJ1=new Navire*[5];
    listeNaviresJ2=new Navire*[5];
    
    listejoueurs= new Joueur*[2];
    listejoueurs1[0]=Joueur(nomJoueur1, 1);
    listeJoueurs2[1]=Joueur(, 2);
    
}
Jeu::~Jeu(){
    
}

bool Jeu::initialiser(Regles Reg){
    
}

void Jeu::creeRegles(){
    int largGrille=0, hautGrille=0, totalBateaux=0,  nombreJoueurs=0;
    while (!testRegles(Reg)){
        
        
        do{
        std::cout<<"entrez la largeur de la grille (minimum 5) : "<<std::endl;
        std::cin>>largGrille;
            if(LargGrille<5)
                std::cout<<"vous avez entré une valeur inférieure à 5"<<endl;}
        while(largGrille<5)
            
            
            do{
         std::cout<<"entrez la hauteur de la grille : "<<std::endl;
                std::cin>>hautGrille;
                if(hautGrille<5)
                std::cout<<"vous avez entré une valeur inférieure à 5"<<endl;
                while(hautGrille<5)
                    }
        
        do{
         std::cout<<"entrez le nombre de bateaux par joueurs(min 2) : "<<std::endl;
            std::cin>>totalBateaux;
            if(totalBateaux<2)
                std::cout<<"Vous avez mit "<<totalBateaux<<" (min 2)"<<std::endl;
        }
        while(totalBateaux<2)
            
            do{
         std::cout<<"1 ou 2 joueurs? : "<<std::endl;
          std::cin>>nombreJoueurs;
        totalBateaux*=2;
                if(nombreJoueurs!=1 && nombreJoueurs!=2)
                    std::cout<<"Vous avez entré une valeur différente de 1 ou 2"<<std::endl;
            }}
    
}

void demarrer(){
    
    
}

void arreter(){
    
    
}
