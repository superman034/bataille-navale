#Pour éviter des problèmes si on a un fichier du meme nom
.PHONY: clean, mrproper

#Desactivation des règles implicite à make
.SUFFIXES:


# Définition des variables (-lncurse est ecrit sur le sujet)
CC= g++
FLAGS= -Wall -lncurses -g

all : case.o chargerNavirePerso.o grille.o jeu.o joueur.o main.o navire.o tableau-case.o window.o option.o tableau-option.o score.o logs.o
	g++ case.o chargerNavirePerso.o grille.o jeu.o joueur.o main.o navire.o tableau-case.o window.o option.o tableau-option.o score.o logs.o -o BatailleNavale $(FLAGS)
 
main.o : main.cpp
	g++ -c main.cpp -o main.o
 
case.o : case.cpp
	g++ -c case.cpp -o case.o

chargerNavirePerso.o : chargerNavirePerso.cpp 
	g++ -c chargerNavirePerso.cpp -o chargerNavirePerso.o

grille.o : grille.cpp
	g++ -c grille.cpp -o grille.o

jeu.o : jeu.cpp
	g++ -c jeu.cpp -o jeu.o

joueur.o : joueur.cpp
	g++ -c joueur.cpp -o joueur.o

navire.o : navire.cpp
	g++ -c navire.cpp -o navire.o

tableau-case.o : tableau-case.cpp
	g++ -c tableau-case.cpp -o tableau-case.o

window.o : window.cpp
	g++ -c window.cpp -o window.o

option.o : option.cpp
	g++ -c option.cpp -o option.o

tableau-option.o : tableau-option.cpp
	g++ -c tableau-option.cpp -o tableau-option.o

score.o : score.cpp
	g++ -c score.cpp -o score.o

logs.o : logs.cpp
	g++ -c logs.cpp -o logs.o

clean:
	rm -rf *.o

mrproper: clean
	rm -rf BatailleNavale
