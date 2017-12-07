#include "window.h"
#include "navire.h"
#include "case.h"
#include "grille.h"

void lancerPartie(){
  /*
Tirage au sort
Si joueur commence -> tirerGrille(IA)
Si IA commence -> tirIAsurJoueur(joueur)
while grille.getNbBateauxCoules != nbBateaux
sinon il perd

  */
  return;
}

void placerNavire(Window& joueur, Grille& Joueur, Navire &aDeplacer){

  int ch;

  int x=0, y=0;
  char p='X';
  Color col=WBLACK;
  
  while((ch = getch()) != 10) // Touche pour confirmer l'emplacement du navire, là c'est entrée
    {     
      switch (ch) {
	//case 10:  Faire ici 2 case une pour espace et l'autre Maj+espace pour pivoter
	break;

      case KEY_UP:
	if(aDeplacer.Y_min_case_navire() > 0)
	  aDeplacer.deplacerNavireHaut(joueur);
	break;
	  
      case KEY_DOWN:
	if(((joueur.getHauteur()-1) - aDeplacer.Y_max_case_navire()) != 0)
	  aDeplacer.deplacerNavireBas(joueur);
	break;
	  
      case KEY_LEFT:
	if(aDeplacer.X_min_case_navire() > 0)
	  aDeplacer.deplacerNavireGauche(joueur);
	break;
	  
      case KEY_RIGHT:
	if((joueur.getHauteur() - aDeplacer.X_max_case_navire()) -1 != 0)
	  aDeplacer.deplacerNavireDroite(joueur);
      }
    }
}

