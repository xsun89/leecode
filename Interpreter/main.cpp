#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int execute(int *reg, int *mem)
{
    int code = mem[0];
    int pointer = 0;
    int step = 0, a, b, c;
    while(code != 100 && pointer < 1000){
        code = mem[pointer];
        a = code / 100;
        b = (code /10) % 10;
        c = code % 10;
        switch (a)
        {
            case 0:
                if(reg[c] != 0){
                    pointer = reg[b] -1;
                }
                break;
            case 1:
                if(!b && !c){
                    return 1+step;
                }
            case 2:
                reg[b] = c;
                break;
            case 3:
                reg[b] += c;
                break;
            case 4:
                reg[b] *= c;
                break;
            case 5:
                reg[b] = reg[c];
                break;
            case 6:
                reg[b] += reg[c];
                break;
            case 7:
                reg[b] *= reg[c];
                break;
            case 8:
                reg[b] = mem[reg[c]];
                break;
            case 9:
                mem[reg[c]] = reg[b];
                break;
        }

        reg[b] %= 1000;
        pointer++;
        step++;
    }

    return step;
}

int main (int ac, char *av[])
{
    int reg[10], mem[1000];
    int cases = 0;
    string line;
    cin >> cases;
    cin.ignore();
    getline(cin, line);
    while(cases--)
    {
        memset(reg, 0, sizeof(reg));
        memset(mem, 0, sizeof(mem));
        for(int i=0; getline(cin, line) && line.length(); i++) {
            mem[i] = atoi(line.data());
        }
        cout << execute(reg, mem) << endl;

        if(cases)
            cout << endl;

    }
    return 0;
}