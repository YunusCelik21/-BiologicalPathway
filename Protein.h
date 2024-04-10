// Name: Yunus Dildar Çelik
// ID: 22203347
// Section: 01

#ifndef _PROTEIN_H
#define _PROTEIN_H
#include <string>
#include "Gene.h"
using namespace std;

class Protein {
private:
	int ID;
	// ListNode<Gene>* genes;
	int size;

public:
	Protein();
	Protein(int ID);

	int getID() const;
	// ListNode<Gene>* getGenes();
	int getSize() const;
};

#endif 
