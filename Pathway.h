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
	string name;
	ListNode<Protein>* proteins;

public:
	Pathway(int ID, string name);
	~Pathway();

	void print() const;
	int getID() const;
	string getName() const;
	ListNode<Protein>* getProteins();
	bool operator<(const Pathway& Pathway) const;
	int getGenes() const;
};

#endif 
