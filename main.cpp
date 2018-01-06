#include <iostream>
#include <cstdlib>
#include <exception>
#include <string>
#include "option.h"
#include "tableau-option.h"
#include "jeu.h"
#include "logs.h"
#include "score.h"

#define HELP_ID          1
#define VERSION_ID       2
#define FICHIER_ID       4
#define AUTEUR_ID        3

#define VERSION 2.0

int main(int argc, char** argv){
  TabOptions opts;
  bool opt_error = false;

  opts.addOption(Option(VERSION_ID, "--version", "-v",
                        "Affiche la version du programme", Option::AUCUN));
  
  opts.addOption(Option(AUTEUR_ID, "--auteur", "-a",
                        "Affiche les auteurs du jeu", Option::AUCUN));
  
  opts.addOption(Option(HELP_ID, "--help", "-h",
                        "Affiche l'aide du programme", Option::AUCUN));

  opts.addOption(Option(FICHIER_ID, "--fichier", "-n",
		        "Charge le nom dans la fonction navire"
		        " à partir du nom passé en paramètre",
		        Option::CHAINE));
  
  std::string nomfichier;

  for (int i = 1; i < argc && !opt_error; i++) {
    if (opts.getOptionId(argv[i]) != -1) {
      // std::cout << "L'option " << argv[i] << " a été trouvée."<<std::endl;
      
      if( ( std::string(argv[i])==std::string("-v") )  || ( std::string(argv[i])==std::string("--version") ) )
      {
	std::cout<<"La version du programme est " << VERSION <<std::endl;
      }
      
      if( ( std::string(argv[i])==std::string("-a") )  || ( std::string(argv[i])==std::string("--auteur") ))
	{
	  std::cout<<"Les auteurs sont : Alex, Abdellah, Anas et Smaail."<<std::endl;
	}

      if( ( std::string(argv[i])==std::string("-h") ) || ( std::string(argv[i])==std::string("--help") ))
	{
	  opts.print();
	}
      
      
      if (opts.optionHasArgument(argv[i])) {
	std::cout << "L'option attend un argument de type "
	     << Type2String(opts.optionArgumentType(argv[i]));
	std::cout << " => " << (++i < argc ?
				std::string(argv[i])=="-a"? "Erreur" : std::string(argv[i])=="-v"? "Erreur" : std::string(argv[i])=="-h"? "Erreur" : argv[i] : "Erreur") << std::endl;
	if(i<argc)
	  if( (std::string(argv[i])!="-a") || (std::string(argv[i])!="-v") || (std::string(argv[i])!="-h")){
	    nomfichier=argv[i]; // Le nom du fichier est récuperé ici
	    Jeu BatailleNavale;
	    BatailleNavale.demarrer(nomfichier);
	  }
	
      }
      std::cout << std::endl; 
    } else {
      opt_error = true;
    }
  }
  if (opt_error) {
    std::cout << "Usage : " << argv[0] << " [Options]" << std::endl;
    std::cout << "--help pour l'aide !"<<std::endl;
    std::terminate();
  }

  if(argc==1){
    Jeu BatailleNavale;
    BatailleNavale.demarrer("rien");
  }

  return 0;
}

