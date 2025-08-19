
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main () {
	const int SIZE = 7;
	double timestep[SIZE];
	double numsteps[SIZE];

	// Read the parameters from params.dat and store them in arrays.
	ifstream infile("params.dat");

	if (!infile) {
		cerr << "Error opening file!" << endl;
		return 1;
	}

	string header;
	getline(infile, header); // Skip the header
	
	for (int i = 0; i < SIZE; i++) {
		infile >> timestep[i] >> numsteps[i];
	}

	infile.close();
	
    	for (int i = 0; i < SIZE; i++) {
        cout << ", Timestep: " << fixed << setprecision(6) << timestep[i]
             << ", NumSteps: " << setprecision(0) << numsteps[i] << endl;
    	}

	return 0;
}

