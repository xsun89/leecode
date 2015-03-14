#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>


#define NCADES 52
#define NSUITS 4
char values[] = "23456789TJQKA";
char suits[] = "cdhs";
int rank_card(char value, char suit)
{
    int i, j;
    int number = -1;
    for(i=0; i<NCADES/NSUITS; i++){
        if(values[i] = value){
            for(j=0; j<NSUITS; j++){
                if(suits[j] == suit){
                    number = j + i*NSUITS;
                }
            }
        }
    }

    return number;
}

char derank_suit(int number){
    return suits[number%NSUITS];
}

char derank_value(int number){
    return values[number/NSUITS];
}
int main()
{
    std::queue<int>  deck[2];
    char c, value, suit;
    while(true){
        for(int i=0; i<2; i++) {
            deck[i].empty();

            while ((c = getchar()) != '\n') {
                if (c == EOF) {
                    return 0;
                }
                if (c != ' ') {
                    value = c;
                    suit = getchar();
                    int number = rank_card(value, suit);
                    deck[i].push(number);
                }
            }
        }

        //war(&deck[0], &deck[1]);
    }
    return 0;
}