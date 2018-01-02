#include "window.h"
#include "navire.h"
#include "case.h"
#include "grille.h"
#include "chargerNavirePerso.h"
#include <stdlib.h> // Pour la fonction rand()
#include <iostream>

using namespace std;

#define SN '-'
// SN = Le symbole affiché à chaque case d'un navire

void tirer(Window& fenetreDeTir, Grille& grilleDeTir){ // Pas fini
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

void lancerPartie(Window& joueur, Grille& Joueur, Window& ia, Grille& IA){
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
void placerNavire(Window& joueur, Grille& Joueur, Navire* aDeplacer){

  size_t ch;
  
  while((ch = getch()) != 10) // Touche pour confirmer l'emplacement du navire, là c'est entrée
    {     
      switch (ch) {
	case 32:
	  aDeplacer->supprimer_navire(joueur);
	  aDeplacer->PivoterNavireDroite();
	  aDeplacer->afficher_navire(joueur, aDeplacer->getCouleur(), SN);
	break;

      case KEY_UP:
	if(aDeplacer->Y_min_case_navire() != 0 && Joueur.peutDeplacer(aDeplacer, "haut") == true){
	  aDeplacer->supprimer_navire(joueur); // Suppresion graphique
	  aDeplacer->deplacerNavireHaut();
	  aDeplacer->afficher_navire(joueur, aDeplacer->getCouleur(), SN); // Affichage graphique de la nouvelle position
	}
	break;
	  
      case KEY_DOWN:
	if(aDeplacer->Y_max_case_navire()+1 != joueur.getHauteur() && Joueur.peutDeplacer(aDeplacer, "bas") == true){
	  aDeplacer->supprimer_navire(joueur); // Suppresion graphique
	  aDeplacer->deplacerNavireBas();
	  aDeplacer->afficher_navire(joueur, aDeplacer->getCouleur(), SN); // Affichage graphique de la nouvelle position
	}
	break;
	  
      case KEY_LEFT:
	if(aDeplacer->X_min_case_navire() != 0  && Joueur.peutDeplacer(aDeplacer, "gauche") == true){
	  aDeplacer->supprimer_navire(joueur); // Suppresion graphique
	  aDeplacer->deplacerNavireGauche();
	  aDeplacer->afficher_navire(joueur, aDeplacer->getCouleur(), SN); // Affichage graphique de la nouvelle position
	}
	break;
	  
      case KEY_RIGHT:
	if(aDeplacer->X_max_case_navire()+1 != joueur.getLargeur() && Joueur.peutDeplacer(aDeplacer, "droite") == true){
	  aDeplacer->supprimer_navire(joueur); // Suppresion graphique
	  aDeplacer->deplacerNavireDroite();
	  aDeplacer->afficher_navire(joueur, aDeplacer->getCouleur(), SN); // Affichage graphique de la nouvelle position
	}
	  break;
      }
    }
}

void selectionnerNavire(Window& flotte, Window& joueur, Grille& Flotte, Grille& Joueur){

  size_t ch;

  size_t x=0, y=0;
  size_t nbNaviresPlaces = 0;
  char p='X';
  Color col=WBLACK;
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
	      if(Joueur.aQuelNavireAppartientCase(x,y)!= NULL) p = Joueur.aQuelNavireAppartientCase(x,y);
	      if(Joueur.appartientAUnNavire(aDeplacer.at(i).getX(), aDeplacer.at(i).getY()) == true && p != aDeplacer) // Si à la position d'une case du navire est occupée dans l'autre grille
		chevauchement = true;
	    }
	  }

	  if (chevauchement == true){
	    for(size_t i=0; i<aDeplacer.getNbCases(); i++){
	      Navire p;
	      if(Joueur.aQuelNavireAppartientCase(x,y)!= NULL) p = Joueur.aQuelNavireAppartientCase(x,y);
	      while(Joueur.appartientAUnNavire(aDeplacer.at(i).getX(), aDeplacer.at(i).getY()) != false && p != aDeplacer){ // On répète l'action tant qu'on n'a pas une position valide
		aDeplacer.deplacerNavireDroite();
		if (aDeplacer.X_max_case_navire() >= joueur.getLargeur()){ // Si après avoir déplacé le navire vers la droite et que la case la plus à droite du navire sort de la fenere
		  aDeplacer.deplacerNavire(0,aDeplacer.at(0).getY()+1); // On remet alors le navire à la position x=0, en augmantant y de 1, comme un retour chariot
		}
	      }
	      // En sortant de la boucle, le navire sera placé à la position valide trouvée
	    }
	  }

	  // On enlève le navire séléctionné de la grille Flotte pour l'ajouter à la grille Joueur :
	  Joueur.ajouterNavire(aDeplacer, joueur);
	  Flotte.enleverNavire(Flotte.findNavire(aSupprimer), flotte); // Suppression de la donnée du navire dans la grille Flotte

	  Navire* test = &(Joueur.getNavire(Joueur.findNavire(aDeplacer))); // Pointeur sur le navire qu'on vient de deplacer et placé pour pouvoir le déplacer avec la fonction placerNavire	  
	  placerNavire(joueur, Joueur, test);
	  
	  nbNaviresPlaces++;
	  
	  flotte.print(x,y,p,col);
	  
	  // Les destructeurs des pointeurs de navire sont appelés implicitement ici, à la fin du bloc, et seront delete
	}	
	break;
      }

    }
}

void init(){
  int h=20,w=20;
  Window titre(3,30,12,0);
  Window joueur(h,w,2,6);
  Window ia(h,w,29,6);
  Window flotte(8,20,6,32);
  
  titre.setCouleurBordure(BRED);
  joueur.setCouleurBordure(BBLUE);
  ia.setCouleurBordure(BBLUE);
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

  tabPerso[0].deplacerNavire(2, 2);
  tabPerso[1].deplacerNavire(6, 1);
  tabPerso[2].deplacerNavire(10, 1);
  tabPerso[3].deplacerNavire(12, 1);
  tabPerso[4].deplacerNavire(17, 1);
  
  //Grille Flotte(porteAvions, croiseur, contreTorpilleur, sousMarin, torpilleur);

  Grille Flotte(tabPerso[0], tabPerso[1], tabPerso[2], tabPerso[3], tabPerso[4]);
  Grille IA = Flotte;
  Grille Joueur;
  /* Grille IA;
  initGrille(IA); // Place des navires automatiquement
  */
  // Grille IA(porteAvions, croiseur, contreTorpilleur, sousMarin, torpilleur);
  
  Flotte.afficher_grille(flotte);
  
  // Fonction pour que le joueur se déplace dans une grille donnée, ici la flotte et pour qu'il y séléctionne un navire
  selectionnerNavire(flotte, joueur, Flotte, Joueur); // Au début on a besoin de se déplacer dans la flotte pour accéder aux bateaux et les placer
  lancerPartie(joueur, Joueur, ia, IA);
  
}

int main(){
  startProgramX();
  init();
  stopProgramX();
  return 0;
}
