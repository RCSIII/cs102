# Blackjack

# **Assignment**
You will write a program that plays the card game, Blackjack, with a player. You will have exactly two players, the player him/herself and the dealer. Both will work off of the same deck of 52 cards, so no cards will be duplicated between the dealer and player.

For purposes of this program, the Blackjack rules will be simplified.

Each card has a value:

Ace - 1 point
2, 3, 4, 5, 6, 7, 8, 9, 10 - Value of card (2, 3, ..., 10 points)
Jack, Queen, King - 10 points

Each card also has one of four suits:

Ace of Hearts, Ace of Clubs, Ace of Spades, Ace of Diamonds
King of Hearts, ..., and so on.

For purposes of this program, the card value and suit will be abbreviated as:

AH = "Ace of Hearts"
AC = "Ace of Clubs"
AD = "Ace of Diamonds"
AS = "Ace of Spades"
2H, 3C, 4D,..., KH, and so on.

The point of the game is to get to the value 21 without going over. You have two "responses", hit or stand. Hit means the dealer will provide you an extra card. Stand means you'll take the score of all of the cards you currently have. You should prompt the user for a response again if an invalid input is provided. If your score is above 21, it is called a "bust", and you lose. If your score is 21, you automatically win without the dealer having a chance to play. After you stand, the dealer plays the game and tries to get above your score.

For purposes of your programmed dealer, it will keep "hitting" until it has a card value greater than or equal to the value 18. If the value is 18 or higher, the dealer will always stand. If the dealer goes above 21, then it will automatically lose, and the player will win.

If the player and dealer have not gone above 21, then the scores are compared. Whomever has the higher score wins. If both have the same score, they tie in a "draw".

The output is in "Examples" below. The only formatting requirement is that all of the cards must be in a left-justified field, 20 characters wide.

# **Examples**
```
Dealer has cards: KD 3S               (13)
You have cards  : QD AS               (11)
Hit or stand    ? hit

Dealer has cards: KD 3S               (13)
You have cards  : QD AS 6D            (17)
Hit or stand    ? stand

Dealer hits     : KD 3S KS            (23)
Dealer busts, player wins!
```
```
Dealer has cards: 4S 8D               (12)
You have cards  : 9D 10H              (19)
Hit or stand    ? hit

Dealer has cards: 4S 8D               (12)
You have cards  : 9D 10H 10C          (29)
Player busts, dealer wins!
```
```
Dealer has cards: KS 9D               (19)
You have cards  : 9D 10H              (19)
Hit or stand    ? stand

Dealer has cards: KS 9D               (19)
You have cards  : 9D 10H              (19)
Player and dealer draw.
```
```
Dealer has cards: 2S 9D               (11)
You have cards  : 10D 9H              (19)
Hit or stand    ? stand

Dealer hits     : 2S 9D 9S            (20)
Dealer stands   : 2S 9D 9S            (20)

Dealer has cards: 2S 9D 9S            (20)
You have cards  : 10D 9H              (19)
Dealer wins!
```

# **Restrictions**

1. You must write prototypes, definitions, and calls for functions that perform the following operations: deal a single card to player or dealer, return a random number between a minimum and maximum value, initialize the cards, score the player and/or dealer's hands. NOTE: Even though you can initialize your array when you declare it, we want you to pass your array to a function to initialize it.
