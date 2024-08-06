/*
Use a struct to define a card as an enumerated member that is its suit
value and a short that is its pips value.

Write a function that randomly shuffles the deck.

Submit your work as a text file.

Then deal out 7 card hands and evaluate the probability that a
hand has no pair, one pair, two pair, three of a kind, full house and 4
of a kind.  This is a Monte Carlo method to get an approximation to these
probabilities.  Use at least 1 million randomly generated hands.

*/

#include <stdio.h>
#include <stdlib.h> /*for rand() and srand()*/
#include <time.h> /*for time()*/

#define HAND_SIZE 7
#define DECK_SIZE 52

typedef enum suit {spades, clubs, hearts, diamonds} suit;

typedef struct card 
{
    short pips; 
    suit suit;
    short order;
    int n_picks;
} card;

typedef struct strength_counts
{
    int royal;
    int straight_flush;
    int four_of_a_kind;
    int full_house;
    int flush;
    int straight;
    int three_of_a_kind;
    int two_pair;
    int one_pair;
    int ace_high_or_less;
    int total;
} strength_counts;

typedef struct strength_probas
{
    float royal;
    float straight_flush;
    float four_of_a_kind;
    float full_house;
    float flush;
    float straight;
    float three_of_a_kind;
    float two_pair;
    float one_pair;
    float ace_high_or_less;
    float total;
} strength_probas;

void print_array(int array[], int size)
{
    int i;
    printf("[ ");
    for (i = 0; i < size; i++)
    {
        printf("%3d", array[i]);
    }
    printf("]\n");
}

void print_card(card c){

    char suit_char;

    switch(c.suit)
    {
        case (spades): suit_char = 's'; break;
        case (clubs): suit_char = 'c'; break;
        case (hearts):  suit_char = 'h'; break;
        case (diamonds):  suit_char = 'd'; break;
    }

    switch (c.pips)
    {
    case 12: 
        printf("[ A %c] ", suit_char); 
        break;
    case 11:
        printf("[ K %c] ", suit_char);
        break;
    case 10:
        printf("[ Q %c] ", suit_char);
        break;
    case  9:
        printf("[ J %c] ", suit_char);
        break;
    default:
        printf("[%2d %c] ", c.pips + 2, suit_char);
        break;
    }
}

void print_hand(card hand[], int size)
{
    int i;
    for (i=0; i < size; i++)
    {
        print_card(hand[i]);
        if (((i+1)%13)==0)
            putchar('\n');
    }
    putchar('\n');
}

void build_deck(card deck[])
{
    suit i;
    short j, order;

    for(i=spades; i<4; i++)
    {
        for(j=0; j<13; j++)
        {
            order = (j + i * 13);
            deck[order].suit = i; // spades:0, clubs:1, hearts:2, diamonds:3
            deck[order].pips = 12-j; // 12:"A", 11:"K", 10:"Q", 9:"J", 8:10, 7:9, 6:8, 5:7, 4:6, 3:5, 2:4, 1:3, 0:2
            deck[order].order = order;//0,...,51
            deck[order].n_picks = 0;
        }
    }
}

card pick_card(card deck[], int epoch)
{
    int n;
    n = rand() % 52; /*pick a random card*/
    while (deck[n].n_picks >= epoch){
        /*if the card was selected before in a epoch, try again*/
        n = rand() % 52;
    }
    deck[n].n_picks = epoch;
    return deck[n];
}

void build_hand(card deck[], card hand[], int epoch)
{
    int i;
    for (i = 0; i < HAND_SIZE; i++)
    {
        hand[i] = pick_card(deck, epoch);
    }
}

void sort_hand(card hand[], int size)
{   
    card temp_card;
    int i, j;

    for (i=0; i<size-1; i++){
        for (j=1; j<size-i; j++){
            if (hand[j].order < hand[j-1].order){
                temp_card = hand[j];
                hand[j] = hand[j-1];
                hand[j-1] = temp_card;
            }
        }
    }

}

void count_suits(card hand[], int suits[])
{
    int i;
    for (i = 0; i < HAND_SIZE; i++)
    {
        ++suits[hand[i].suit];
    }
}

