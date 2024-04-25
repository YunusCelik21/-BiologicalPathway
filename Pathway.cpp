// Name: Yunus Dildar Çelik
// ID: 22203347
// Section: 01

#include "Pathway.h"

Pathway::Pathway(int ID, string name) : ID(ID), name(name), proteins(nullptr) {}

Pathway::~Pathway() {
    if (proteins)
        delete proteins;
}

void Pathway::print() const {
    cout << "Pathway " << ID << " : " << name << " (" << size(proteins) << " Proteins) (" << getGeneCount() << " Genes)" << endl;
}

int Pathway::getID() const {
    return ID;
}

string Pathway::getName() const {
    return name;
}

ListNode<Protein>*& Pathway::getProteins() {
    return proteins;
}

int Pathway::getGeneCount() const {
    int sum = 0;
    ListNode<Protein>* protein = proteins;

    while (protein) {
        sum += size(protein->value->getGenes());
        protein = protein->next;
    }

    return sum;
}

bool Pathway::addProtein(Protein& protein) {
    if (contains(proteins, protein)) 
        // TODO: print error message
        return false;
    

    // TODO: print error message
    addValue(proteins, protein);
    return true;
}

bool Pathway::removeProtein(const Protein& protein) {
    if (!contains(proteins, protein)) {
        std::cout << "Cannot remove protein. Pathway " << ID << " does not have a protein with ID " << protein.getID() << "." << std::endl;
        return false;
    }
    
    std::cout << "Removed protein " << protein.getID() << " from pathway " << ID << "." << std::endl;
    removeValue(proteins, protein);
    return true;
}

bool Pathway::operator<(const Pathway& pathway) const {
    return this->ID < pathway.ID;
}

bool Pathway::operator==(const Pathway& pathway) const {
    return this->ID == pathway.ID;
}