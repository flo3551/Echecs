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

	//v�rifier si pi�ce sur chemin et sur case arriv�e
	if ((x == m_x && y >= 1 && y <= 8) || (y == m_y && x >= 1 && x <= 8))
	{
		if (m_x < x)    //d�placement vers droite
		{
			for (i = m_x+1; i <= x; i++) // jusqu'� la case cible
			{
				if (e.getPiece(i, y) != NULL) //v�rifie si pi�ce pr�sente sur le chemin
				{
					if (e.getPiece(i, y)->isWhite()){
						maPiece = true;
						cout << "la tour ne peut pas sauter de pi�ce" << endl;
					}
					if (i == x && e.getPiece(i, y)->isWhite() != m_white)   //Si pi�ce adverse
					{
						e.enleverPiece(x, y);
						cout << "mouvementValide de Fou : droite" << endl;
						mouvValide = true;
					}
				}
				else //pas de pi�ce 
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
			if (m_x > x)    //d�placement vers gauche
			{
				for (i = m_x-1; i >= x; i--)// du fou vers cible (vers gauche donc d�cr�mente)
				{
					if (e.getPiece(i, y) != NULL) //si pi�ce pr�sente sur le chemin
					{
						if (e.getPiece(i, y)->isWhite()){
							maPiece = true;
							cout << "la tour ne peut pas sauter de pi�ce" << endl;
						}
						if (i == x && e.getPiece(i, y)->isWhite() != m_white)   //Si pi�ce adverse
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
				if (m_y < y)    //d�placement vers bas
				{
					for (i = m_y+1; i <= y; i++)
					{
						if (e.getPiece(x, i) != NULL)//si piece pr�sente sur le chemin
						{
							if (e.getPiece(x,i)->isWhite()){
								maPiece = true;
								cout << "la tour ne peut pas sauter de pi�ce" << endl;
							}
							if(i == y && e.getPiece(x, i)->isWhite() != m_white)   //Si pi�ce adverse
							{
								e.enleverPiece(x, y);
								cout << "mouvementValide de Fou : bas" << endl;
								mouvValide = true;
							}
						}
						else{
							if (i == y && mouvValide == false && maPiece == false) //pas de pi�ce
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
								cout << "la tour ne peut pas sauter de pi�ce" << endl;
							}
							if (i == y && e.getPiece(x, i)->isWhite() != m_white)   //Si pi�ce adverse
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