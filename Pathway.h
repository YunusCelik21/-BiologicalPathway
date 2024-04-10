// Name: Yunus Dildar Çelik
// ID: 22203347
// Section: 01

#ifndef _PATHWAY_H
#define _PATHWAY_H
#include <string>
#include "Protein.h"
using namespace std;

class Pathway {
private:
	int ID;
	// ListNode<Protein>* proteins;
	int size;

public:
	Pathway();
	Pathway(int ID);

	int getID() const;
	// ListNode<Gene>* getProteins();
	int getSize() const;
};

#endif 
