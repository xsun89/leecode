#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
char status[8][8];

bool checkWP(int i, int j, int wKingX, int wKingY){
    return (wKingX - i == 1) && (abs(wKingY - j) == 1);
}

bool checkBP(int i, int j, int bKingX, int bKingY){
    return (i - bKingX == 1) && (abs(bKingY - j) == 1);
}

bool checkN(int i, int j, int kingX, int kingY)
{
    return (abs(i-kingX) == 2 && abs(j-kingY) == 1) ||
            (abs(i-kingX) == 1 && abs(j-kingY) == 2);
}

bool checkB(int i, int j, int kingX, int kingY){
    int step, currentX = i, currentY = j, directX, directY;
    bool checked = false;
    if(abs(i-kingX) == abs(j=kingY))
    {
        checked = true;
        directX = (i < kingX)? 1 : -1;
        directY = (j < kingY)? 1 : -1;
        step = abs(i-kingX);
        while(step>0){
            currentX += directX;
            currentY += directY;
            if(status[currentX][currentY] != '.'){
               checked = false;
                break;
            }
            step--;
        }
    }

    return checked;
}

bool checkR(int i, int j, int kingX, int kingY){
    int step, currentX=i, currentY=j, directX, directY;
    bool checked = false;
    if(i==kingX || j==kingY){
        checked = true;
        step = abs(i-kingX) > 0 ? abs(i-kingX) : abs(j-kingY);
        directY = (j==kingY) ? (0) : (j<kingY? 1:-1);
        directX = (i==kingX) ? (0) : (i<kingX? 1:-1);
        while(step > 0) {
            currentY += directY;
            currentX += directX;
            if (status[currentX][currentY] != '.') {
                checked = false;
                break;
            }
            step--;
        }
    }

    return checked;
}

bool checkQ(int i, int j, int kingX, int kingY)
{
    return checkR(i, j, kingX, kingY) || checkB(i, j, kingX, kingY);
}
void check(int gameCount)
{
    int bKingX = -1, bKingY = -1, wKingX = -1, wKingY = -1;
    bool wChecked = false, bChecked = false;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++) {
            if (status[i][j] == 'k') {
                bKingX = i;
                bKingY = j;
            } else if(status[i][j] == 'K'){
                wKingX = i;
                wKingY = j;
            }
        }
    }

    if(bKingX == -1 || bKingY == -1 || wKingX == -1 || wKingY == -1){
        return;
    }

    cout << "Game #" << gameCount <<": ";
    for(int i=0; i<8; i++){
        for(int j=0; j<8;j++){
            switch (status[i][j]){
                case 'p':
                    wChecked = checkWP(i, j, wKingX, wKingY);
                    break;
                case 'P':
                    bChecked = checkBP(i, j, bKingX, bKingY);
                    break;
                case 'n':
                    wChecked = checkN(i, j, wKingX, wKingY);
                    break;
                case 'N':
                    bChecked = checkN(i, j, bKingX, bKingY);
                    break;
                case 'b':
                    wChecked = checkB(i, j, wKingX, wKingY);
                    break;
                case 'B':
                    bChecked = checkB(i, j, bKingX, bKingY);
                    break;
                case 'r':
                    wChecked = checkR(i, j, wKingX, wKingY);
                    break;
                case 'R':
                    bChecked = checkR(i, j, bKingX, bKingY);
                    break;
                case 'q':
                    wChecked = checkQ(i, j, wKingX, wKingY);
                    break;
                case 'Q':
                    bChecked = checkQ(i, j, bKingX, bKingY);
                    break;
                default:
                    break;

            }
            if(bChecked){
                cout << "black king is in check." << endl;
                return;
            }
            if(wChecked){
                cout << "white king is in check." << endl;
                return;
            }
        }
    }
    cout << "no king is in check." << endl;
}
int main (int ac, char *av[])
{
    memset(status, -1, sizeof(status));
    string line;
    int gameCount = 1, temp = 0;
    while(getline(cin, line))
    {
        if(line == "end"){
            break;
        }
        if(line != ""){
            for(int i=0; i<8;i++){
                status[temp][i] = line[i];
            }
            temp++;
        }else{
            check(gameCount);
            gameCount++;
            temp = 0;
        }

    }
    return 0;
}