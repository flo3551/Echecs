#include "Piece.h"
#include "Reine.h"
#include <iostream>

Reine::Reine(bool white) : Piece(4, (white ? 1 : 8), white) { }


bool
Reine::mouvementValide(Echiquier &e, int x, int y)
{
	bool mouvValide = false;
	if (Tour::mouvementValide(e, x, y) || Fou::mouvementValide(e, x, y)){
		cout << "mouvementValide de Reine" << endl;
		mouvValide = true;
	}
	
	return mouvValide;
}

char
Reine::type()
{
	return m_white ? 'Q' : 'q';
} 