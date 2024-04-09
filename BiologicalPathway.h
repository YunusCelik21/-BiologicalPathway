// Name: Yunus Dildar Çelik
// ID: 22203347
// Section: 01

#ifndef BIOLOGICAL_PATHWAY_H
#define BIOLOGICAL_PATHWAY_H
using namespace std;

class BiologicalPathway {
private:

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
