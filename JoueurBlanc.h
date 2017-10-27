#if !defined JoueurBlanc_h
#define JoueurBlanc_h

#include "Joueur.h"
using namespace std;


class JoueurBlanc : public Joueur {
public:
	JoueurBlanc();
	~JoueurBlanc();

	bool isWhite();
	bool isBlack();
};
#endif 