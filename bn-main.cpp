#include "window.h"
#include "navire.h"
#include "case.h"

void deplacement(Window &grille){

  int ch;

  int x=grille.getX()+1, y=grille.getY()+1;
  char p='X';
  //Color col=WCYAN;
  grille.print(x,y,p);
  
  while((ch = getch()) != 'q')
    {
      switch (ch) {
      case '1':
	//col=BMAGENTA;
	break;
      case '2':
	//col=WCYAN;
	break;
      case 'c':
	grille.clear();
	break;
      case KEY_UP:
	grille.print(x,y,' ');
	grille.print(x,--y,p);
	break;
      case KEY_DOWN:
	grille.print(x,y,' ');
	grille.print(x,++y,p);
	break;
      case KEY_LEFT:
	grille.print(x,y,' ');
	grille.print(--x,y,p);
	break;
      case KEY_RIGHT:
	grille.print(x,y,' ');
	grille.print(++x,y,p);
	break;
	/*case '\n':
	x=w/2,y=h/2;
	grille.print(x,y,p);
	break;*/
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
  porteAvions.afficher_navire(flotte, porteAvions.getCouleur());

  Navire croiseur(4, 4, 2, BGREEN);
  croiseur.afficher_navire(flotte, croiseur.getCouleur());

  Navire contreTorpilleur(3, 6, 2, BYELLOW);
  contreTorpilleur.afficher_navire(flotte, contreTorpilleur.getCouleur());

  Navire sousMarin(3, 8, 2, BMAGENTA);
  sousMarin.afficher_navire(flotte, sousMarin.getCouleur());

  Navire torpilleur(2, 10, 2, BRED);
  torpilleur.afficher_navire(flotte, torpilleur.getCouleur());
  
  // Fonction pour que le joueur se déplace dans une grille donnée en paramètre
  deplacement(joueur); // Au début on a besoin de se déplacer dans la flotte pour accéder aux bateaux et les transférer vers la grille du joueur
  
}

int main(){
  startProgramX();
  batailleNavale();
  stopProgramX();
  return 0;
}
