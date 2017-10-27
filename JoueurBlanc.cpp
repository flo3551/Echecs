
#include "JoueurBlanc.h"
#include <iostream>

JoueurBlanc::JoueurBlanc() {
	init(true);
}

JoueurBlanc::~JoueurBlanc()
{
	cout << "Destruction de joueur blanc " << endl;
} 

bool
JoueurBlanc::isWhite()
{
	return true;
}

bool
JoueurBlanc::isBlack()
{
	return false;
}