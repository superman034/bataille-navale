#include <iostream>
#include <stdlib.h> // Pour la fonction rand()
#include "jeu.h"
#include "window.h"
#include "navire.h"
#include "case.h"
#include "grille.h"
#include "chargerNavirePerso.h"


#define SN '-'// SN = Le symbole affiché à chaque case d'un navire
#define HAUT_LARG_GRILLE_MIN 10

Jeu::Jeu(){
	this->nombreJoueurs=0;
	this->nombreJoueursHumains=0;
}

Jeu::~Jeu(){
   delete[] listeJoueurs; 
}

void Jeu::setNomsJoueurs(){
  setNbJoueurs();
  setDimFenetre();
  
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
    	
      listeJoueurs[0].setNom(nomJoueur_1);
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
    if(nombreJoueursHumains==0){
      listeJoueurs[0].setNom("IA_1");
      listeJoueurs[0].setIA();
      listeJoueurs[1].setNom("IA_2");
      listeJoueurs[1].setIA();
      listeJoueurs[2].setNom("IA_3");
      listeJoueurs[2].setIA();
    }
    else if(nombreJoueursHumains==1){
      std::cout<<"Entrez votre nom"<<std::endl;
      std::string nomJoueur_1;
      std::cin>>nomJoueur_1;
    	
      listeJoueurs[0].setNom(nomJoueur_1);
      listeJoueurs[1].setNom("IA_1");
      listeJoueurs[1].setIA();
      listeJoueurs[2].setNom("IA_2");
      listeJoueurs[2].setIA();
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
      listeJoueurs[2].setNom("IA_1");
      listeJoueurs[2].setIA();
    }
    else if(nombreJoueursHumains==3){
      std::cout<<"Joueur 1, entrez votre nom"<<std::endl;
      std::string nomJoueur_1;
      std::cin>>nomJoueur_1;
      std::cout<<"Joueur 2, entrez votre nom"<<std::endl;
      std::string nomJoueur_2;
      std::cin>>nomJoueur_2;
      std::cout<<"Joueur 3, entrez votre nom"<<std::endl;
      std::string nomJoueur_3;
      std::cin>>nomJoueur_3;
    	   	
      listeJoueurs[0].setNom(nomJoueur_1);
      listeJoueurs[1].setNom(nomJoueur_2);
      listeJoueurs[2].setNom(nomJoueur_3);
    }    	
    
  }
    
  else if(nombreJoueurs==4){
    if(nombreJoueursHumains==0){
      listeJoueurs[0].setNom("IA_1");
      listeJoueurs[0].setIA();
      listeJoueurs[1].setNom("IA_2");
      listeJoueurs[1].setIA();
      listeJoueurs[2].setNom("IA_3");
      listeJoueurs[2].setIA();
      listeJoueurs[3].setNom("IA_4");
      listeJoueurs[3].setIA();
    }
    else if(nombreJoueursHumains==1){
      std::cout<<"Entrez votre nom"<<std::endl;
      std::string nomJoueur_1;
      std::cin>>nomJoueur_1;
    	
      listeJoueurs[0].setNom(nomJoueur_1);
      listeJoueurs[1].setNom("IA_1");
      listeJoueurs[1].setIA();
      listeJoueurs[2].setNom("IA_2");
      listeJoueurs[2].setIA();
      listeJoueurs[3].setNom("IA_4");
      listeJoueurs[3].setIA();
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
      listeJoueurs[2].setNom("IA_1");
      listeJoueurs[2].setIA();
      listeJoueurs[3].setNom("IA_2");
      listeJoueurs[3].setIA();
    }
    else if(nombreJoueursHumains==3){
      std::cout<<"Joueur 1, entrez votre nom"<<std::endl;
      std::string nomJoueur_1;
      std::cin>>nomJoueur_1;
      std::cout<<"Joueur 2, entrez votre nom"<<std::endl;
      std::string nomJoueur_2;
      std::cin>>nomJoueur_2;
      std::cout<<"Joueur 3, entrez votre nom"<<std::endl;
      std::string nomJoueur_3;
      std::cin>>nomJoueur_3;
    	    	
      listeJoueurs[0].setNom(nomJoueur_1);
      listeJoueurs[1].setNom(nomJoueur_2);
      listeJoueurs[2].setNom(nomJoueur_3);
      listeJoueurs[3].setNom("IA_1");
      listeJoueurs[3].setIA();
    }
    else if(nombreJoueursHumains==4){
      std::cout<<"Joueur 1, entrez votre nom"<<std::endl;
      std::string nomJoueur_1;
      std::cin>>nomJoueur_1;
      std::cout<<"Joueur 2, entrez votre nom"<<std::endl;
      std::string nomJoueur_2;
      std::cin>>nomJoueur_2;
      std::cout<<"Joueur 3, entrez votre nom"<<std::endl;
      std::string nomJoueur_3;
      std::cin>>nomJoueur_3;
      std::cout<<"Joueur 4, entrez votre nom"<<std::endl;
      std::string nomJoueur_4;
      std::cin>>nomJoueur_4;
    	   	
      listeJoueurs[0].setNom(nomJoueur_1);
      listeJoueurs[1].setNom(nomJoueur_2);
      listeJoueurs[2].setNom(nomJoueur_3);
      listeJoueurs[3].setNom(nomJoueur_4);   
    }
  }
}

