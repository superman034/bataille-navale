#Pour éviter des problèmes si on a un fichier du meme nom
.PHONY: clean, mrproper

#Desactivation des règles implicite à make
.SUFFIXES:


# Définition des variables
CC= g++
FLAGS= -Wall










clean:
	rm -rf *.o

mrproper: clean
	rm -rf Bibou
