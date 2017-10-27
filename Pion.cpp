#include "Piece.h"
#include "Pion.h"
#include "Echiquier.h"
#include <iostream>

Pion::Pion(int x, bool white) : Piece(x, (white ? 2 : 7), white) { }

bool
Pion::mouvementValide(Echiquier &e, int x, int y)
{
	bool mouvValide = false;
	if ((m_y == 2 && m_white) || (m_y == 7 && !m_white))
	{
		//pion avance d'1 ou 2 case ou diagonale si pièce adverse
		if ((x == m_x && y == m_y + 2 && m_white) || (x == m_x && y == m_y - 2 && !m_white)) //cas avancer de 2 cases
		{
			if (m_white && e.getPiece(m_x, m_y + 1) == NULL && e.getPiece(m_x, m_y + 2) == NULL)
			{
				cout << "mouvementValide de Pion" << endl; 
				mouvValide = true;
			}
			else
			{
				if (!m_white && e.getPiece(m_x, m_y - 1) == NULL && e.getPiece(m_x, m_y - 2) == NULL)
				{
					cout << "mouvementValide de Pion" << endl; 
					mouvValide = true;
				}
			}
		}
		else
		{
			if ((x == m_x && y == m_y + 1 && m_white) || (x == m_x && y == m_y - 1 && !m_white))    //on avance d'1 case
			{
				if (e.getPiece(x, y) == NULL)
				{
					cout << "mouvementValide de Pion" << endl;
					mouvValide = true;
				}
			}
			else{ //manger pièce adverse
				if ((1 == abs(x - m_x) && y == m_y + 1 && m_white) || (1 == abs(x - m_x) && y == m_y - 1 && !m_white))
				{
					if (e.getPiece(x, y) != NULL && e.getPiece(x, y)->isWhite() != m_white)
					{
						e.enleverPiece(x, y);
						cout << "mouvementValide de Pion" << endl;
						mouvValide = true;
					}
				}
			}
		}
	}
	else
	{
		if ((x == m_x && y == m_y + 1 && m_white) || (x == m_x && y == m_y - 1 && !m_white))
		{
			if (e.getPiece(x, y) == NULL)
			{
				cout << "mouvementValide de Pion" << endl;
				mouvValide = true;
			}
		}
		else{
			if ((1 == abs(x - m_x) && y == m_y + 1 && m_white) || (1 == abs(x - m_x) && y == m_y - 1 && !m_white))
			{
				if (e.getPiece(x, y) != NULL && e.getPiece(x, y)->isWhite() != m_white)
				{
					e.enleverPiece(x, y);
					cout << "mouvementValide de Pion" << endl;
					mouvValide = true;
				}
			}
		}
	}
	return mouvValide;
}

char
Pion::type()
{
	return m_white ? 'P' : 'p';
}
