// Name: Yunus Dildar Çelik
// ID: 22203347
// Section: 01

#ifndef _BIOLOGICAL_PATHWAY_H
#define _BIOLOGICAL_PATHWAY_H
#include <string>
#include "ListNode.h"
#include "Pathway.h"
using namespace std;

class BiologicalPathway {
private:
	ListNode<Pathway>* pathways;
	ListNode<Protein>* proteins;
	ListNode<Gene>* genes;

public:
	BiologicalPathway();
	~BiologicalPathway();
	
	void addPathway(const int pathwayId, const string pathwayName);
	void removePathway(const int pathwayId);
	void printPathways() const;
	
	void addProtein(const int proteinId, const int pathwayId);
	void removeProtein(const int proteinId, const int pathwayId);
	void printProteinsInPathway(const int pathwayId) const;
	
	void addGene(const int geneID, const string geneName, const int proteinId);
	void removeGene(const int geneID, const int proteinId);
	void printGenesOfProtein(const int proteinId) const;
};

#endif
