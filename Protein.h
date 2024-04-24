// Name: Yunus Dildar Çelik
// ID: 22203347
// Section: 01

#ifndef _PROTEIN_H
#define _PROTEIN_H
#include <string>
#include "Gene.h"
#include "ListNode.h"
using namespace std;

class Protein {
private:
	int ID;
	ListNode<Gene>* genes;

public:
	Protein(int ID);
	~Protein();

	void print() const;
	int getID() const;
	ListNode<Gene>* getGenes() const;
	string getIDsAsArray() const;
	bool addGene(Gene& gene);
	bool removeGene(const Gene& gene);
	bool operator<(const Protein& protein) const;
	bool operator==(const Protein& protein) const;
};

#endif 
