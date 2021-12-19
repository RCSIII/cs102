#include <iostream>
#include <string>

using namespace std;

int main(){
	
	string bankAction;
	double balance;
	double deposit;
	double withdrawal;
	cout << "How much money do you have in your bank account? ";
	cin >> balance;

	while(true){

		cout << "Would you like to deposit, withdrawal, print your balance, or quit. ";
		cin >> bankAction;

		if(bankAction == "deposit"){
			
			cout << "How much? ";
			cin >> deposit;
			balance += deposit;
		}
		else if(bankAction == "withdrawal"){

			cout << "How much? ";
			cin >> withdrawal;
			balance -= withdrawal;
		}
		else if(bankAction == "balance"){

			cout << "Your balance is $" << balance << '\n';
		}
		else if(bankAction == "quit"){
			break;
		}
		else{
			cerr << "Invalid Input";
		}

	}
	
	return 0;
}
