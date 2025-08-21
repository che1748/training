
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
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
	
	// Check if the parameters are stored properly	
    	for (int i = 0; i < SIZE; i++) {
        	cout << ", Timestep: " << fixed << setprecision(6) << timestep[i]
             	     << ", NumSteps: " << setprecision(0) << numsteps[i] << endl;
    	}
	
	// Write the solutions to output.dat
	ofstream outfile("/home/yuxinc3/training/data/output.dat");
	if (!outfile) {
		cerr << "error opening file!" << endl;
	}
	
	// This for loop goes through the different time steps.
	for (int i=0; i<SIZE; i++) {
		int size = static_cast<int>(numsteps[i]) + 1;
		vector<double> x(size);
		vector<double> y(size);
		double step = timestep[i];
		x[0] = 0;
		y[0] = 1;

		int index = 1;
		// This while loop uses euler method for each time step.
		while (index < size) {
			y[index] = (1 - 3*step)*y[index-1];
			x[index] = x[index-1] + step;
			index++;
		}
		outfile << left << setw(5) << "x" + to_string(i+1) + "  ";
		// This for loop prints all the x data to a row.	
		for (double xi : x) {
			outfile << left << setw(20) << xi;
		}

		outfile << endl;

		outfile << left << setw(5) << "y" + to_string(i+1) + "  ";
		// This for loop prints all the y data to a row.
		for (double yi : y) {
			outfile << left << setw(20) << yi;
		}

		outfile << endl;
	
	}
	outfile.close();
	return 0;
}

