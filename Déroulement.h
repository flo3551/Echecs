#if !defined D�roulement_h
#define D�roulement_h

#include "Piece.h"

#include "Pion.h"
#include "Fou.h"
#include "Tour.h"
#include "Reine.h"
#include "Roi.h"
#include "Cavalier.h"

#include "Echiquier.h"
#include "Joueur.h"
#include "JoueurBlanc.h"
#include "JoueurNoir.h"
#include <string>

using namespace std;

class D�roulement
{
	protected:
		Echiquier e;
		JoueurBlanc jb;
		JoueurNoir jn;
		bool leJoueur;
		int x;
		int y;

	public:
		D�roulement();
		~D�roulement();
		void d�roulement();
		void checkCoordonn�es();
		void samePosition(int xDeb, int yDeb, int xCible, int yCible);
};

#endif