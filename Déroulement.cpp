#include "Déroulement.h"
#include "Piece.h"

#include "Pion.h"
#include "Fou.h"
#include "Tour.h"
#include "Reine.h"
#include "Roi.h"
#include "Cavalier.h"
 
#include "Joueur.h"
#include "JoueurBlanc.h"
#include "JoueurNoir.h"
#include "Echiquier.h"
#include <iostream>
#include <string>

using namespace std;

Déroulement::Déroulement()
{
	cout << "Constructeur defaut" << endl;
}


Déroulement::~Déroulement()
{
	cout << "Destructeur" << endl;
}

void Déroulement::checkCoordonnées(){
	bool coorValide = false;
	while (coorValide == false){
		cout << "\nX = ";
		cin >> x;
		cout << "\nY = ";
		cin >> y;

		if ((x >= 1) && (x <= 8) && (y >= 1) && (y <= 8))
		{
			coorValide = true;
		}
		else
		{
			cout << "\nCoordonnées hors du jeu. Saisissez des valeurs entre 1 et 8 inclues.";
		}
	}

}

void
Déroulement::samePosition(int xDeb, int yDeb, int xCible, int yCible){
	bool posDiff = false;
	while (posDiff == false){
		if ((xDeb != xCible && yDeb != yCible) || (xDeb == xCible && yDeb != yCible) || (xDeb != xCible && yDeb == yCible)){
			posDiff = true;
		}else{
			cout << "\nVous ne pouvez pas déplacer votre pièce sur elle-même, choisissez des coordonnées valides pour la case cible de votre pièce.";
			cout << "\nX = ";
			cin >> x;
			cout << "\nY = ";
			cin >> y;

			xCible = this->x;
			yCible = this->y;
		}
	}
	
}

void Déroulement::déroulement(){
	JoueurBlanc jb = JoueurBlanc();
	JoueurNoir jn = JoueurNoir();
	Echiquier e = Echiquier();
	leJoueur = true;
	bool mouvValide = false;
	int echec = 0;

	bool finJeu = false;
	int xDep;
	int yDep;
	int xCible;
	int yCible;

	char typePiece;

	jb.affiche();
	jn.affiche();

	jb.placerPieces(e);
	jn.placerPieces(e);

	e.affiche();


	/**CREATION PIECES**/
	Roi rb(true);                 //ROIS
	Roi rn(false);
	Reine qb(true);               //REINES
	Reine qn(false);
	Tour tb1(true, true);         //TOURS
	Tour tn1(false, true);
	Tour tb2(true, false);
	Tour tn2(false, false);
	Fou fb1(true, true);          //FOUS
	Fou fn1(false, true);
	Fou fb2(true, false);
	Fou fn2(false, false);
	Cavalier cb1(true, true);     //CAVALIERS
	Cavalier cn1(false, true);
	Cavalier cb2(true, false);
	Cavalier cn2(false, false);
	Pion pb1(1, true);            //PIONS
	Pion pn1(1, false);
	Pion pb2(2, true);
	Pion pn2(2, false);
	Pion pb3(3, true);
	Pion pn3(3, false);
	Pion pb4(4, true);
	Pion pn4(4, false);
	Pion pb5(5, true);
	Pion pn5(5, false);
	Pion pb6(6, true);
	Pion pn6(6, false);
	Pion pb7(7, true);
	Pion pn7(7, false);
	Pion pb8(8, true);
	Pion pn8(8, false);

	/**PLACEMENT PIECES**/
	e.enleverPiece(5, 1);  //ROIS
	e.placer(&rb);
	e.enleverPiece(5, 8);
	e.placer(&rn);
	e.enleverPiece(4, 1);  //REINES
	e.placer(&qb);
	e.enleverPiece(4, 8);
	e.placer(&qn);
	e.enleverPiece(1, 1);  //TOURS
	e.placer(&tb1);
	e.enleverPiece(1, 8);
	e.placer(&tn1);
	e.enleverPiece(8, 1);
	e.placer(&tb2);
	e.enleverPiece(8, 8);
	e.placer(&tn2);
	e.enleverPiece(3, 1);  //FOUS
	e.placer(&fb1);
	e.enleverPiece(3, 8);
	e.placer(&fn1);
	e.enleverPiece(6, 1);
	e.placer(&fb2);
	e.enleverPiece(6, 8);
	e.placer(&fn2);
	e.enleverPiece(2, 1);  //CAVALIERS
	e.placer(&cb1);
	e.enleverPiece(2, 8);
	e.placer(&cn1);
	e.enleverPiece(7, 1);
	e.placer(&cb2);
	e.enleverPiece(7, 8);
	e.placer(&cn2);
	e.enleverPiece(1, 2);  //PIONS
	e.placer(&pb1);
	e.enleverPiece(1, 7);
	e.placer(&pn1);
	e.enleverPiece(2, 2);
	e.placer(&pb2);
	e.enleverPiece(2, 7);
	e.placer(&pn2);
	e.enleverPiece(3, 2);
	e.placer(&pb3);
	e.enleverPiece(3, 7);
	e.placer(&pn3);
	e.enleverPiece(4, 2);
	e.placer(&pb4);
	e.enleverPiece(4, 7);
	e.placer(&pn4);
	e.enleverPiece(5, 2);
	e.placer(&pb5);
	e.enleverPiece(5, 7);
	e.placer(&pn5);
	e.enleverPiece(6, 2);
	e.placer(&pb6);
	e.enleverPiece(6, 7);
	e.placer(&pn6);
	e.enleverPiece(7, 2);
	e.placer(&pb7);
	e.enleverPiece(7, 7);
	e.placer(&pn7);
	e.enleverPiece(8, 2);
	e.placer(&pb8);
	e.enleverPiece(8, 7);
	e.placer(&pn8);

	

	while (finJeu == false){
		bool mouvValide = false;

		e.affiche();
		if (leJoueur){
			cout << "\nAu tour du joueur blanc." << endl << "Choisissez les coordonnees de la piece a deplacer.";
		}
		else{
			cout << "\nAu tour du joueur noir." << endl << "Choisissez les coordonnees de la piece a deplacer.";
		}

		this->checkCoordonnées();
		xDep = this->x;
		yDep = this->y;
		cout << xDep;
		cout << yDep;
		
		if (e.getPiece(xDep, yDep) != NULL) //si la pièce existe
		{
			if ((leJoueur && e.getPiece(xDep, yDep)->isWhite()) || (!leJoueur && e.getPiece(xDep, yDep)->isBlack())) //si la pièce existante est de la couleur du joueur
			{
				
				
				while (!mouvValide){
					cout << "\nChoisissez les coordonnees de la case cible de votre pièce : ";
					this->checkCoordonnées();
					cout << x;
					cout << y;
					samePosition(xDep, yDep, this->x, this->y);//vérifier qu'on déplace pas la pièce sur la même case
					if (e.getPiece(xDep, yDep)->mouvementValide(e, x, y)) //on vérifie si le mouvement est possible
					{
						//ECHEC ?
						e.deplacer(e.getPiece(xDep, yDep), x, y);
						mouvValide = true;
					}
					else{
						cout << "mouvInvalide" << endl;
					}
				}
			}
		}

		e.affiche();


		leJoueur = !leJoueur;
		//finJeu = true;

	}

}