void count_pips(card hand[], int pips[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        //printf("%d ", hand[i].pips);
        ++pips[(hand[i].pips)];
        //print_array(pips,13);
    }
}


int has_n_of_a_kind(int pips[], int n)
{
    int i, ans=0;
    for (i = 0; i < 13; i++)
    {   
        switch (n)
        {
        case 2:
            if (pips[i] == n) 
                ++ans;
            break;
        case 3:
        case 4:
            if (pips[i] == n){
                ++ans;
                break;
            }
        }
    }
    return ans;
}

int is_pair(int pips[])
{
    return (has_n_of_a_kind(pips, 2) == 1);
}

int is_two_pairs(int pips[]){
    return (has_n_of_a_kind(pips,2)==2);
}

int is_three_of_a_kind(int pips[])
{
    return has_n_of_a_kind(pips, 3);
}

int is_four_of_a_kind(int pips[])
{
    return has_n_of_a_kind(pips, 4);
}

int is_full_house(int pips[])
{
    if (has_n_of_a_kind(pips, 2) & has_n_of_a_kind(pips, 3))
        return 1;
    else
        return 0;
}

int is_straight(int pips[])
{
    int i, seq=0;
    for (i = 0; i <= 13; i++)
    {
        if (pips[i % 13]>0)
            ++seq;
        else
            seq=0;
        if (seq==5)
            return 1;
    }
    return 0;
}

int is_flush(int suits[])
{
    int i;
    for (i=0; i<4; i++)
    {
        if((suits[i]>2) & (suits[i]<5))
            return 0;
        else if (suits[i]==5)
            return 1;
    }
    return 0;
}

int is_straight_flush(int suits[], int pips[])
{
    if (is_flush(suits) & is_straight(pips))
        return 1;
    else
        return 0;
}

int is_royal(int suits[], int pips[])
{
    int i;
    if (is_straight_flush(suits, pips))
    {
        for (i=12; i>7; i--)
        {
            if(pips[i]==0)
                return 0;
        }
        return 1;
    }
    else
        return 0;
}

void count_pips_suit(card hand[], int suits[], int pips_suit[]){
    int i=-1, sum=0; 
    while (sum < 5){
        i++;
        sum += suits[i];
        //printf("i=%d, su=%d\n", i, suits[i]);
    }
    //printf("\nsum = %d\n", sum);
    //printf("\ni=%d, suits[i] = %d\n",i, suits[i]);
    
    if (suits[i] >= 5){
        //printf("\nhello\n");
        count_pips(hand + sum - suits[i], pips_suit, suits[i]);
    }
}


void evaluate_test(card hand[])
{
    int i = -1, sum = 0;
    int suits[4]={0}, pips_total[13]={0}, pips_suit[13]={0};

    count_suits(hand, suits);
    count_pips(hand, pips_total, 7);
    count_pips_suit(hand, suits, pips_suit);

    //print_array(suits, 4);
    //print_array(pips_total, 13);
    //print_array(pips_suit, 13);

    printf("Is royal: %c\n", is_royal(suits, pips_suit) ? 'S' : 'N');
    printf("Is straight flush: %c\n", is_straight_flush(suits, pips_suit) ? 'S' : 'N');
    printf("Is 4 of a kind: %c\n", is_four_of_a_kind(pips_total) ? 'S' : 'N');
    printf("Is full house: %c\n", is_full_house(pips_total) ? 'S' : 'N');
    printf("Is flush: %c\n", is_flush(suits) ? 'S' : 'N');
    printf("Is straight: %c\n", is_straight(pips_total) ? 'S' : 'N');
    printf("Is 3 of a kind: %c\n", is_three_of_a_kind(pips_total) ? 'S' : 'N');
    printf("Is 2 pairs: %c\n", is_two_pairs(pips_total) ? 'S' : 'N');
    printf("Is pair: %c\n", is_pair(pips_total) ? 'S' : 'N');
    
}

