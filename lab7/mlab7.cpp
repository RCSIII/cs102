// Robert Schenck
// Mini-Lab 7
#include <iostream>

using namespace std;

int CardNumber(int userInput){
	int card = userInput % 13;
	return card;
}

string CardSuit(double userInput){
	string suit;
	double number = userInput / 13.00;
	if(number < 1){
		suit = "Hearts";
	}else if(number >= 1 && number < 2){
		suit = "Diamonds";
	}else if(number >= 2 && number < 3){
		suit = "Spades";
	}else if(number >= 3 && number < 4){
		suit = "Clubs";
	}
			
	return suit;
}

int main(){

	string deck[13] = {	"2", "3", "4" , "5", "6" ,"7" ,"8" ,"9", "10", "J", "Q", "K", "A"};
	double userInput;

	cout << "Enter a card index: ";
	cin >> userInput;
	cout << "That's the " << deck[CardNumber(userInput)] << " of " << CardSuit(userInput) << '\n';

	return 0;
}
