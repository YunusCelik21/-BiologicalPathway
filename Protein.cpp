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

ListNode<Gene>* Protein::getGenes() const {
    return genes;
}

string Protein::getIDsAsArray() const {
    if (!genes)
        return "None";

    string s = "[";
    ListNode<Gene>* gene = genes;

    while (gene->next) {
        s += gene->value.getID();
        s += ", ";
        gene = gene->next;
    }

    s += gene->value.getID();
    s += "]";

    return s;
}

bool Protein::operator<(const Protein& protein) const {
    return this->ID < protein.ID;
}

bool Protein::operator==(const Protein& protein) const {
    return this->ID == protein.ID;
}

