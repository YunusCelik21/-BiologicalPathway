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
	Gene();
	Gene(int ID, string name);

	int getID() const;
	string getName() const;
};

#endif 