void selectionnerNavire(Window& flotte, Window& joueur, Grille& Flotte, Grille& Joueur){

  int ch;

  int x=0, y=0;
  int nbNaviresPlaces = 0;
  char p='X';
  Color col=WBLACK;
  flotte.print(x,y,p,col);
  
  while((ch = getch()) != 'q' && nbNaviresPlaces < 5)
    {     
      switch (ch) {
      case KEY_UP:	  
	if (y-1 < 0 == false){
	  if(Flotte.appartientAGrille(x, y-1) == true && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,'_',Flotte.aQuelNavireAppartientCase(x,y).getCouleur());
	    flotte.print(x,--y,p, Flotte.aQuelNavireAppartientCase(x, y-1).getCouleur());
	  }

	  else if(Flotte.appartientAGrille(x,y-1) == false && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,'_',Flotte.aQuelNavireAppartientCase(x,y).getCouleur());
	    flotte.print(x,--y,p,col);
	  }

	  else if(Flotte.appartientAGrille(x,y-1) == true && Flotte.appartientAGrille(x,y) == false){
	    flotte.print(x,y,' ', col);
	    flotte.print(x,--y,p,Flotte.aQuelNavireAppartientCase(x,y-1).getCouleur());
	  }
	  
	  else{
	    flotte.print(x,y,' ', col);
	    flotte.print(x,--y,p, col);
	  }
	}
	break;
      case KEY_DOWN:
	if (y+2 > flotte.getHauteur() == false){
	  if(Flotte.appartientAGrille(x, y+1) == true && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,'_',Flotte.aQuelNavireAppartientCase(x,y).getCouleur());
	    flotte.print(x,++y,p, Flotte.aQuelNavireAppartientCase(x, y+1).getCouleur());
	  }

	  else if(Flotte.appartientAGrille(x,y+1) == false && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,'_',Flotte.aQuelNavireAppartientCase(x,y).getCouleur());
	    flotte.print(x,++y,p,col);
	  }

	  else if(Flotte.appartientAGrille(x,y+1) == true && Flotte.appartientAGrille(x,y) == false){
	    flotte.print(x,y,' ', col);
	    flotte.print(x,++y,p,Flotte.aQuelNavireAppartientCase(x,y+1).getCouleur());
	  }
	  
	  else{
	    flotte.print(x,y,' ', col);
	    flotte.print(x,++y,p, col);
	  }
	}
	break;
      case KEY_LEFT:
	if (x-1 < 0 == false){
	  if(Flotte.appartientAGrille(x-1, y) == true && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,'_',Flotte.aQuelNavireAppartientCase(x,y).getCouleur());
	    flotte.print(--x,y,p, Flotte.aQuelNavireAppartientCase(x-1, y).getCouleur());
	  }

	  else if(Flotte.appartientAGrille(x-1,y) == false && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,'_',Flotte.aQuelNavireAppartientCase(x,y).getCouleur());
	    flotte.print(--x,y,p,col);
	  }

	  else if(Flotte.appartientAGrille(x-1,y) == true && Flotte.appartientAGrille(x,y) == false){
	    flotte.print(x,y,' ', col);
	    flotte.print(--x,y,p,Flotte.aQuelNavireAppartientCase(x-1,y).getCouleur());
	  }
	  
	  else{
	    flotte.print(x,y,' ', col);
	    flotte.print(--x,y,p, col);
	  }
	}
	break;
      case KEY_RIGHT:
	if (x+2 > flotte.getLargeur() == false){
	  if(Flotte.appartientAGrille(x+1, y) == true && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,'_',Flotte.aQuelNavireAppartientCase(x,y).getCouleur());
	    flotte.print(++x,y,p,Flotte.aQuelNavireAppartientCase(x+1, y).getCouleur());
	  }

	  else if(Flotte.appartientAGrille(x+1,y) == false && Flotte.appartientAGrille(x,y) == true){
	    flotte.print(x,y,'_',Flotte.aQuelNavireAppartientCase(x,y).getCouleur());
	    flotte.print(++x,y,p,col);
	  }

	  else if(Flotte.appartientAGrille(x+1,y) == true && Flotte.appartientAGrille(x,y) == false){
	    flotte.print(x,y,' ', col);
	    flotte.print(++x,y,p,Flotte.aQuelNavireAppartientCase(x+1,y).getCouleur());
	  }
	  
	  else{
	    flotte.print(x,y,' ', col);
	    flotte.print(++x,y,p, col);
	  }
	}
	break;
      case 10: // Valeur ASCII pour désigner la touche entrée
	if (Flotte.appartientAGrille(x, y) == true){
	  
	  Navire aDeplacer = Flotte.aQuelNavireAppartientCase(x, y);	  
	  // On enlève le navire séléctionné de la grille Flotte pour l'ajouter à la grille Joueur :
	  
	  Flotte.enleverNavire(Flotte.findNavire(aDeplacer), flotte); // Suppression de la donnée du navire dans la grille Flotte
	  Joueur.ajouterNavire(aDeplacer, aDeplacer.getCouleur());
	  
	  Joueur.afficher_grille(joueur);
	  
	  placerNavire(joueur, Joueur, aDeplacer);
	  nbNaviresPlaces++;
	  
	  flotte.print(x,y,p,col);
	}	
	break;
      }

      // Fonctionne quand on sort du while, donc quand tous les navires sont placés et donc on lance la partie :
      lancerPartie();

    }
}


void init(){
  int h=20,w=20;
  Window menu(3,30,1,0);
  Window joueur(h,w,2,6);
  Window IA(h,w,29,6);
  Window flotte(8,13,5,30);
  
  menu.setCouleurBordure(BRED);
  joueur.setCouleurBordure(BBLUE);
  IA.setCouleurBordure(BBLUE);
  flotte.setCouleurBordure(BBLUE);
  
  menu.print(1,1,"Tapez q pour quitter !!!", WRED);

  Navire porteAvions(5, 2, 2, BBLUE);
  Navire croiseur(4, 4, 2, BGREEN);
  Navire contreTorpilleur(3, 6, 2, BYELLOW);
  Navire sousMarin(3, 8, 2, BMAGENTA);
  Navire torpilleur(2, 10, 2, BRED);
  
  Grille Flotte(porteAvions, croiseur, contreTorpilleur, sousMarin, torpilleur);
  Grille Joueur;
  
  Flotte.afficher_grille(flotte);
  
  // Fonction pour que le joueur se déplace dans une grille donnée, ici la flotte et pour qu'il y séléctionne un navire
  selectionnerNavire(flotte, joueur, Flotte, Joueur); // Au début on a besoin de se déplacer dans la flotte pour accéder aux bateaux et les placer
  
}

int main(){
  startProgramX();
  init();
  stopProgramX();
  return 0;
}