void Jeu::setNbJoueurs(){
  size_t t=0, h=0;
  do{std::cout<<"entrez le nombre de joueurs (entre 2 et 4)"<<std::endl;
    std::cin>>t;
    std::cout<<"entrez le nombre d'humain (entre 1 et "<<t<<")"<<std::endl;
    std::cin>>h;

    if(t<2 || t>4 || h>t){
      std::cout<<"vous avez entré des valeurs incorrectes"<<std::endl;
    }
  }
  while(t<2 || t>4 || h>t);
  nombreJoueurs = t;
  nombreJoueursHumains = h;
  listeJoueurs = new Joueur[t];
}

void Jeu::setDimFenetre(){
  size_t l=0, h=0;                   
  do{
    std::cout<<"entrez la largeur de la grille (minimum " << HAUT_LARG_GRILLE_MIN << ") : " <<std::endl;
    std::cin>>l;
    if(l<HAUT_LARG_GRILLE_MIN)
      std::cout<<"vous avez entré une valeur inférieure à " << HAUT_LARG_GRILLE_MIN <<std::endl;}
  while(l<HAUT_LARG_GRILLE_MIN);
                      
  do{
    std::cout<<"entrez la hauteur de la grille (minimum "<< HAUT_LARG_GRILLE_MIN << ") : "<<std::endl;
    std::cin>>h;
    if(h<HAUT_LARG_GRILLE_MIN)
      std::cout<<"vous avez entré une valeur inférieure à "<< HAUT_LARG_GRILLE_MIN <<std::endl;}
  while(h<HAUT_LARG_GRILLE_MIN);
  largFenetre = l;
  hautFenetre = h;
}

void Jeu::demarrer(){
  setNomsJoueurs();
  startProgramX();
  init();
  stopProgramX();
}

Joueur& Jeu::getJoueur(size_t numJoueur){
return listeJoueurs[numJoueur-1];
}

size_t Jeu::getNbJoueurs(){
return nombreJoueurs;}

size_t Jeu::getNbJoueursHumains(){
return nombreJoueursHumains;}

//bn-main


