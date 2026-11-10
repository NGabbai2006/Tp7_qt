#include "pile_entier.h"
#include <iostream>
using namespace std;
#include "qDebug.h"

pile_entier::pile_entier(int nb) {
	pile = new int[nb];
	taille = nb;
	hauteur = 0;
}
// constructeur, taille de la pile, 20 par defaut, initialise la hauteur à 0 alloue dynamiquement de la place mémoire

pile_entier::~pile_entier() {
	delete[] pile;
}// destructeur-libère la pile

void pile_entier::empile(int nb) {
	if (pile_entier::pleine() == 1) {
		return;
	}
	pile[hauteur] = nb;
	hauteur++;
} // ajoute un élement à la pile

int pile_entier::depile() {
	if (pile_entier::vide() == 1) {
		return 1;
	}
	int nb = pile[hauteur-1];
	hauteur--;
	return nb;
}// retourne la valeur de l’entier inséré en dernier, la hauteur diminue de 1 unité


int pile_entier::pleine() {
	if (taille == hauteur) {
		return 1;
	}
	else {
		return 0;
	}

}// retourne 1 si la pile est pleine, 0 sinon

int pile_entier::vide() {
	if (hauteur==0) {
		return 1;
	}
	else
	{
		return 0;
	}
}// retourne 1 si la pile est vide, 0 sinon

int pile_entier::recupHauteur() {
	return hauteur;
}
int pile_entier::recupTaille() {
	return taille;
}