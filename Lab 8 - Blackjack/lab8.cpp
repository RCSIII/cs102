// Robert Schenck
// Lab8
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <sstream>
#include <ctime>
using namespace std;

//Constant array's that store the card's value and suit, and a constant int for the size of the deck
const string SUITS[] = {"H", "D", "S", "C"};
const string CARD_VALUES[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
const int NUM_CARDS = 52;
const int CARDS_TO_DEAL = 2;

// Function prototypes
int GetRandom(int min, int max);
string DealCard(int (&cards)[NUM_CARDS], int &player);
int ScoreHand(int (&cards)[NUM_CARDS], int &player);
void IntializeCardDeck(int (&cards)[NUM_CARDS]);

// Main Function
int main(){

	// Seeding RNG
	srand(time(NULL));

	// Declaration of cards array and string streams
	int cards[NUM_CARDS];
	string hitOrStand = "";
	stringstream dealersCards;
	stringstream dealersCardsSwap;
	stringstream playersCards;
	stringstream playersCardsSwap;
	int dealer = 3;
	int player = 2;
	IntializeCardDeck(cards);

	// Stores the players cards in a string strema
	dealersCards << setw(5) << left << DealCard(cards, dealer) << DealCard(cards, dealer);
	playersCards << "You have cards  : " << setw(5) << left << DealCard(cards, player) << DealCard(cards, player);
	
	// Prints out the cards that each player starts with
	cout << "Dealer has cards: " << dealersCards.str();
	cout << setw(3) << right << "(" << ScoreHand(cards, dealer) << ")" << '\n';
	cout << playersCards.str();
	cout << setw(3) << right << "(" << ScoreHand(cards, player) << ")" << '\n';

	while(true){
		// Ask the user to hit or stand and error checks the input
		cout << "Hit or Stand    ? ";
		cin >> hitOrStand;
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}else if(hitOrStand != "hit" || hitOrStand != "stand"){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
		// If user stands, then break out of the while loop
		if(hitOrStand == "stand"){
			cout << '\n';
			break;
		}

		// If user hits, then deal another card
		if(hitOrStand == "hit"){
			cout << '\n';
			cout << "Dealer has cards: " << dealersCards.str();
			cout << setw(3) << right << "(" << ScoreHand(cards, dealer) << ")" << '\n';
			playersCardsSwap << playersCards.str() << "   " << DealCard(cards, player);
			playersCards.str("");
			playersCards << playersCardsSwap.str();
			playersCardsSwap.str("");
			cout << playersCards.str();
			cout << setw(3) << right << "(" << ScoreHand(cards, player) << ")" << '\n';
		}

		// Determines if the player wins/busts
		if(ScoreHand(cards, player) > 21){
			cout << "Player busts, dealer wins!" << '\n';
			return 0;
		}else if(ScoreHand(cards, player) == 21){
			cout << "Player wins!" << '\n';
			return 0;
		}else if(ScoreHand(cards, player) < 21){
			continue;
		}
	}

	while(true){
		// If ScoreHands returns a value less than 18 for the dealer, then the dealer hits
		if(ScoreHand(cards, dealer) < 18){
			dealersCardsSwap << dealersCards.str() << "   " << DealCard(cards, dealer);
			dealersCards.str("");
			dealersCards << dealersCardsSwap.str();
			dealersCardsSwap.str("");
			cout << "Dealer hits     : " << dealersCards.str();
			cout << setw(3) << right << "(" << ScoreHand(cards, dealer) << ")" << '\n';
		// If ScoreHands returns a value that is equal to or greater than 18, the dealer stands
		}else{
			cout << "Dealer stands   : " << dealersCards.str();
			cout << setw(3) << right << "(" << ScoreHand(cards, dealer) << ")" << '\n';
			cout << '\n';
			break;
		}

		// Determines if the dealers wins/busts
		if(ScoreHand(cards, dealer) > 21){
			cout << "Dealer busts, player wins!" << '\n';
			return 0;
		}else if(ScoreHand(cards, dealer) == 21){
			cout << "Dealer wins!" << '\n';
			return 0;
		}
	}

	while(true){
		// Determines who wins after each player has stood and prints out the cards that they finish with
		cout << "Dealer has cards: " << dealersCards.str();
		cout << setw(3) << right << "(" << ScoreHand(cards, dealer) << ")" << '\n';
		cout << playersCards.str();
		cout << setw(3) << right << "(" << ScoreHand(cards, player) << ")" << '\n';
		// If the player cards have more value than the player wins
		if(ScoreHand(cards, player) > ScoreHand(cards, dealer)){
			cout << "Player wins!" << '\n';
			return 0;
		// If the dealer cards have more value than the dealer wins
		}else if(ScoreHand(cards, dealer) > ScoreHand(cards, player)){
			cout << "Dealer wins!" << '\n';
			return 0;
		// If both players cards have the same value than they tie
		}else if(ScoreHand(cards, dealer) == ScoreHand(cards, player)){
			cout << "Player and dealer draw." << '\n';
			return 0;
		}
	}

	return 0;
}

// Initializes card deck
void IntializeCardDeck(int (&cards)[NUM_CARDS]){
	cards[NUM_CARDS] = {0};
}

// Takes a random number and returns a number that is inbetween them
int GetRandom(int min, int max){
	int randomNum;

	randomNum = min + rand() % (max - min + 1);

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

	// Loops through the cards array determining if the cards belongs to that specific player
	for(j = 0; j < NUM_CARDS; j++){
		if(cards[j] == player){
			// If the index of the cards array mod 13 is aboce 10 (J or Q) or 0 (K), then the value of that card is 10
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
