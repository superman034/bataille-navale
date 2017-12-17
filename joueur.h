
#ifndef JOUEUR_H
#define JOUEUR_H



#include <string>

class Joueur{
private:
    std::string nom;//
    size_t bateauxCoules, score, identifiant; //nbr de bateau perdus, et score = nombre de parties gagnées par le joueur
	bool ia;//pour savoir si le joueur est une IA ou pas
	//Grille grille;

public:
    //constructeurs / destructeurs
 
    Joueur(std::string nom, size_t identifiant,bool ia);// on met batcoul et score a 0
    Joueur();
    ~Joueur();
    //accesseurs en lecture
    std::string getNom()const;
    size_t getScore ()const;
    size_t getCoules()const;
    size_t getId()const;
    bool getIA()const;
    //Grille getGrille();
    
    //accesseur en écriture
    
    void setNom(std::string nouvNom);
    void setCoules0();
    void addCoules();
    void addScore();
    void setScore0();
    void setIA();
    void setId(size_t id);
    //void setGrille(Grille grille);
  
    
    
};








#endif
