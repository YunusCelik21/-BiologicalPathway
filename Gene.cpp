// Name: Yunus Dildar Çelik
// ID: 22203347
// Section: 01

#include "Gene.h"
#include <iostream>

Gene::Gene(int ID, string name) : ID(ID), name(name) {}

void Gene::print() const {
    cout << "GENE " << ID << " : " << name << endl;
}

int Gene::getID() const {
    return ID;
}

string Gene::getName() const {
    return name;
}

bool Gene::operator<(const Gene& gene) const {
    return this->ID < gene.ID;
}
