#include <iostream>
#include "option.h"
#include "tabOptions.h"
#include <string.h>
#include <string>

using namespace std;

#define HELP_ID          1
#define VERSION_ID       2
#define FICHIER_ID       4
#define AUTEUR_ID        3

int main(int argc, char** argv) {



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

  
  string nom; // nom du fichier Chef (anas)
  

  for (int i = 1; i < argc && !opt_error; i++) {
    if (opts.getOptionId(argv[i]) != -1) {
      cout << "L'option " << argv[i] << " a été trouvée."<<endl;
      
      if( ( string(argv[i])==string("-v") )  || ( string(argv[i])==string("--version") ) )
      {
	cout<<"La version du programme est 2.0"<<endl;
      }
      
      if( ( string(argv[i])==string("-a") )  || ( string(argv[i])==string("--auteur") ))
	{
	  cout<<"Les auteurs sont : Alex, Abdellah, Anas et Smaail."<<endl;
	}

      if( ( string(argv[i])==string("-h") ) || ( string(argv[i])==string("--help") ))
	{
	  opts.print();
	}
      
      
      if (opts.optionHasArgument(argv[i])) {
	cout << " Elle attend un argument de type "
	     << Type2String(opts.optionArgumentType(argv[i]));
	cout << " => " << (++i < argc ?
			   string(argv[i])=="-a"? "Erreur" : string(argv[i])=="-v"? "Erreur" : string(argv[i])=="-h"? "Erreur" : argv[i] : "Erreur");
	if(i<argc)
	  if( (string(argv[i])!="-a") || (string(argv[i])!="-v") || (string(argv[i])!="-h"))
	    nom=argv[i]; // C'est ici que je le récupère
	
      }
      cout << endl; 
    } else {
      opt_error = true;
    }
  }
  if (opt_error) {
    cout << "Usage : " << argv[0] << " [Options]" << endl;
    cout << "--help pour l'aide !"<<endl;
    return 1;
  }

  return 0;
}

