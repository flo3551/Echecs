#if !defined Pion_h
#define Pion_h

#include "Piece.h"
using namespace std;


class Pion : public Piece
{
public:
	Pion(int x, bool white);
	bool mouvementValide(Echiquier &e, int x, int y);
	char type();
};
#endif 