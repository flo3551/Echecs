#if !defined Déroulement_h
#define Déroulement_h

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

class Déroulement
{
	protected:
		Echiquier e;
		JoueurBlanc jb;
		JoueurNoir jn;
		bool leJoueur;
		int x;
		int y;

	public:
		Déroulement();
		~Déroulement();
		void déroulement();
		void checkCoordonnées();
		void samePosition(int xDeb, int yDeb, int xCible, int yCible);
};

#endif