#include "Piece.h"
#include "Fou.h"
#include "Echiquier.h"
#include <iostream>

 

Fou::Fou() { }

Fou::Fou(bool white, bool left) : Piece((left ? 3 : 6), (white ? 1 : 8), white) { }

bool
Fou::mouvementValide(Echiquier &e, int x, int y)
{
	//r�cup�ration position de d�part
	int xCaseDepart = this->x();
	int yCaseDepart = this->y();
	bool isWhite = this->isWhite();
	bool mouvValide = false;
	bool maPiece = true;
	int ecartX = x - xCaseDepart;
	int ecartY = y - yCaseDepart;

	//v�rifier si pi�ce sur chemin et case arriv�e
	if (ecartX == ecartY || ecartX == -ecartY)   //aller en diagonale
	{
		if (ecartX > 0 && ecartY < 0)    //en haut � droite
		{
			while (xCaseDepart != x && yCaseDepart != y) 
			{
				xCaseDepart++;
				yCaseDepart--;

				if (e.getPiece(xCaseDepart, yCaseDepart) != NULL)//si pi�ce pr�sente
				{
					if (xCaseDepart == x && yCaseDepart == y && e.getPiece(x, y)->isWhite() != isWhite)   //Si pi�ce adverse
					{
						e.enleverPiece(x, y);
						cout << "mouvementValide du Fou : Haut Droite" << endl;
						mouvValide = true;
					}
					if (e.getPiece(xCaseDepart, yCaseDepart)->isWhite()){ //si pi�ce � nous alors on bloque
						maPiece = false;
						cout << "le fou ne peut pas sauter de pi�ce" << endl;

					}
				}
				else
				{
					if (xCaseDepart == x && yCaseDepart == y && mouvValide == false )
					{
						cout << "mouvementValide du Fou : Haut Droite" << endl;
						mouvValide = true;
					}
				}
			}
		}
		else{
			if (ecartX < 0 && ecartY > 0)    //bas � gauche
			{
				while (xCaseDepart != x && yCaseDepart != y && maPiece == true)
				{
					xCaseDepart--;
					yCaseDepart++;
					if (e.getPiece(yCaseDepart, yCaseDepart) != NULL)
					{
						if (xCaseDepart == x && yCaseDepart == y && e.getPiece(x, y)->isWhite() != isWhite)   //Si pi�ce adverse 
						{
							e.enleverPiece(x, y); 
							cout << "mouvementValide du Fou : Bas Gauche" << endl;
							mouvValide = true;
						}
						if (e.getPiece(yCaseDepart, yCaseDepart)->isWhite()){ //si pi�ce � nous alors on bloque
							maPiece = false;
							cout << "le fou ne peut pas sauter de pi�ce" << endl;
						
						}
					}
					else
					{
						if (xCaseDepart == x && yCaseDepart == y && mouvValide == false)
						{
							cout << "mouvementValide du Fou : Bas Gauche" << endl;
							mouvValide = true;
						}
					}
				}
			}
			else{
				if (ecartX < 0 || ecartY < 0)    //haut gauche
				{
					while (xCaseDepart != x || yCaseDepart != y)
					{
						xCaseDepart--;
						yCaseDepart--;
						if (e.getPiece(xCaseDepart, yCaseDepart) != NULL)
						{
							if (xCaseDepart == x && yCaseDepart == y && e.getPiece(x, y)->isWhite() != isWhite)   //Si pi�ce adverse
							{
								e.enleverPiece(x, y);
								cout << "mouvementValide du Fou : Haut Gauche" << endl;
								mouvValide = true;
							}
							if (e.getPiece(yCaseDepart, yCaseDepart)->isWhite()){ //si pi�ce � nous alors on bloque
								maPiece = false;
								cout << "le fou ne peut pas sauter de pi�ce" << endl;

							}
						}
						else
						{
							if (xCaseDepart == x && yCaseDepart == y && mouvValide == false)
							{
								cout << "mouvementValide du Fou : Haut Gauche" << endl;
								mouvValide = true;
							}
						}
					}
				}
				else {//bas droite
					while (xCaseDepart != x && yCaseDepart != y)
					{
						xCaseDepart++;
						yCaseDepart++;
						if (e.getPiece(xCaseDepart, yCaseDepart) != NULL)
						{
							if (xCaseDepart == x && yCaseDepart == y && e.getPiece(x, y)->isWhite() != isWhite)   //Si pi�ce couleur adverse
							{
								e.enleverPiece(x, y);
								cout << "mouvementValide du Fou : Bas Droite" << endl;
								mouvValide = true;
							}
							if (e.getPiece(yCaseDepart, yCaseDepart)->isWhite()){ //si pi�ce � nous alors on bloque
								maPiece = false;
								cout << "le fou ne peut pas sauter de pi�ce" << endl;
							}
						}
						else
						{
							if (xCaseDepart == x && yCaseDepart == y && mouvValide == false)
							{
								cout << "mouvementValide du Fou : Bas Droite" << endl;
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
Fou::type()
{
	return m_white ? 'F' : 'f';
}
