#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
using namespace std;

void initialisation(){
  ifstream test("score.txt");
  if(!test.is_open()){
    ofstream fichier("score.txt");
    if(!fichier.is_open())
      {
	cout<<"Le fichier n'a pas pu s'ouvrir."<<endl;
	return;
      }
    for(int i=0; i<5; i++) {
      fichier<<"Aucun : 0"<<endl;
    }
  }
}


void recupNom(string *T){
  istringstream isstream;
  ifstream fichier("score.txt");
  string str;
  for(int i=0; i<5; i++)
    {
      getline(fichier, str);
      string word;
      
      isstream.str(str);
      getline(isstream, word, ' '); // Mot 1 : le nom du joueur (il se trouve avant le caractère ' ' (espace))
      T[i]=word;
    }
}

void convertTabStringInt(string *T, int *tab) {
  for(int i=0; i<5; i++){
    tab[i]=atoi(T[i].c_str());
  }
}

void recupScore(string *T){

  ifstream fichier("score.txt");
  for(int i=0; i<5; i++)
    {
      string str;
      istringstream isstream;
      getline(fichier, str);
      string word;
      isstream.str(str);
      getline(isstream, word, ' '); // Mot 1 avant les 2 points
      getline(isstream, word, ' '); // Mot 2 les 2 points
      getline(isstream, word); // Mot 3 le score
      T[i]=word;
    }
}


string convertirInt(int nombre){
  stringstream nbString;
  nbString<<nombre;
  return nbString.str();
}

void tabScoreIntToString(int *tInt, string *tString) {
  for(int i=0; i<5; i++) {
    tString[i]=convertirInt(tInt[i]);
      }
}

void tabTrie(int *T, string *TabNom, int nb, string name) {
  int i=0;
  while(T[i]>nb && i<5)
    {
      i++;
    }
  if(i==5)
    return;

  int old=T[i];
  string oldName=TabNom[i];
  
  T[i]=nb;
  TabNom[i]=name;
  
  i++;
  int newValue;
  string newName;
  for(int k=i; k<5; k++)
    {
      newValue=T[k];
      T[k]=old;
      old=newValue;
      
      newName=TabNom[k];
      TabNom[k]=oldName;
      oldName=newName;
    }
}

void ajouterScore(int nb, string name) {
  //Tableau de Nom (celui du joueur) et tableaux de score
  string tabScoreString[5];
  string tabName[5];
  int tabScoreInt[5];
  
  recupScore(tabScoreString);
  recupNom(tabName);
  convertTabStringInt(tabScoreString, tabScoreInt);

  
  tabTrie(tabScoreInt, tabName, nb, name);
  tabScoreIntToString(tabScoreInt, tabScoreString);
      
  string ligne;
  ofstream reecriture ("score.txt", ofstream::trunc);
  for(int g=0; g<5; g++)
    {
      string chaine;
      chaine+=tabName[g];
      chaine+=" : ";
      chaine+=tabScoreString[g];
      chaine+='\n';
      reecriture.write(chaine.c_str(), chaine.size());
    }
  
}



 


int main(){
  initialisation(); //  Test si le fichier score existe déja, sinon on le crée
  ajouterScore(2330, "Unknow"); 
  ajouterScore(3200, "Montpellier");
  
return 0;
}
