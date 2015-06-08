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

void clear_queue(std::queue<int>* a, std::queue<int>* b)
{
    while (!a->empty()){
        int tmp = a->front();
        a->pop();
        b->push(tmp);
    }
}
void war(std::queue<int> *a, std::queue<int> *b) {
    int steps = 0;
    int x, y;
    std::queue<int> c;
    bool inwar;
    inwar = false;
    while ((!a->empty()) && (!b->empty() && (steps < 10000))) {
        steps = steps + 1;
        x = a->front();
        a->pop();
        y = b->front();
        b->pop();
        c.push(x);
        c.push(y);
        if (inwar) {
            inwar = false;
        } else {
            if (derank_value(x) > derank_value(y))
                clear_queue(&c, a);
            else if (derank_value(x) < derank_value(y))
                clear_queue(&c, b);
            else if (derank_value(y) == derank_value(x))
                inwar = true;
        }
    }
    if (!a->empty() && b->empty())
        printf("a wins in %d steps \n", steps);
    else if (a->empty() && !b->empty())
        printf("b wins in %d steps \n", steps);
    else if (!a->empty() && !b->empty())
        printf("game tied after %d steps, |a|=%d |b|=%d \n",
                steps, a->size(), b->size());
    else
        printf("a and b tie in %d steps \n", steps);
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

        war(&deck[0], &deck[1]);
    }
    return 0;
}