#if !defined Joueur_h
#define Joueur_h

#include "Piece.h"
#include "Pion.h"
#include "Fou.h"
#include "Tour.h"
#include "Reine.h"
#include "Roi.h"
#include "Cavalier.h"
#include "Echiquier.h"
 
class Joueur
{
private:
	Piece *m_pieces[16];

public:
	Joueur(bool white);
	Joueur();
	~Joueur();

	void init(bool white);
	void affiche();
	bool placerPieces(Echiquier & e);
};


#endif // !defined Joueur_h
