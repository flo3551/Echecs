#include "Piece.h"
#include "Tour.h"
#include "Echiquier.h"
#include <iostream>

Tour::Tour() { }

Tour::Tour(bool white, bool left) : Piece((left ? 1 : 8), (white ? 1 : 8), white) { }

bool
Tour::mouvementValide(Echiquier &e, int x, int y)
{
	bool mouvValide = false;
	bool maPiece = false;
	int i = 0;

	//vérifier si pièce sur chemin et sur case arrivée
	if ((x == m_x && y >= 1 && y <= 8) || (y == m_y && x >= 1 && x <= 8))
	{
		if (m_x < x)    //déplacement vers droite
		{
			for (i = m_x+1; i <= x; i++) // jusqu'à la case cible
			{
				if (e.getPiece(i, y) != NULL) //vérifie si pièce présente sur le chemin
				{
					if (e.getPiece(i, y)->isWhite()){
						maPiece = true;
						cout << "la tour ne peut pas sauter de pièce" << endl;
					}
					if (i == x && e.getPiece(i, y)->isWhite() != m_white)   //Si pièce adverse
					{
						e.enleverPiece(x, y);
						cout << "mouvementValide de Fou : droite" << endl;
						mouvValide = true;
					}
				}
				else //pas de pièce 
				{
					if (i == x && mouvValide == false && maPiece == false)
					{
						cout << "mouvementValide de Fou : droite" << endl;
						mouvValide = true;
					}
				}
			}
		}
		else
		{
			if (m_x > x)    //déplacement vers gauche
			{
				for (i = m_x-1; i >= x; i--)// du fou vers cible (vers gauche donc décrémente)
				{
					if (e.getPiece(i, y) != NULL) //si pièce présente sur le chemin
					{
						if (e.getPiece(i, y)->isWhite()){
							maPiece = true;
							cout << "la tour ne peut pas sauter de pièce" << endl;
						}
						if (i == x && e.getPiece(i, y)->isWhite() != m_white)   //Si pièce adverse
						{
							e.enleverPiece(x, y);
							cout << "mouvementValide de Fou : gauche" << endl;
							mouvValide = true;
						}
					}
					else{
						if (i == x && mouvValide == false && maPiece == false)//pas de piece
						{
							cout << "mouvementValide de Fou : gauche" << endl;
							mouvValide = true;

						}
					}
				}
			}
			else{
				if (m_y < y)    //déplacement vers bas
				{
					for (i = m_y+1; i <= y; i++)
					{
						if (e.getPiece(x, i) != NULL)//si piece présente sur le chemin
						{
							if (e.getPiece(x,i)->isWhite()){
								maPiece = true;
								cout << "la tour ne peut pas sauter de pièce" << endl;
							}
							if(i == y && e.getPiece(x, i)->isWhite() != m_white)   //Si pièce adverse
							{
								e.enleverPiece(x, y);
								cout << "mouvementValide de Fou : bas" << endl;
								mouvValide = true;
							}
						}
						else{
							if (i == y && mouvValide == false && maPiece == false) //pas de pièce
							{
								cout << "mouvementValide de Fou : bas" << endl;
								mouvValide = true;
							}
						}
					}
				}
				else{ //vers le haut
					for (i = m_y; i >= y; i--)
					{
						if (e.getPiece(x, i) != NULL)
						{
							if (e.getPiece(x, i)->isWhite()){
								maPiece = true;
								cout << "la tour ne peut pas sauter de pièce" << endl;
							}
							if (i == y && e.getPiece(x, i)->isWhite() != m_white)   //Si pièce adverse
							{
								e.enleverPiece(x, y);
								cout << "mouvementValide de Fou : haut" << endl;
								mouvValide = true;
							}
						}
						else{
							if (i == y && mouvValide == false && maPiece == false)
							{
								cout << "mouvementValide de Fou : haut" << endl;
								mouvValide = true;
							}
						}
					}
				}
			}
		}
	}
	return mouvValide;
}

char
Tour::type()
{
	return m_white ? 'T' : 't';
}