# Honors Peer-graded Assignment: Week 2 Honors Assignment

Use a struct to define a card as an enumerated member that is its suit value and a short that is its pips value.

Write a function that randomly shuffles the deck.

Submit your work as a text file. 

Then deal out 7 card hands and evaluate the probability that a hand has no pair, one pair, two pair, three of a kind, full house and 4 of a kind.  This is a Monte Carlo method to get an approximation to these probabilities.  Use at least 1 million randomly generated hands.

You can check against probabilities found in a standard table. 

Seven-Card Stud

|    Hand        |Combinations|Probabilities|
|----------------|------------|-------------|
|Royal flush     | 4324       | 0.00003232  |
|Straight flush  | 37260      | 0.00027851  |
|Four of a kind  | 224848     | 0.00168067  |
|Full house      | 3473184    | 0.02596102  |
|Flush           | 4047644    | 0.03025494  |
|Straight        | 6180020    | 0.04619382  |
|Three of a kind | 6461620    | 0.04829870  |
|Two pair        | 31433400   | 0.23495536  |
|Pair            | 58627800   | 0.43822546  |
|Ace high or less| 23294460   | 0.17411920  |
|Total           | 133784560  | 1.00000000  |

## Detectable hands:

* Royal flush :white_check_mark:    
* Straight flush  :white_check_mark:
* Four of a kind  :white_check_mark:
* Full house :white_check_mark:
* Flush :white_check_mark:          
* Straight :white_check_mark:       
* Three of a kind :white_check_mark:
* Two pair :white_check_mark:        
* Pair :white_check_mark:           
* Ace high or less
* Total           