// Robert Schenck
// Lab 7
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// Constant array's that store the card's value and suit, and a constant int for size of the deck
const string SUITS[] = {"H", "D", "S", "C"};
const string CARD_VALUES[] = {"A","2","3","4", "5", "6", "7", "8","9", "10", "J", "Q", "K"};
const int NUM_CARDS = 52;
const int CARDS_TO_DEAL = 3;

// Function prototypes
int GetRandom(int min, int max);
string DealCard(int (&cards)[NUM_CARDS], int &player);
int ScoreHand(int (&cards)[NUM_CARDS], int &player);

// Main function
int main(){
	
	// Declaration of cards array and number of players
	int numPlayers;
	int cards[NUM_CARDS] = {0};
	int i;

	// Gets the number of players from the user and doesn't allow any non-integer input or any number greater than the number
	// of cards divided by the amount of cards being dealt (ex: 52 / 2 = 26, numPlayers <= 26)
	for(;;){
		cout << "How many players? ";
		cin >> numPlayers;
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}else if(numPlayers > NUM_CARDS / CARDS_TO_DEAL){
			cout << "There is not enough cards for that many people.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}else{
			break;
		}
	}
	
	// Deal each player 2 cards and scores them until there are no players left
	for(i = 1; i < numPlayers + 1; i++){
		cout << "Player " << i << " has cards: ";
		cout << setw(5) << left <<  DealCard(cards, i) << DealCard(cards, i);
		cout << setw(3) << right << "(" << ScoreHand(cards, i) << ")" << '\n';
	}
}

// Takes a random number and returns a number that is inbetween them
int GetRandom(int min, int max){
	int randomNum;
	if(min != 0){
		randomNum = (rand() % max) + min;
	}else{
		randomNum = rand() % max;
	}

	return randomNum;
}

// Deals cards to players
string DealCard(int (&cards)[NUM_CARDS], int &player){
	int cardValuesIndex;
	int suitIndex;
	int randomIndex = GetRandom(0, 52);
	
	// Makes sure duplicate cards are not dealt
	while(true){
		if(cards[randomIndex] == 0){
			cards[randomIndex] = player;
			break;
		}else{
			// If the card is a duplicate the program gets a new random number from the GetRandom function
			randomIndex = GetRandom(0, 52);
		}
	}

	// Creates a card from the indexes of the value and suit arrays and returns it 
	string playerCard = CARD_VALUES[randomIndex % 13] + SUITS[randomIndex / 13];		
	return playerCard;

}

// Scores each players hand
int ScoreHand(int (&cards)[NUM_CARDS], int &player){
	
	int j = 0;
	int score = 0;

	// Loops through the cards array determining if the card belongs to that specific player
	for(j = 0; j < NUM_CARDS; j++){
		if(cards[j] == player){
			// If the index of the cards array mod 13 is above 10 (J or Q) or 0 (K), then the value of that card is 10
			if((j + 1) % 13 > 10 || (j + 1) % 13 == 0){
				score += 10;
			}else{
			// If the index of the cards array mod 13 is 10 or below, then the value of that card is the index mod 13
				score += (j % 13) + 1;
			}
		}
	}
	return score;

}

