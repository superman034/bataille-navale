#include "window.h"
#include "navire.h"
#include "case.h"
#include "grille.h"
#include <stdlib.h> // Pour la fonction rand()
#include <iostream>

#define SN '-'
// SN = Le symbole affiché à chaque case d'un navire

void tirer(Window& fenetreDeTir, Grille grilleDeTir){ // Pas fini
  size_t ch;
  size_t x=0, y=0;
  char p='X';
  Color col=WBLACK;
  fenetreDeTir.print(x,y,p,col);
  
  while((ch = getch()) != 10)
    {     
      switch (ch) {
      case KEY_UP:	  
	if ((y-1 < 0) == false){
	}
	break;
	
      case KEY_DOWN:
	if ((y+2 > fenetreDeTir.getHauteur()) == false){
	}
	break;
	
      case KEY_LEFT:
	if ((x-1 < 0) == false){
	}
	break;
	
      case KEY_RIGHT:
	if ((x+2 > fenetreDeTir.getLargeur()) == false){
	}
	break;
	
      case 10: // Valeur ASCII pour désigner la touche entrée
	//tir
	break;
      }

    }
  
}

void lancerPartie(Window& joueur, Grille& Joueur, Window& ia, Grille& IA){
  size_t first = rand() % 2;
  /*
    Tirage au sort
    Si joueur commence -> tirerGrille(IA)
    Si IA commence -> tirIAsurJoueur(joueur)
    while grille.getNbBateauxCoules != nbBateaux
    sinon il perd

  */

  if (first == 0){ // Le joueur commence, il tire
    while (Joueur.getNbNaviresCoules() < 5 || IA.getNbNaviresCoules() < 5){
      tirer(ia, IA);
      Joueur.tirCase(joueur);
      Joueur.afficher_grille(joueur);
    }
  }
  
  else
    if (first == 1){ // L'IA commence
      while (Joueur.getNbNaviresCoules() < 5 || IA.getNbNaviresCoules() < 5){
      Joueur.tirCase(joueur);
      Joueur.afficher_grille(joueur);
      tirer(ia, IA);
      }
    }    

  /* size_t ch; Code pour tester l'algorithme de tir

  while((ch = getch()) != 'q') // Touche pour confirmer l'emplacement du navire, là c'est entrée
    {     
      switch (ch) {
      case 10:
	Joueur.tirCase(joueur);
	Joueur.afficher_grille(joueur);
	break;
      }
    }
  */
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
	if(aDeplacer->Y_min_case_navire() > 0){
	  aDeplacer->supprimer_navire(joueur); // Suppresion graphique
	  aDeplacer->deplacerNavireHaut();
	  aDeplacer->afficher_navire(joueur, aDeplacer->getCouleur(), SN); // Affichage graphique de la nouvelle position
	}
	break;
	  
      case KEY_DOWN:
	if(((joueur.getHauteur()-1) - aDeplacer->Y_max_case_navire()) != 0)
	  aDeplacer->supprimer_navire(joueur); // Suppresion graphique
	  aDeplacer->deplacerNavireBas();
	  aDeplacer->afficher_navire(joueur, aDeplacer->getCouleur(), SN); // Affichage graphique de la nouvelle position
	break;
	  
      case KEY_LEFT:
	if(aDeplacer->X_min_case_navire() > 0)
	  aDeplacer->supprimer_navire(joueur); // Suppresion graphique
	  aDeplacer->deplacerNavireGauche();
	  aDeplacer->afficher_navire(joueur, aDeplacer->getCouleur(), SN); // Affichage graphique de la nouvelle position
	break;
	  
      case KEY_RIGHT:
	if((joueur.getHauteur() - aDeplacer->X_max_case_navire()) -1 != 0)
	  aDeplacer->supprimer_navire(joueur); // Suppresion graphique
	  aDeplacer->deplacerNavireDroite();
	  aDeplacer->afficher_navire(joueur, aDeplacer->getCouleur(), SN); // Affichage graphique de la nouvelle position
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
	if ((y-1 < 0) == false){
	  if(Flotte.appartientAGrille(x, y-1) == true && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,SN,Flotte.aQuelNavireAppartientCase(x,y)->getCouleur());
	    flotte.print(x,--y,p, Flotte.aQuelNavireAppartientCase(x, y-1)->getCouleur());
	  }

	  else if(Flotte.appartientAGrille(x,y-1) == false && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,SN,Flotte.aQuelNavireAppartientCase(x,y)->getCouleur());
	    flotte.print(x,--y,p,col);
	  }

	  else if(Flotte.appartientAGrille(x,y-1) == true && Flotte.appartientAGrille(x,y) == false){
	    flotte.print(x,y,' ', col);
	    flotte.print(x,--y,p,Flotte.aQuelNavireAppartientCase(x,y-1)->getCouleur());
	  }
	  
	  else{
	    flotte.print(x,y,' ', col);
	    flotte.print(x,--y,p, col);
	  }
	}
	break;
      case KEY_DOWN:
	if ((y+2 > flotte.getHauteur()) == false){
	  if(Flotte.appartientAGrille(x, y+1) == true && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,SN,Flotte.aQuelNavireAppartientCase(x,y)->getCouleur());
	    flotte.print(x,++y,p, Flotte.aQuelNavireAppartientCase(x, y+1)->getCouleur());
	  }

	  else if(Flotte.appartientAGrille(x,y+1) == false && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,SN,Flotte.aQuelNavireAppartientCase(x,y)->getCouleur());
	    flotte.print(x,++y,p,col);
	  }

	  else if(Flotte.appartientAGrille(x,y+1) == true && Flotte.appartientAGrille(x,y) == false){
	    flotte.print(x,y,' ', col);
	    flotte.print(x,++y,p,Flotte.aQuelNavireAppartientCase(x,y+1)->getCouleur());
	  }
	  
	  else{
	    flotte.print(x,y,' ', col);
	    flotte.print(x,++y,p, col);
	  }
	}
	break;
      case KEY_LEFT:
	if ((x-1 < 0) == false){
	  if(Flotte.appartientAGrille(x-1, y) == true && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,SN,Flotte.aQuelNavireAppartientCase(x,y)->getCouleur());
	    flotte.print(--x,y,p, Flotte.aQuelNavireAppartientCase(x-1, y)->getCouleur());
	  }

	  else if(Flotte.appartientAGrille(x-1,y) == false && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,SN,Flotte.aQuelNavireAppartientCase(x,y)->getCouleur());
	    flotte.print(--x,y,p,col);
	  }

	  else if(Flotte.appartientAGrille(x-1,y) == true && Flotte.appartientAGrille(x,y) == false){
	    flotte.print(x,y,' ', col);
	    flotte.print(--x,y,p,Flotte.aQuelNavireAppartientCase(x-1,y)->getCouleur());
	  }
	  
	  else{
	    flotte.print(x,y,' ', col);
	    flotte.print(--x,y,p, col);
	  }
	}
	break;
      case KEY_RIGHT:
	if ((x+2 > flotte.getLargeur()) == false){
	  if(Flotte.appartientAGrille(x+1, y) == true && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,SN,Flotte.aQuelNavireAppartientCase(x,y)->getCouleur());
	    flotte.print(++x,y,p,Flotte.aQuelNavireAppartientCase(x+1, y)->getCouleur());
	  }

	  else if(Flotte.appartientAGrille(x+1,y) == false && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,SN,Flotte.aQuelNavireAppartientCase(x,y)->getCouleur());
	    flotte.print(++x,y,p,col);
	  }

	  else if(Flotte.appartientAGrille(x+1,y) == true && Flotte.appartientAGrille(x,y) == false){
	    flotte.print(x,y,' ', col);
	    flotte.print(++x,y,p,Flotte.aQuelNavireAppartientCase(x+1,y)->getCouleur());
	  }
	  
	  else{
	    flotte.print(x,y,' ', col);
	    flotte.print(++x,y,p, col);
	  }
	}
	break;
      case 10: // Valeur ASCII pour désigner la touche entrée
	if (Flotte.appartientAGrille(x, y) == true){
	  
	  // Navire* aDeplacer = NULL;
	  Navire* ptr = Flotte.aQuelNavireAppartientCase(x, y);
	  Navire aDeplacer = *ptr;
	  // On enlève le navire séléctionné de la grille Flotte pour l'ajouter à la grille Joueur :
	  
	  Joueur.ajouterNavire(aDeplacer, joueur);
	  Flotte.enleverNavire(Flotte.findNavire(ptr), flotte); // Suppression de la donnée du navire dans la grille Flotte

	  Navire* ptr2 = Joueur.aQuelNavireAppartientCase(x, y);
	  
	  //Joueur.afficher_grille(joueur);
	  
	  placerNavire(joueur, Joueur, ptr2);
	  nbNaviresPlaces++;
	  
	  flotte.print(x,y,p,col);
	}	
	break;
      }

    }
}


void init(){
  int h=8,w=12;
  Window menu(3,30,1,0);
  Window joueur(h,w,2,6);
  Window ia(h,w,29,6);
  Window flotte(8,13,5,15);
  
  menu.setCouleurBordure(BRED);
  joueur.setCouleurBordure(BBLUE);
  ia.setCouleurBordure(BBLUE);
  flotte.setCouleurBordure(BBLUE);
  
  menu.print(1,1,"Tapez q pour quitter !!!", WRED);

  Navire porteAvions(5, 2, 2, BBLUE);
  Navire croiseur(4, 4, 2, BGREEN);
  Navire contreTorpilleur(3, 6, 2, BYELLOW);
  Navire sousMarin(3, 8, 2, BMAGENTA);
  Navire torpilleur(2, 10, 2, BRED);
  
  Grille Flotte(porteAvions, croiseur, contreTorpilleur, sousMarin, torpilleur);
  Grille Joueur;
  /* Grille IA;
  initGrille(IA); // Place des navires automatiquement
  */
  Grille IA(porteAvions, croiseur, contreTorpilleur, sousMarin, torpilleur);
  
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
