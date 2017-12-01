#include "window.h"
#include "navire.h"
#include "case.h"
#include "grille.h"

void deplacement(Window &grille){

  int ch;

  int x=grille.getX()+1, y=grille.getY()+1;
  char p='X';
  Color col=WBLACK;
  grille.print(x,y,p,col);
  
  while((ch = getch()) != 'q')
    {
      switch (ch) {
      case KEY_UP:
	grille.print(x,y,' ', col);
	grille.print(x,--y,p, col);
	break;
      case KEY_DOWN:
	grille.print(x,y,' ', col);
	grille.print(x,++y,p, col);
	break;
      case KEY_LEFT:
	grille.print(x,y,' ', col);
	grille.print(--x,y,p, col);
	break;
      case KEY_RIGHT:
	grille.print(x,y,' ', col);
	grille.print(++x,y,p, col);
      }
    }
}


void batailleNavale(){
  int h=20,w=20;
  Window menu(3,30,1,0);
  Window joueur(h,w,2,6);
  Window IA(h,w,29,6);
  Window flotte(10,15,5,30);
  
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

  //Case c(3,1);
  
  Grille Joueur(porteAvions, croiseur, contreTorpilleur, sousMarin, torpilleur);
  //Joueur.ajouterCase(c);
  Joueur.afficher_grille(flotte);
  
  // Fonction pour que le joueur se déplace dans une grille donnée en paramètre
  deplacement(joueur); // Au début on a besoin de se déplacer dans la flotte pour accéder aux bateaux et les transférer vers la grille du joueur
  
}

int main(){
  startProgramX();
  batailleNavale();
  stopProgramX();
  return 0;
}
