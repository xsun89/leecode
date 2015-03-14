#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>

using namespace std;
#define MAXNUMBER  100
void sortIntArray(int *number, int n)
{
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(number[i] > number[j]){
                int tem;
                tem = number[i];
                number[i] = number[j];
                number[j] = tem;
            }
        }
    }

    return;
}
int main (int ac, char *av[])
{
    int number[MAXNUMBER];

    string line;
    while(getline(cin, line)) {
        if (line[0] == '0'){
            break;
        }
        memset(number, 0, sizeof(number));
        int n, i;
        bool isJolly = true;
        istringstream iss(line);
        iss >> n;
        for (i = 1; i <= n; i++) {
            iss >> number[i - 1];
        }
        if (n == 1 && number[0] == 1) {
            isJolly = true;
            continue;
        }
        int ret[n-1];
        for (i = 0; i < n; i++) {
            ret[i - 1] = abs(number[i] - number[i - 1]);
        }
        sortIntArray(ret, n - 1);

        for (i = 1; i <= n - 1; i++) {
            if (ret[i - 1] != i) {
                isJolly = false;
                break;
            }
        }
        if (isJolly)
            cout << line << "       " << "Jolly" << endl;
        else
            cout << line << "       " << "not Jolly" << endl;
    }
    return 0;
}