#if !defined Cavalier_h
#define Cavalier_h

#include "Piece.h"
using namespace std;
 

class Cavalier : public Piece
{
public:
	Cavalier(bool white, bool left);
	bool mouvementValide(Echiquier &e, int x, int y);
	char type();
};
#endif