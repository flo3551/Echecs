#if !defined Roi_h
#define Roi_h

#include "Piece.h"
using namespace std;


class Roi : public Piece
{
public:
	Roi(bool white);
	bool mouvementValide(Echiquier &e, int x, int y);
	char type();
};
#endif 