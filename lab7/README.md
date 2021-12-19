# Card Dealer

# **Assignment**
You will write a program that deals 2 cards to several players. All players will work off of the same deck of 52 cards, so no cards will be duplicated between any players.

Each card has a value and a suit:

```
Values: Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King
Suits: Hearts, Diamonds, Spades, Clubs
```
Examples: Ace of Hearts, Ace of Clubs, Ace of Spades, Ace of Diamonds
King of Hearts, ..., and so on.

For purposes of this program, the card value and suit will be abbreviated as:

```
AH = "Ace of Hearts"
AC = "Ace of Clubs"
AD = "Ace of Diamonds"
AS = "Ace of Spades"
2H, 3C, 4D,..., JD, QC, KH, and so on.
```
Your program will simply deal 2 cards to each player, effectively allowing them to play a card game using your program.

The output is in "Examples" below. The only formatting requirement is that all of the cards must be in a left-justified field, 20 characters wide.

You will have an array of 52 cards. The actual array index will be a unique value and suit. The value of the array at that index will be which player has the card, or 0 for an undealt card.

# **Functions**
1. Write a function called GetRandom, which will take a minimum and maximum value. This function will return a random number between [min, max] (inclusively).

2. Write a function called DealCard, which will take an array of 52 cards and a player to deal a card to. The function will randomly choose an undealt card and assign it to the given player. The function will then return which card it dealt to the player.

3. Write a function called ScoreHand, which will take an array of 52 cards and a player whose hand to score. The function will return the final score. To score the hand, each face card (Jack, Queen, King) will be 10 points. The numeric cards will be their numeric value, and aces will be 1 point. The suit of the card is not part of the point value calculation.

# **Examples**
```
How many players? 2
Player 1 has cards: 10S 10H          (20)
Player 2 has cards: 10D 9H           (19)
```
```
How many players? 4
Player 1 has cards: 9D 9S            (18)
Player 2 has cards: JD 4H            (14)
Player 3 has cards: 4C 2S            (6)
Player 4 has cards: 9H 2D            (11)
```

# **Restrictions**
1. The 52 cards must be in a single array. The array will have 52 elements, and it will store which player has which card. Since each player will receive exactly two cards, you must ensure that no more than 26 players will be allowed to play.

2. You must use arithmetic to determine which card fits each array index (0 - 51). You must not use a branch construct, such as any if statements or switch statements. For this, you might need an array to store each suit 'D','C', 'H', 'S', and another to store the values A, 2, 3, ..., Q, K.
