#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;
#define NCADES 52
#define NSUITS 4
char values[13] = "23456789TJQKA";
char suits[4] = "CDHS";

int rankCard(char value, char suit)
{
    int i, j;
    int number = -1;
    for(i=0; i<NCADES/NSUITS; i++){
        if(value == values[i]){
            for(j=0; j<NSUITS; j++){
                if(suit == suits[j]){
                    number = i*NSUITS + j;
                }
            }
        }
    }
    return number;
}

char getSuit(int number){
    return suits[number%NSUITS];
}

char getValue(int number){
    return values[number/NSUITS];
}

int getRank(vector<int>* c)
{
    int max;
    vector<int>::iterator it = c->begin();
    max = *it;
    int value[5];
    int suit[5];
    int i = 0;
    for(; it==c->end(); it++){
        value[i] = *it/NSUITS;
        suit[i] = *it%NSUITS;
        if(max < value[i])
            max = value[i];
        i++;
    }

    int num = suit[0];
    for(i=1; i<5; i++){
        if(num != suit[i]){
            num = suit[i];
        }
    }

    if(num == suit[0]){
        return max;
    }


}
int main(int ac, char *av[])
{
    string line;
    string black[5];
    string white[5];
    vector<int> b;
    vector<int> w;
    while (getline(cin, line))
    {
        memset(black, 0, sizeof(black));
        memset(white, 0, sizeof(white));

        const char* tmp;
        istringstream stm(line);
        for(int i=0; i<5; i++){
            stm >> black[i];
            tmp = black[i].c_str();
            b.push_back(rankCard(tmp[0], tmp[1]));
        }
        for(int i=0; i<5; i++){
            stm >> white[i];
            tmp = white[i].c_str();
            w.push_back(rankCard(tmp[0], tmp[1]));
        }

        int brank = getRank(&b);
        int wrank = getRank(&w);

    }

    return 0;
}
