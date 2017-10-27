#if !defined Fou_h
#define Fou_h
 
#include "Piece.h"
using namespace std;

class Fou : virtual public Piece
{
public:
	Fou();
	Fou(bool white, bool left);
	bool mouvementValide(Echiquier &e, int x, int y);
	char type();
};

#endif