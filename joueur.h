
#ifndef JOUEUR_H
#define JOUEUR_H

class Joueur{
private:
    char nom[32];
    int bateauxCoules, score, identifiant; //nbr de bateau perdus, et score = nombre de parties gagnées par le joueur

public:
    //constructeurs / destructeurs
 
    Joueur(char *nom, int identifiant);// on met batcoul et score a 0
    ~Joueur();
    //accesseurs en lecture
    char* getNom()const;
    int getScore ()const;
    int getCoules()const;
    int getId()const;
    
    //accesseur en écriture
    
    void setNom(char* nouvNom);
    void setCoules0();
    void addCoules();
    void addScore();
    void setScore0();
    
    
};








#endif
