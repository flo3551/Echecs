/**
* Programme test de Piece
*
* @file testPiece.cxx
*/

// Utile pour l'affichage
#include <iostream>
#include <assert.h>
#include "Piece.h"
#include "JoueurBlanc.h"
#include "JoueurNoir.h"
#include "Echiquier.h"
#include "Déroulement.h"


// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;


/**
* Programme principal
*/
int main(int argc, char** argv)
{
	/*
	JoueurNoir jn;
	JoueurBlanc jb;

	Echiquier e;
	e.affiche(); 

	bool piecesOK;
	piecesOK = jn.placerPieces(e);
	assert(piecesOK);
	piecesOK = jb.placerPieces(e);
	assert(piecesOK);
	*/
	

	//Pion p4(1, true);
	//assert(!e.placer(&p4));
	
	//Piece *p_empty = NULL;
	//assert(!e.placer(p_empty));

	//Piece *p_bad = new Pion(10, true);
	//assert(!e.placer(p_bad));
	//delete p_bad;
	//e.affiche();

	//e.enleverPiece(1, 8);
	//assert(!e.enleverPiece(10, 8));
	//assert(!e.enleverPiece(1, 8));
	
	//e.affiche();

	//jn.affiche();
	//jb.affiche();

	Déroulement d;
	d.déroulement();
	return 0;
}
