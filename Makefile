#Pour éviter des problèmes si on a un fichier du meme nom
.PHONY: clean, mrproper

#Desactivation des règles implicite à make
.SUFFIXES:


# Définition des variables (-lncurse est ecrit sur le sujet)
CC= g++
FLAGS= -Wall -lncurses -g



all : case.o chargerNavirePerso.o grille.o jeu.o joueur.o main.o navire.o tableau-case.o window.o
	g++ case.o chargerNavirePerso.o grille.o jeu.o joueur.o main.o navire.o tableau-case.o window.o -o Programme $(FLAGS)
 
main.o : main.cpp jeu.cpp joueur.cpp window.cpp navire.cpp case.cpp grille.cpp chargerNavirePerso.cpp tableau-case.cpp
	g++ -c main.cpp -o main.o
 
case.o : case.cpp window.cpp
	g++ -c case.cpp -o case.o

chargerNavirePerso.o : chargerNavirePerso.cpp navire.cpp
	g++ -c chargerNavirePerso.cpp -o chargerNavirePerso.o

grille.o : grille.cpp tableau-case.cpp navire.cpp window.cpp
	g++ -c grille.cpp -o grille.o

jeu.o : jeu.cpp joueur.cpp window.cpp navire.cpp case.cpp grille.cpp
	g++ -c jeu.cpp -o jeu.o

joueur.o : joueur.cpp window.cpp grille.cpp
	g++ -c joueur.cpp -o joueur.o

navire.o : navire.cpp case.cpp window.cpp
	g++ -c navire.cpp -o navire.o

tableau-case.o : tableau-case.cpp case.cpp
	g++ -c tableau-case.cpp -o tableau-case.o

window.o : window.cpp
	g++ -c window.cpp -o window.o









clean:
	rm -rf *.o

mrproper: clean
	rm -rf Programme

