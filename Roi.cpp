#include "Piece.h"
#include "Roi.h"
#include "Echiquier.h"
#include <iostream>

Roi::Roi(bool white) : Piece(5, (white ? 1 : 8), white) { }

bool
Roi::mouvementValide(Echiquier &e, int x, int y)
{
	bool mouvValide = false;
	if ((abs(x - m_x) <= 1) && (abs(y - m_y) <= 1))
	{
		//Piece présente à l'arrivee ?
		if (e.getPiece(x,y) != NULL)
		{
			if (e.getPiece(x, y)->isWhite() != m_white) //Si piece couleur adverse
			{
				e.enleverPiece(x, y);
				cout << "mouvementValide de Roi" << endl;
				mouvValide = true;
			}
		}
		else
		{
			cout << "mouvementValide de Roi" << endl;
			mouvValide = true;
		}
	}
	return mouvValide;
}

char 
Roi::type()
{
	return m_white ? 'R' : 'r';
}