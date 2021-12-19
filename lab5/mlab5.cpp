// Robert Schenck
// Mini-lab 5

#include <iostream>
#include <string>

using namespace std;

int main(){

	// Variable initialization
	int seed;
	const int ARRAY_LENGTH = 25;
	int array[ARRAY_LENGTH];
	int arraySum = 0;

	// User inputted seed
	cout << "Enter a  seed: ";
	cin >> seed;

	// Seeding the RNG
	srand(seed);

	// Filling the array with numbers ranging from -10, 10
	for(int i = 0; i < ARRAY_LENGTH; i++){
		array[i] = rand() % 21 + (-10);
	}
	// Calculating the sum of the array
	for(int j = 0; j < ARRAY_LENGTH; j++){
		arraySum += array[j];
	}
	// Outputs the sum of the array
	cout << "Sum of array = " << arraySum << '\n';

	return 0;
}
