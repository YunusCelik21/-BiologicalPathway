// Name: Yunus Dildar Çelik
// ID: 22203347
// Section: 01

#include "BiologicalPathway.h"
#include <iostream>
#include <string>
using namespace std;

BiologicalPathway::BiologicalPathway() : pathways(nullptr), proteins(nullptr), genes(nullptr) {}

BiologicalPathway::~BiologicalPathway() {
	if (pathways)
		delete pathways;
	if (proteins)
		delete proteins;
	if (genes)
		delete genes;
}

void BiologicalPathway::addPathway(const int pathwayId, const string pathwayName) {
	if (!pathways) {
		
	}
	else {

	}
}

void BiologicalPathway::removePathway(const int pathwayId) {
}

void BiologicalPathway::printPathways() const
{
}

void BiologicalPathway::addProtein(const int proteinId, const int pathwayId) {
	if (!proteins) {

	}
	else {

	}
}

void BiologicalPathway::removeProtein(const int proteinId, const int pathwayId)
{
}

void BiologicalPathway::printProteinsInPathway(const int pathwayId) const {
	
}

void BiologicalPathway::addGene(const int geneID, const string geneName, const int proteinId) {
	if (!genes) {

	}
	else {

	}
}

void BiologicalPathway::removeGene(const int geneID, const int proteinId) {

}

void BiologicalPathway::printGenesOfProtein(const int proteinId) const {
	
}