void evaluate_hand(card hand[], strength_counts *strengths)
{
    int i = -1, sum = 0;
    int suits[4]={0}, pips[13]={0}, pips_suit[13]={0};

    sort_hand(hand, HAND_SIZE);

    count_suits(hand, suits);
    count_pips(hand, pips, 7);
    count_pips_suit(hand, suits, pips_suit);

    strengths->total++;

    if (is_royal(suits, pips_suit)){
        strengths->royal++;
        return ;
    }
    else if (is_straight_flush(suits, pips_suit)){
        strengths->straight_flush++;
        return ;
    }
    else if (is_four_of_a_kind(pips)){
        strengths->four_of_a_kind++;
        return ;
    }
    else if (is_full_house(pips)){
        strengths->full_house++;
        return ;
    }
    else if (is_flush(suits)){
        strengths->flush++;
        return ;
    }
    else if (is_straight(pips))
    {
        strengths->straight++;
        return;
    }
    else if (is_three_of_a_kind(pips))
    {
        strengths->three_of_a_kind++;
        return;
    }
    else if (is_two_pairs(pips))
    {
        strengths->two_pair++;
        return;
    }
    else if (is_pair(pips))
    {
        strengths->one_pair++;
        return;
    }
    else{
        strengths->ace_high_or_less++;
        return;
    }
}

void calculate_avgs(strength_counts strengths, strength_probas *probas)
{
    probas->royal = (float)strengths.royal / strengths.total;
    probas->straight_flush = (float) strengths.straight_flush/strengths.total;
    probas->four_of_a_kind = (float) strengths.four_of_a_kind/strengths.total;
    probas->full_house = (float) strengths.full_house/strengths.total;
    probas->flush = (float) strengths.flush/strengths.total;
    probas->straight = (float) strengths.straight/strengths.total;
    probas->three_of_a_kind = (float) strengths.three_of_a_kind/strengths.total;
    probas->two_pair = (float) strengths.two_pair/strengths.total;
    probas->one_pair = (float) strengths.one_pair/strengths.total;
    probas->ace_high_or_less = (float) strengths.ace_high_or_less/strengths.total;
    probas->total = (float)strengths.total / strengths.total;
}

void print_statistics(strength_counts strengths, strength_probas probas){
    printf(
        "\n%s%10d%15f\n%s%10d%15f\n%s%10d%15f\n%s%10d%15f\n%s%10d%15f\n%s%10d%15f\n%s%10d%15f\n%s%10d%15f\n%s%10d%15f\n%s%10d%15f\n%s%10d%15f\n",
        "Royal flush     : ", strengths.royal           , probas.royal           , 
        "Straight flush  : ", strengths.straight_flush  , probas.straight_flush  ,
        "Four of a kind  : ", strengths.four_of_a_kind  , probas.four_of_a_kind  ,
        "Full house      : ", strengths.full_house      , probas.full_house      ,
        "Flush           : ", strengths.flush           , probas.flush           ,
        "Straight        : ", strengths.straight        , probas.straight        ,
        "Three of a kind : ", strengths.three_of_a_kind , probas.three_of_a_kind ,
        "Two pair        : ", strengths.two_pair        , probas.two_pair        ,
        "Pair            : ", strengths.one_pair        , probas.one_pair        ,
        "Ace high or less: ", strengths.ace_high_or_less, probas.ace_high_or_less,
        "Total           : ", strengths.total           , probas.total
        );
}

void run_until(card deck[]){
    int try = 1;
    card hand[7];
    strength_counts strengths={0};

    build_hand(deck, hand, try);
    evaluate_hand(hand, &strengths);

    while(strengths.straight_flush==0){
        build_hand(deck, hand, ++try);
        evaluate_hand(hand, &strengths);
    }
    printf("On try %d we've got: \n", try);
    print_hand(hand, HAND_SIZE);
}


int main(void){
    card deck[DECK_SIZE];
    card hand[HAND_SIZE];
    strength_counts strengths = {0};
    strength_probas probas={0};
    int i, epoch, pips[13]={0};

    build_deck(deck);
    srand(time(NULL));
    //run_until(deck);
   
    for (epoch=1; epoch<=100000000; epoch++)
    {
        build_hand(deck, hand, epoch);
        
        evaluate_hand(hand, &strengths);
    }
    calculate_avgs(strengths, &probas);
    print_statistics(strengths, probas);

    return 0;
}