void Jeu::tirer(Window& fenetreDeTir, Grille grilleDeTir){ // Pas fini
  size_t ch;
  size_t x=0, y=0;
  bool tir = false;
  char p='X';
  Color col=WBLACK;
  
  if (grilleDeTir.appartientATabCases(x, y) == true){ // Code pour afficher le viseur pour tirer à la prochaine case vide
    while (grilleDeTir.appartientATabCases(x, y) != false){
      if (x+1 >= fenetreDeTir.getLargeur()){
	y++;
	x=0;
      }
      else
	x++;
    }
  }
  
  fenetreDeTir.print(x,y,p,col);
  grilleDeTir.afficher_grille(fenetreDeTir);
  
  while(!tir)
    {     
      switch (ch = getch()) {
      case KEY_UP:
	if (y != 0 && grilleDeTir.appartientATabCases(x, y-1) == false){
	  fenetreDeTir.print(x,y,' ', col);
	  y--;
	  fenetreDeTir.print(x,y,p, col);
	}

	else{
	  int i = 2;
	  bool exit = false;
	  while(!exit){ // On fait une boucle pour trouver la prochaine case que l'on peut atteindre
	    if(grilleDeTir.appartientATabCases(x, y-i) == false){
	      exit = true; // On a trouvé la prochaine case
	    }
	    else
	      i++;
	  }
	  int aux = y-i; // On passe par une valeur auxiliaire int car y est un size_t, donc un entier positif
	  if(aux < 0){ // Si la case qu'on a trouvée sort de la fenêtre, on ne fait rien et on reste à la même coordonnée, donc i = 0
	    i = 0;
	  }
	  fenetreDeTir.print(x,y,' ', col);
	  y-=i;
	  fenetreDeTir.print(x,y,p, col);
	}
	break;
	
      case KEY_DOWN:
	if (y+1 != fenetreDeTir.getHauteur() && grilleDeTir.appartientATabCases(x, y+1) == false){
	  fenetreDeTir.print(x,y,' ', col);
	  y++;
	  fenetreDeTir.print(x,y,p, col);
	}

	else{
	  int i = 2;
	  bool exit = false;
	  while(!exit){ // On fait une boucle pour trouver la prochaine case que l'on peut atteindre
	    if(grilleDeTir.appartientATabCases(x, y+i) == false){
	      exit = true; // On a trouvé la prochaine case
	    }
	    else
	      i++;
	  }
	  if(y+i >= fenetreDeTir.getHauteur()){
	    i = 0;
	  }
	  fenetreDeTir.print(x,y,' ', col);
	  y+=i;
	  fenetreDeTir.print(x,y,p, col);
	}
	break;
	
      case KEY_LEFT:
	if (x != 0 && grilleDeTir.appartientATabCases(x-1, y) == false){
	  fenetreDeTir.print(x,y,' ', col);
	  x--;
	  fenetreDeTir.print(x,y,p, col);
	}

	else{
	  int i = 2;
	  bool exit = false;
	  while(!exit){ // On fait une boucle pour trouver la prochaine case que l'on peut atteindre
	    if(grilleDeTir.appartientATabCases(x-i, y) == false){
	      exit = true; // On a trouvé la prochaine case
	    }
	    else
	      i++;
	  }
	  int aux = x-i; // On passe par une valeur auxiliaire int car y est un size_t, donc un entier positif
	  if(aux < 0){
	    i = 0;
	  }
	  fenetreDeTir.print(x,y,' ', col);
	  x-=i;
	  fenetreDeTir.print(x,y,p, col);
	}
	break;
	
      case KEY_RIGHT:
	if (x+1 != fenetreDeTir.getLargeur() && grilleDeTir.appartientATabCases(x+1, y) == false){
	  fenetreDeTir.print(x,y,' ', col);
	  x++;
	  fenetreDeTir.print(x,y,p, col);
	}

	else{
	  int i = 2;
	  bool exit = false;
	  while(!exit){ // On fait une boucle pour trouver la prochaine case que l'on peut atteindre
	    if(grilleDeTir.appartientATabCases(x+i, y) == false){
	      exit = true; // On a trouvé la prochaine case
	    }
	    else
	      i++;
	  }
	  if(x+i >= fenetreDeTir.getLargeur()){ // Si la case qu'on a trouvée sort de la fenêtre, on ne fait rien et on reste à la même coordonnée, donc i = 0
	    i = 0;
	  }
	  fenetreDeTir.print(x,y,' ', col);
	  x+=i;
	  fenetreDeTir.print(x,y,p, col);
	}
	break;
	
      case 32: // Valeur ASCII pour désigner la touche espace
	fenetreDeTir.print(x,y,' ', col);
	if(grilleDeTir.appartientAUnNavire(x, y) == true){
	  Navire* N = grilleDeTir.aQuelNavireAppartientCase(x, y);
	  if(N != NULL){
	    Case* C = N->findCase(x,y);
	    if(C->getTouchee() == false){
	      C->setTouchee(true);
	      grilleDeTir.ajouterCase(Case(x,y,false,true,true));
	      grilleDeTir.afficher_tabCases(fenetreDeTir);
	    }
	  }
	}
	
	else{
	  grilleDeTir.ajouterCase(Case(x, y));
	  grilleDeTir.afficher_tabCases(fenetreDeTir);
	}
	
	tir = true;
	break;
      }
    }
}

