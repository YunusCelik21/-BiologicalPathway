// Name: Yunus Dildar Çelik
// ID: 22203347
// Section: 01

#include "Protein.h"

Protein::Protein(int ID) : ID(ID), genes(nullptr) {}

Protein::~Protein() {
    if (genes)
        delete genes;
}

void Protein::print() const {
    cout << "Protein ID : " << ID << ", Gene IDs : " << getIDsAsArray() << endl;
}

int Protein::getID() const {
    return ID;
}

ListNode<Gene>*& Protein::getGenes() {
    return genes;
}

string Protein::getIDsAsArray() const {
    if (!genes)
        return "None";

    string s = "[";
    ListNode<Gene>* gene = genes;

    while (gene->next) {
        s += to_string(gene->value->getID());
        s += ", ";
        gene = gene->next;
    }

    s += to_string(gene->value->getID());
    s += "]";

    return s;
}

bool Protein::addGene(Gene& gene) {
    if (contains(genes, gene)) 
        // TODO: print error msg
        return false;
    
    // TODO: print succsess msg
    addValue(genes, gene);
    return true;
}

bool Protein::removeGene(const Gene& gene) {
    if (!contains(genes, gene)) {
        std::cout << "Cannot remove gene. There is no gene " << gene.getID() << " encoding protein " << ID << "." << std::endl;
        return false;
    }
  
    removeValue(genes, gene);
    std::cout << "Removed gene " << gene.getID() << " from protein " << ID << "." << std::endl;
    return true;
}

bool Protein::operator<(const Protein& protein) const {
    return this->ID < protein.ID;
}

bool Protein::operator==(const Protein& protein) const {
    return this->ID == protein.ID;
}