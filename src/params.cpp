//This code generate a .dat file that includes time steps and
//the number of steps for solving the ODE dx/dt = -3x.

# include <iostream>
# include <cmath>  // required for pow()
# include <iomanip> // required for setw()
# include <fstream> // for file operations.
# define end '\n'
using namespace std;

int main() {
	double tstep[7];
	double numofsteps[7];
	// print paramters to the screen
	for (int i = 0; i < 7; i++) {
		tstep[i] = pow(10, -i);
		numofsteps[i] = 9/tstep[i];
		cout << left << setw(10) << "Element " + to_string(i) + ": " << fixed << setprecision(6) << setw(12) <<tstep[i] << right << setw(10) << "steps: " << setprecision(0) << numofsteps[i] << end;	
	}
	
	// write parameters to params.dat
	ofstream outfile("params.dat");

	if (!outfile) {
		cerr << "Error opening file!" << end;
		return 1;
	}
	
	// write headers
	outfile << left << setw(15) << "Timestep"
		<< setw(15) << "NumSteps" << end;

	// write data
	for (int i=0; i<7; i++) {
		outfile << left << setw(15) << fixed << setprecision(6) << tstep[i]
			<< setw(15) << numofsteps[i] << end;
	}
	outfile.close();
	return 0;

	
}

