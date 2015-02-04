#include <iostream>
using namespace std;
#define MAXSIZE  10000
int cache[10000];
int counting(long long number)
{
    if(number == 1)
        return 1;
    if(number & 1){
        number += (number << 1) + 1;
    } else{
        number >>= 1;
    }

    if(number < MAXSIZE)
    {
        if(cache[number] == 0) {
            cache[number] = counting(number);
        }
        else{
            return 1 + cache[number];
        }
    }
    return 1 + counting(number);
}

int main() {

    int start, end, result, max=0;

    while(cin >> start >> end){
        if(start == 0 && end == 0){
            break;
        }
        for(int i=start; i<=end; i++) {
            result = counting(i);
            if(result > max)
            {
                max = result;
            }
        }
        cout << start << " " << end << " " << max << endl;
    }
    return 0;
}