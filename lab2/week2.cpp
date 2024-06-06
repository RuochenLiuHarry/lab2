
#include<iostream>

using  namespace std;

namespace CST8219{
class Vehicle{
private:
		int numWheels;
		int numDoors;

public:
	Vehicle(int w, int d): numWheels(w), numDoors(d){
	cout << "In constructor with 2 parameters" << endl;
	}
	Vehicle(int w): Vehicle(w,4){
	cout << "In constructor with 1 parameters, wheels = " << w << endl;
	}
	Vehicle() : Vehicle(4) {
	cout << "In constructor with 0 parameters" << endl;
	}

	~Vehicle() {
		cout << "In destructor" << endl;
	}

	};

};

int main(int argc, char **argv)
{
	CST8219::Vehicle veh1;
	CST8219::Vehicle veh2(4);
	CST8219::Vehicle veh3(4,2);

	cout << "Vehicle veh1 takes " << sizeof(veh1) << " bytes." << endl;
	cout << "Vehicle veh2 takes " << sizeof(veh2) << " bytes." << endl;
	cout << "Vehicle veh3 takes " << sizeof(veh3) << " bytes." << endl;
	
	CST8219::Vehicle* pVehicle;
	int d, w;
	char userInput = ' ';

	do {

		cout << "Enter number of doors: ";
		cin >> d;
		cout << "Enter number of wheels: ";
		cin >> w;

		if (d > 0 && w > 0) {
			pVehicle = new CST8219::Vehicle(w, d);
		}
		else {
			cout << "Invalid. Please enter numbers greater than 0." << endl;
			continue;
		}

		cout << "enter 'q' to quit or create a new vehicle: ";
		cin >> userInput;
		if (userInput != 'q') {
			delete pVehicle;
		}

	} while (userInput != 'q');

	delete pVehicle;


	return 0;


}