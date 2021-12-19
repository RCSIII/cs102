# Slot Machine

# **Assignment**
You will be writing a program to simulate a slot machine. The player will start with $1000 and you will repeatedly ask the user how much money they wish to insert into the machine before spinning, or allow the player to quit. If the player runs out of money, the game is over. Additionally, the player cannot spend more money than they have available. You should store the player's wagers and winnings in order to output statistics when the user is done playing.

# **Spinning and Payouts**
After placing a bet, the money is immediately subtracted from the player's balance. The slot machine has 3 reels which are spun after the lever is pulled. Each reel will randomly contain a integer value between 2 and 7 inclusive after being spun. If the all 3 reels have the value 7, the player obtained a jackpot and will receive the amount which they wagered times 10. If all 3 reels match, but contain a value other than 7, award the player their wagered amount times 5. Otherwise, if only 2 reels match, award the player their wager times 2. If none of the reels match, the player does not receive any earnings.

# **Restrictions / Hints**
1. At the start, ask the user for a seed to use for the random number generator. Use this value to seed your random numbers.

2. Before each spin, show the user their current balance and ask for a wager.

3. The slot machine only accepts wagers containing whole dollar amounts. You may not enter any spare change.

4. You must use an array to store the value of each reel.

5. You must use a for loop to input the random values of each reel.

6. You must use a vector to store the amount of each wager.

7. You must use a vector to store the winnings of each spin.

8. If the user wagers an amount of 0 or less, stop playing and output play statistics. Additionally, if the user has a balance of $0 and is unable to wager, end the game and output play statistics. If the user never played and walks away immediately, do not output any statistics.

9. At the end, output a summary of each spin including the wager and amount won. Then output the smallest and largest wager, and the smallest non-zero winnings and the largest winnings from a single spin. Note that if the user never wins, the smallest and largest winnings displayed should be 0.

# **Examples**

```
Input a seed: 102

Your money: $1000
Place a bet: $50
 4 4 6
You won $100!

Your money: $1050
Place a bet: $50
 6 7 3
You didn't win.

Your money: $1000
Place a bet: $100
 4 4 2
You won $200!

Your money: $1100
Place a bet: $200
 6 7 5
You didn't win.

Your money: $900
Place a bet: $0

You wagered $50 and won $100.
You wagered $50 and won $0.
You wagered $100 and won $200.
You wagered $200 and won $0.

Your smallest wager was $50.
Your largest wager was $200.
Your smallest winnings was $100.
Your largest winnings was $200.
```
```
Input a seed: YBMAZ
Input a seed: 3

Your money: $1000
Place a bet: $ZAMBY
Place a bet: $1
 2 3 2
You won $2!

Your money: $1001
Place a bet: $2
 2 5 6
You didn't win.

Your money: $999
Place a bet: $3
 2 6 3
You didn't win.

Your money: $996
Place a bet: $4
 6 6 6
You won $20!

Your money: $1012
Place a bet: $0

You wagered $1 and won $2.
You wagered $2 and won $0.
You wagered $3 and won $0.
You wagered $4 and won $20.

Your smallest wager was $1.
Your largest wager was $4.
Your smallest winnings was $2.
Your largest winnings was $20.
```
```
Input a seed: 130

Your money: $1000
Place a bet: $1000
 5 3 2
You didn't win.

You are out of money!

You wagered $1000 and won $0.

Your smallest wager was $1000.
Your largest wager was $1000.
Your smallest winnings was $0.
Your largest winnings was $0.
```
```
Input a seed: 140

Your money: $1000
Place a bet: $0
 
You walked away without playing.
```
