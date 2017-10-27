#if !defined Tour_h
#define Tour_h
#include "Piece.h"
using namespace std;

class Tour : virtual public Piece
{
public:
	Tour();
	Tour(bool white, bool left);
	bool mouvementValide(Echiquier &e, int x, int y);
	char type();
};
#endif 