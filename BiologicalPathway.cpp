// Name: Yunus Dildar Çelik
// ID: 22203347
// Section: 01

#include "BiologicalPathway.h"
#include <iostream>
#include <string>
using namespace std;
#define print(x) cout << x << endl

BiologicalPathway::BiologicalPathway() : pathways(nullptr) {}

BiologicalPathway::~BiologicalPathway() {
	if (pathways)
		delete pathways;
}

void BiologicalPathway::addPathway(const int pathwayId, const string pathwayName) {
	Pathway* pathway = new Pathway(pathwayId, pathwayName);

	if (contains(pathways, *pathway)) {
		print("Cannot add pathway. There is already a pathway with ID " << pathwayId << ".");
		delete pathway;
	}
	else {
		addValue(pathways, *pathway);
		print("Added pathway " << pathwayId << ".");
	}
}

void BiologicalPathway::removePathway(const int pathwayId) {
	Pathway pathway(pathwayId, "");

	if (removeValue(pathways, pathway)) 
		print("Removed pathway " << pathwayId << ".");
	else
		print("Cannot remove pathway. There is no pathway with ID " << pathwayId << ".");
}

void BiologicalPathway::printPathways() const {
	if (!pathways)
		print("There are no pathways to show.");
	else {
		print("Pathways in the system:");
		printList(pathways);
	}
}

void BiologicalPathway::addProtein(const int proteinId, const int pathwayId) {
	Pathway pathway(pathwayId, "");
	Protein* protein = new Protein(proteinId);

	if (!contains(pathways, pathway)) {
		print("Cannot add protein. There is no pathway with ID " << pathwayId << ".");
		delete protein;
	}
	else {
		ListNode<Pathway>* head = pathways;
		bool exists = false;

		while (head) {
			if (contains(head->value->getProteins(), *protein))
				exists = true;
			head = head->next;
		}

		if (exists) {
			print("Cannot add protein. There is a pathway having a protein with ID " << proteinId << ".");
			delete protein;
		}
		else {
			head = pathways;

			while (head) {
				if (*(head->value) == pathway) {
					head->value->addProtein(*protein);
					print("Added protein " << proteinId << " to pathway " << pathwayId << ".");
				}
				head = head->next;
			}
		}
	}
}

void BiologicalPathway::removeProtein(const int proteinId, const int pathwayId) {
	Pathway pathway(pathwayId, "");
	Protein protein(proteinId);

	if (!contains(pathways, pathway))
		print("Cannot remove protein. There is no pathway with ID " << pathwayId << ".");
	else {
		ListNode<Pathway>* head = pathways;

		while (head) {
			if (*(head->value) == pathway) 
				head->value->removeProtein(protein);
			head = head->next;
		}
	}
}

void BiologicalPathway::printProteinsInPathway(const int pathwayId) const {
	Pathway pathway(pathwayId, "");

	if (!contains(pathways, pathway))
		print("Cannot print proteins. There is no pathway with ID " << pathwayId << ".");
	else {
		ListNode<Pathway>* head = pathways;

		while (head) {
			if (*(head->value) == pathway)
				if (head->value->getProteins()) {
					print("Proteins in pathway " << pathwayId << ":");
					printList(head->value->getProteins());
				}
				else
					print("There are no proteins to show in pathway " << pathwayId << ".");
			head = head->next;
		}
	}
}

void BiologicalPathway::addGene(const int geneID, const string geneName, const int proteinId) {
	Gene* gene = new Gene(geneID, geneName);
	Protein protein(proteinId);
	Protein* requiredProtein = nullptr;

	ListNode<Pathway>* headPathway = pathways;
	bool geneExist = false;

	while (headPathway) {
		ListNode<Protein>* headProtein = headPathway->value->getProteins();

		while (headProtein) {
			if (contains(headProtein->value->getGenes(), *gene))
				geneExist = true;

			if (*(headProtein->value) == protein)
				requiredProtein = headProtein->value;

			headProtein = headProtein->next;
		}
		
		headPathway = headPathway->next;
	}

	if (geneExist) {
		print("Cannot add gene. Gene " << geneID << " is already in use.");
		delete gene;
	}
	else if (!requiredProtein) {
		print("Cannot add gene. There is no protein with ID " << proteinId << ".");
		delete gene;
	}
	else {
		requiredProtein->addGene(*gene);
		print("Added gene " << geneID << " to protein " << proteinId << ".");
	}
}

void BiologicalPathway::removeGene(const int geneID, const int proteinId) {
	Protein protein(proteinId);
	Gene gene(geneID, "");
	Protein* requiredProtein = nullptr;
	ListNode<Pathway>* headPathway = pathways;

	while (headPathway) {
		if (contains(headPathway->value->getProteins(), protein)) {
			ListNode<Protein>* headProtein = headPathway->value->getProteins();

			while (headProtein) {
				if (*(headProtein->value) == protein)
					requiredProtein = headProtein->value;
				headProtein = headProtein->next;
			}
		}

		headPathway = headPathway->next;
	}

	if (!requiredProtein)
		print("Cannot remove gene. There is no protein with ID " << proteinId << ".");
	else 	
		requiredProtein->removeGene(gene);

}

void BiologicalPathway::printGenesOfProtein(const int proteinId) const {
	ListNode<Pathway>* headPathway = pathways;
	Protein protein(proteinId);
	Protein* requiredProtein = nullptr;

	while (headPathway) {
		if (contains(headPathway->value->getProteins(), protein)) {
			ListNode<Protein>* headProtein = headPathway->value->getProteins();

			while (headProtein) {
				if (*(headProtein->value) == protein)
					requiredProtein = headProtein->value;
				headProtein = headProtein->next;
			}
		}

		headPathway = headPathway->next;
	}

	if (!requiredProtein)
		print("Cannot print genes. There is no protein with ID " << proteinId << ".");
	else {
		if (!requiredProtein->getGenes())
			print("There are no genes to show in protein " << proteinId << ".");
		else {
			print("Genes in protein " << proteinId << ":");
			printList(requiredProtein->getGenes());
		}
	}

}