void Jeu::lancerPartie(Window& joueur, Grille& Joueur, Window& ia, Grille& IA){
  size_t first = rand() % 2;
  bool fin = false;
  while (!fin){
    if (first == 0){ // Le joueur commence, il tire
      tirer(ia, IA);
      if (IA.getNbNaviresCoules() == 5)
	fin = true;
      else{
	Joueur.tirCase(joueur);
	Joueur.afficher_grille(joueur);
	if (Joueur.getNbNaviresCoules() == 5)
	  fin = true;
      }
    }
    
    if (first == 1){ // L'IA commence
      Joueur.tirCase(joueur);
      if (Joueur.getNbNaviresCoules() == 5)
	fin = true;
      else{
	Joueur.afficher_grille(joueur);
	tirer(ia, IA);
	if (IA.getNbNaviresCoules() == 5)
	  fin = true;
      }
    }

  }

  // Mettre message de fin ici

}

void Jeu::placerNavire(Window* joueur, Grille* Joueur, Navire* aDeplacer){

  size_t ch;
  
  while((ch = getch()) != 10) // Touche pour confirmer l'emplacement du navire, là c'est entrée
    {     
      switch (ch) {
	case 32:
	  aDeplacer->supprimer_navire(*joueur);
	  aDeplacer->PivoterNavireDroite();
	  aDeplacer->afficher_navire(*joueur, aDeplacer->getCouleur(), SN);
	break;

      case KEY_UP:
	if(aDeplacer->Y_min_case_navire() != 0 && Joueur->peutDeplacer(aDeplacer, "haut") == true){
	  aDeplacer->supprimer_navire(*joueur); // Suppresion graphique
	  aDeplacer->deplacerNavireHaut();
	  aDeplacer->afficher_navire(*joueur, aDeplacer->getCouleur(), SN); // Affichage graphique de la nouvelle position
	}
	break;
	  
      case KEY_DOWN:
	if(aDeplacer->Y_max_case_navire()+1 != joueur->getHauteur() && Joueur->peutDeplacer(aDeplacer, "bas") == true){
	  aDeplacer->supprimer_navire(*joueur); // Suppresion graphique
	  aDeplacer->deplacerNavireBas();
	  aDeplacer->afficher_navire(*joueur, aDeplacer->getCouleur(), SN); // Affichage graphique de la nouvelle position
	}
	break;
	  
      case KEY_LEFT:
	if(aDeplacer->X_min_case_navire() != 0  && Joueur->peutDeplacer(aDeplacer, "gauche") == true){
	  aDeplacer->supprimer_navire(*joueur); // Suppresion graphique
	  aDeplacer->deplacerNavireGauche();
	  aDeplacer->afficher_navire(*joueur, aDeplacer->getCouleur(), SN); // Affichage graphique de la nouvelle position
	}
	break;
	  
      case KEY_RIGHT:
	if(aDeplacer->X_max_case_navire()+1 != joueur->getLargeur() && Joueur->peutDeplacer(aDeplacer, "droite") == true){
	  aDeplacer->supprimer_navire(*joueur); // Suppresion graphique
	  aDeplacer->deplacerNavireDroite();
	  aDeplacer->afficher_navire(*joueur, aDeplacer->getCouleur(), SN); // Affichage graphique de la nouvelle position
	}
	  break;
      }
    }
}

