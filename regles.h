#ifndef REGLES_H
#define REGLES_H

class Regles{
private:
    int largGrille,
        hautGrille;
    
    
public:
    // constructeur / destructeurs
    Regles(int largGrille, int hautGrille);
    Regles();
  
    
    int getLarg();
    int getHaut();
    
    
    void setRegles(int largGrille, int hautGrille);//changer les regles
    
	bool testerRegles();
    
};


#endif
