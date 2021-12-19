// Robert Schenck
// Lab 5

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main(){

	// Variable declarations and initilizations
	int seed;
	int balance = 1000;
	int winning;
	int smallestWinning = 0;
	int largestWinning = 0;
	int smallestWager = 1001;
	int largestWager = 0;
	int wager;
	int reel[3];
	vector<int> wagers;
	vector<int> winnings;

	// User seeds the number generator
	for(;;){
		cout << "Enter a seed: ";
		cin >> seed;
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
		}else{
			break;
		}
	}
	srand(seed);
	cout << '\n';

	while(true){

		// If the balance is less than or equal to 0 then break
		if(balance > 0){

			// Shows user their balance and ask how much they want to wager
			cout << "Your money: $" << balance << '\n';
			for(;;){
				cout << "Place a bet: $";
				cin >> wager;
				if(cin.fail()){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(),'\n');
				}else if(wager > balance){
					cout << "You don't have that much money.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(),'\n');
				}else{
					break;
				}
			}
			balance -= wager;

			// Adds the wager to the wagers vectors and determines the largest and smallest wagers
			wagers.push_back(wager);
			if(wager > largestWager){
				largestWager = wager;
			}
			if(wager < smallestWager && wager > 0){
				smallestWager = wager;
			}
			// Fills the reel with random numbers inbetween 7 and 2 if wager > 0, breaks otherwise
			if(wager > 0){
				for(int i = 0; i < 3; i++){
					reel[i] = rand() % 6 + 2;
					cout << reel[i] << " ";
				}
				cout << '\n';
			}else{
				break;
			}

			// Compares the reel to see if they all match, 2 match, or none match at all and then
			// calculates the winnings and adds to balance.
			if(reel[0] == reel[1] && reel[0] == reel[2] && reel[1] == reel[2]){
				if(reel[0] == 7){
					winning = wager * 10;
					balance += winning;
					cout << "You won $" << winning << "!\n";
					cout << '\n';
				}else{
					winning = wager * 5;
					balance += winning;
					cout << "Yon won $" << winning << "!\n";
					cout << '\n';
				}
			}else if(reel[0] == reel[1] || reel[1] == reel[2] || reel[0] == reel[2]){
				winning = wager * 2;
				balance += winning;
				cout << "You won $" << winning << "!\n";
				cout << '\n';
			}else if(reel[0] != reel[1] && reel[0] != reel[2] && reel[1] != reel[2]){
					cout << "You didn't win.\n";
					cout << '\n';
					winning = 0;
			}
			
			// Determines the largest and smallest winnings. Adds winnings to winnings vector.
			winnings.push_back(winning);
			if(winning > largestWinning){
				largestWinning = winning;
			}else if(winning < smallestWinning && winning > 0){
				smallestWinning = winning;
			}

			

		// If player runs out of money
		}else{
			cout << '\n';
			cout << "You ran out of money!\n";
			break;
		}
	}

	// Prints statistics for the game
	cout << '\n';
	for(int j = 0; j < winnings.size(); j++){
		cout << "You wagered $" << wagers.at(j) << " and won $" << winnings.at(j) << ".\n";
	}
	if(wagers.at(0) != 0){
		cout << '\n';
		cout << "Your smallest wager was $" << smallestWager << ".\n";
		cout << "Your largest wager was $" << largestWager << ".\n";
		cout << "Your smallest winnings was $" << smallestWinning << ".\n";
		cout << "Your largest winnings was $" << largestWinning << ".\n";
	}else{
		cout << '\n';
		cout << "You walked away without playing.\n";
	}
	
	return 0;
}