//void Jeu::selectionnerNavire(Window& flotte, Window* joueur, Grille& Flotte, Grille* Joueur){
void Jeu::selectionnerNavire(size_t numJoueur, Window& flotte, Grille& Flotte){

  size_t ch;

  size_t x=0, y=0;
  size_t nbNaviresPlaces = 0;
  char p='X';
  Color col=WBLACK;
  
  Grille* Joueur = &(listeJoueurs[numJoueur].getGrille());
  Window* joueur = &(listeJoueurs[numJoueur].getFenetre());
		     
  
  flotte.print(x,y,p,col);
  
  while((ch = getch()) != 'q' && nbNaviresPlaces < 5)
    {     
      switch (ch) {
      case KEY_UP:	  
	if (y != 0){
	  if(Flotte.appartientAGrille(x, y-1) == true && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,SN,Flotte.aQuelNavireAppartientCase(x,y)->getCouleur());
	    y--;
	    flotte.print(x,y,p, Flotte.aQuelNavireAppartientCase(x, y)->getCouleur());
	  }

	  else if(Flotte.appartientAGrille(x,y-1) == false && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,SN,Flotte.aQuelNavireAppartientCase(x,y)->getCouleur());
	    y--;
	    flotte.print(x,y,p,col);
	  }

	  else if(Flotte.appartientAGrille(x,y-1) == true && Flotte.appartientAGrille(x,y) == false){
	    flotte.print(x,y,' ', col);
	    y--;
	    flotte.print(x,y,p,Flotte.aQuelNavireAppartientCase(x,y)->getCouleur());
	  }
	  
	  else{
	    flotte.print(x,y,' ', col);
	    y--;
	    flotte.print(x,y,p, col);
	  }
	}
	break;
      case KEY_DOWN:
	if (y+1 != flotte.getHauteur()){
	  if(Flotte.appartientAGrille(x, y+1) == true && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,SN,Flotte.aQuelNavireAppartientCase(x,y)->getCouleur());
	    y++;
	    flotte.print(x,y,p, Flotte.aQuelNavireAppartientCase(x, y)->getCouleur());
	  }

	  else if(Flotte.appartientAGrille(x,y+1) == false && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,SN,Flotte.aQuelNavireAppartientCase(x,y)->getCouleur());
	    y++;
	    flotte.print(x,y,p,col);
	  }

	  else if(Flotte.appartientAGrille(x,y+1) == true && Flotte.appartientAGrille(x,y) == false){
	    flotte.print(x,y,' ', col);
	    y++;
	    flotte.print(x,y,p,Flotte.aQuelNavireAppartientCase(x,y)->getCouleur());
	  }
	  
	  else{
	    flotte.print(x,y,' ', col);
	    y++;
	    flotte.print(x,y,p, col);
	  }
	}
	break;
      case KEY_LEFT:
	if (x != 0){
	  if(Flotte.appartientAGrille(x-1, y) == true && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,SN,Flotte.aQuelNavireAppartientCase(x,y)->getCouleur());
	    x--;
	    flotte.print(x,y,p, Flotte.aQuelNavireAppartientCase(x, y)->getCouleur());
	  }

	  else if(Flotte.appartientAGrille(x-1,y) == false && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,SN,Flotte.aQuelNavireAppartientCase(x,y)->getCouleur());
	    x--;
	    flotte.print(x,y,p,col);
	  }

	  else if(Flotte.appartientAGrille(x-1,y) == true && Flotte.appartientAGrille(x,y) == false){
	    flotte.print(x,y,' ', col);
	    x--;
	    flotte.print(x,y,p,Flotte.aQuelNavireAppartientCase(x,y)->getCouleur());
	  }
	  
	  else{
	    flotte.print(x,y,' ', col);
	    x--;
	    flotte.print(x,y,p, col);
	  }
	}
	  break;
	case KEY_RIGHT:
	  if (x+1 != flotte.getLargeur()){
	    if(Flotte.appartientAGrille(x+1, y) == true && Flotte.appartientAGrille(x,y) == true){
	      flotte.print(x,y,SN,Flotte.aQuelNavireAppartientCase(x,y)->getCouleur());
	      x++;
	      flotte.print(x,y,p,Flotte.aQuelNavireAppartientCase(x, y)->getCouleur());
	    }

	    else if(Flotte.appartientAGrille(x+1,y) == false && Flotte.appartientAGrille(x,y) == true){
	      flotte.print(x,y,SN,Flotte.aQuelNavireAppartientCase(x,y)->getCouleur());
	      x++;
	      flotte.print(x,y,p,col);
	    }

	    else if(Flotte.appartientAGrille(x+1,y) == true && Flotte.appartientAGrille(x,y) == false){
	      flotte.print(x,y,' ', col);
	      x++;
	      flotte.print(x,y,p,Flotte.aQuelNavireAppartientCase(x,y)->getCouleur());
	    }
	  
	    else{
	      flotte.print(x,y,' ', col);
	      x++;
	      flotte.print(x,y,p, col);
	    }
	  }
	  break;
      case 10: // Valeur ASCII pour désigner la touche entrée
	if (Flotte.appartientAGrille(x, y) == true){
	 	  
	  Navire* aSupprimer = Flotte.aQuelNavireAppartientCase(x,y);
	  Navire aDeplacer = *aSupprimer;

	  // L'algorithme suivant sert à éviter que l'on place un navire sur un navire qui a déjà été placé auparavant
	  // Le code détermine la prochaine position valide pour pouvoir y insérer le navire que l'on veut placer
	  // Une position valide est une position où la superficie entière du navire ne doit pas dépasser la fenêtre et où aucune case navire ne touche la case d'un autre navire

	  bool chevauchement = false; 
	  for(size_t i=0; i<aDeplacer.getNbCases(); i++){
	    for(size_t i=0; i<aDeplacer.getNbCases(); i++){ // On parcourt chaque case du navire qu'on veut placer
	      Navire p;
	      if(Joueur->aQuelNavireAppartientCase(x,y)!= NULL) p = Joueur->aQuelNavireAppartientCase(x,y);
	      if(Joueur->appartientAUnNavire(aDeplacer.at(i).getX(), aDeplacer.at(i).getY()) == true && p != aDeplacer) // Si à la position d'une case du navire est occupée dans l'autre grille
		chevauchement = true;
	    }
	  }

	  if (chevauchement == true){
	    for(size_t i=0; i<aDeplacer.getNbCases(); i++){
	      Navire p;
	      if(Joueur->aQuelNavireAppartientCase(x,y)!= NULL) p = Joueur->aQuelNavireAppartientCase(x,y);
	      while(Joueur->appartientAUnNavire(aDeplacer.at(i).getX(), aDeplacer.at(i).getY()) != false && p != aDeplacer){ // On répète l'action tant qu'on n'a pas une position valide
		aDeplacer.deplacerNavireDroite();
		if (aDeplacer.X_max_case_navire() >= joueur->getLargeur()){ // Si après avoir déplacé le navire vers la droite et que la case la plus à droite du navire sort de la fenere
		  aDeplacer.deplacerNavire(0,aDeplacer.at(0).getY()+1); // On remet alors le navire à la position x=0, en augmantant y de 1, comme un retour chariot
		}
	      }
	      // En sortant de la boucle, le navire sera placé à la position valide trouvée
	    }
	  }

	  // On enlève le navire séléctionné de la grille Flotte pour l'ajouter à la grille Joueur :
	  Joueur->ajouterNavire(aDeplacer, *joueur);
	  Flotte.enleverNavire(Flotte.findNavire(aSupprimer), flotte); // Suppression de la donnée du navire dans la grille Flotte

	  Navire* navire = &(Joueur->getNavire(Joueur->findNavire(aDeplacer))); // Pointeur sur le navire qu'on vient de deplacer et placé pour pouvoir le déplacer avec la fonction placerNavire
	  placerNavire(joueur, Joueur, navire);
	  
	  nbNaviresPlaces++;
	  
	  flotte.print(x,y,p,col);
	  
	  // Les destructeurs des pointeurs de navire sont appelés implicitement ici, à la fin du bloc, et seront delete
	}	
	break;
      }

    }
}

