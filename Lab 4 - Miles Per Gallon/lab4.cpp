// Robert Schenck
// Lab 4

#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main(){
	
	// Variable Declarations and Initializations
	string response;
	double carMiles = 0;
	double carGallons = 0;
	double truckMiles = 0;
	double truckGallons = 0;
	double totalCarMiles;
	double totalCarGallons;
	double totalTruckMiles;
	double totalTruckGallons;
	int numTrucks = 0;
	int numCars = 0;

	// Cycles through while user wants to add vehicles to their fleet
	while(response != "done"){
		cout << "Enter command: ";
		cin >> response;

		// Checks to see if user gave a valid response, if not goes back to the top of while loop
		if(response != "truck" && response != "car" && response != "done"){
			cout << "Unknown Command.\n";
			continue;
		}
		
		// If user entered car, ask for the car's miles and how many gallons. Adds these numbers to the running total
		// Increments number of cars in the fleet
		if(response == "car"){
			cout << "Enter car's miles: ";
			cin >> carMiles;
			while(!cin){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout << "Enter car's miles: ";
				cin >> carMiles;
			}
			totalCarMiles += carMiles;

			cout << "Enter car's gallons: ";
			cin >> carGallons;
			while(!cin){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout << "Enter car's gallons: ";
				cin >> carGallons;
			}
			totalCarGallons += carGallons;

			numCars++;
		}

		// If the user entered truck, ask for the truck's miles and how many allons. Adds these numbers to the running total
		// Increments number of trucks in the fleet
		if(response == "truck"){
			cout << "Enter truck's miles: ";
			cin >> truckMiles;
			while(!cin){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout << "Enter truck's miles: ";
				cin >> truckMiles;
			}
			totalTruckMiles += truckMiles;

			cout << "Enter car's gallons: ";
			cin >> truckGallons;
			while(!cin){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout << "Enter truck's gallons: ";
				cin >> truckGallons;
			}
			totalTruckGallons += truckGallons;

			numTrucks++;
		}
	}

	// Calculates the average MPG of the cars and trucks.
	// Outputs that there were no cars and/or trucks if there were no cars and/or trucks 
	if(numCars == 0){
		cout << "Fleet has no cars.\n";
	}else{
		cout << "Average car MPG: " << totalCarMiles / totalCarGallons << '\n';
	}
	if(numTrucks == 0){
		cout << "Fleet has no trucks.\n";
	}else{
		cout << "Average truck MPG: " << totalTruckMiles / totalTruckGallons << '\n';
	}

	return 0;

}


