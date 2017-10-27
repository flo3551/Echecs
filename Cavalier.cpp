#include "Piece.h"
#include "Cavalier.h"
#include "Echiquier.h"
#include <iostream>
 

Cavalier::Cavalier(bool white, bool left) : Piece((left ? 2 : 7), (white ? 1 : 8), white) { }

bool
Cavalier::mouvementValide(Echiquier &e, int x, int y) 
{
	bool mouvValide = false;

	//vérifier case d'arrivée dispo
	if ((abs(x - m_x) == 2 && abs(y - m_y) == 1) || (abs(x - m_x) == 1 && abs(y - m_y) == 2))
	{
		if (e.getPiece(x, y) != NULL)//si pièce présente
		{
			if (e.getPiece(x, y)->isWhite() != m_white)//pièce adverse
			{
				e.enleverPiece(x, y);
				cout << "mouvementValide de Cavalier" << endl;
				mouvValide = true;
			}
		}
		else{
			//pas de pièce
			cout << "mouvementValide de Cavalier" << endl;
			mouvValide = true;
		}
	}
	return mouvValide;
	
}

char
Cavalier::type()
{
	return m_white ? 'C' : 'c';
}
