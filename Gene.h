// Name: Yunus Dildar Çelik
// ID: 22203347
// Section: 01

#ifndef _GENE_H
#define _GENE_H
#include <string>
using namespace std;

class Gene {
private:
	int ID;
	string name;

public:
	Gene(int ID, string name);

	void print() const;
	int getID() const;
	string getName() const;
	bool operator<(const Gene& gene) const;
	bool operator==(const Gene& gene) const;
};

#endif 