void Jeu::init(){
  Window titre(3,30,12,0);
  titre.setCouleurBordure(BRED);

  Window F(hautFenetre, largFenetre,2,6);
  listeJoueurs[0].setFenetre(F); // <- PB
  F.setCouleurBordure(BBLUE);
  
  size_t x = 5+largFenetre;
  for(int i=1;i<nombreJoueurs;i++){
    Window G(hautFenetre, largFenetre, x, 6);
    listeJoueurs[i].setFenetre(G);
    listeJoueurs[i].getFenetre().setCouleurBordure(BBLUE);			     
    x+=largFenetre+3;
    }
  
  Window flotte(7,21,6,32);
  flotte.setCouleurBordure(BBLUE);
  
  titre.print(8,1,"Bataille navale", WRED);

  Navire porteAvions(5, 2, 2, BBLUE);
  Navire croiseur(4, 4, 2, BGREEN);
  Navire contreTorpilleur(3, 6, 2, BYELLOW);
  Navire sousMarin(3, 8, 2, BMAGENTA);
  Navire torpilleur(2, 10, 2, BRED);

  // Suivant le mode, si l'utilisateur a choisi les modes personnalisé ou non on appelle la fonction suivante :
  
  Navire* tabPerso;
  tabPerso = chargerNavirePerso();

  tabPerso[0].deplacerNavire(2, 1);
  tabPerso[1].deplacerNavire(7, 1);
  tabPerso[2].deplacerNavire(11, 1);
  tabPerso[3].deplacerNavire(13, 1);
  tabPerso[4].deplacerNavire(18, 1);

  // Grille Flotte(tabPerso[0], tabPerso[1], tabPerso[2], tabPerso[3], tabPerso[4]);
  //Flotte.afficher_grille(flotte);
  
  //Grille Flotte(porteAvions, croiseur, contreTorpilleur, sousMarin, torpilleur);

  // Grille IA(porteAvions, croiseur, contreTorpilleur, sousMarin, torpilleur);
  
  // Fonction pour que le joueur se déplace dans une grille donnée, ici la flotte et pour qu'il y séléctionne un navire
  //selectionnerNavire(flotte, listeJoueurs[0].getFenetre(), Flotte, listeJoueurs[0].getGrille()); // Au début on a besoin de se déplacer dans la flotte pour accéder aux bateaux et les placer
  for(size_t i=0; i<nombreJoueurs; i++){
    if (listeJoueurs[i].getIA() == false){
      Grille Flotte(tabPerso[0], tabPerso[1], tabPerso[2], tabPerso[3], tabPerso[4]);
      Flotte.afficher_grille(flotte);
      selectionnerNavire(i, flotte, Flotte);
    }
  }
  //else placer auto
    
     
  //selectionnerNavire(flotte, joueur, Flotte, Joueur);
  //lancerPartie(joueur, Joueur, ia, IA);
  
}
