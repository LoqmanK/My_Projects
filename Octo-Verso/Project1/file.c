#include <assert.h>
#pragma once
#include "file.h"
#include "vecteur.h"
void initFile(File* f, int n) {
	initVecteur(f, n);
}
int estVide(const File* f) {
	return (taille(f) == 0);
}
int entrer(File* f,ItemF it) {
	return ajouter(f, it);
}
ItemF sortir(File* f) {
	ItemF tmp = obtenir(f,0);
	supprimer(f, 0);
	return tmp;
}
ItemF premier(File* f) {
	return obtenir(f, 0);
}
void detruireFile(File* f) {
	detruireVecteur(f);
}
ItemF obtenirF(const File* f, int i) {
	return obtenir(f, i);
}
void modifierF(File* v, int i, ItemF it) {
	modifier(v, i, it);
}

void testFile() {
	const int MAX = 10;
	File f;
	initFile(&f, 2);
	assert(estVide(&f));
	for (int i = 0; i < MAX; ++i) {
		entrer(&f, i);
		assert(!estVide(&f));
		assert(premier(&f) == 0);
	}
	for (int i = 0; i < MAX; ++i) {
		assert(!estVide(&f));
		assert(premier(&f) == i);
		int v = sortir(&f);
		assert(v == i);
	}
	assert(estVide(&f));
	detruireFile(&f);
}
