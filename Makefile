#Pour éviter des problèmes si on a un fichier du meme nom
.PHONY: clean, mrproper

#Desactivation des règles implicite à make
.SUFFIXES:


# Définition des variables (-lncurse est ecrit sur le sujet)
CC= g++
FLAGS= -Wall -lncurse










clean:
	rm -rf *.o

mrproper: clean
	rm -rf Programme

