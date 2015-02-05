// Minesweeper ��ɨ�ף�
/*
Input
        The input will consist of an arbitrary number of fields. The first line of each field
contains two integers n and m (0 < n,m �� 100) which stand for the number of lines
and columns of the field, respectively. Each of the next n lines contains exactly m
        characters, representing the field.
Safe squares are denoted by ��.�� and mine squares by ��*,�� both without the quotes.
The first field line where n = m = 0 represents the end of input and should not be
        processed.
Output
        For each field, print the message Field #x: on a line alone, where x stands for the
        number of the field starting from 1. The next n lines should contain the field with the
��.�� characters replaced by the number of mines adjacent to that square. There must
be an empty line between field outputs.
Sample Input
4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0
Sample Output
Field #1:
*100
2210
1*10
1110
Field #2:
**100
33200
1*100
*/
//
// ����˼·�ܼ򵥣�ʹ���ַ������ʾ�����ĵ���ͼ�����ɨ��ͳ�Ƹ�����Χ�ĵ����������ڼ����������ʱ��
// �õ���һ��С���ɣ����ñ߽����� bounds������ǰ�ĵ�˳�μ��ϱ߽������ֵ���ɵõ���ǰ����Χ�� 8 ��
// �㣬ע�ⲻҪ�����жϵ��Ƿ��ڵ��׵�ͼ��Χ�ڡ�
#include <iostream>
#include <cstring>
using namespace std;
#define MAXSIZE 100
bool inrange(int rows, int cols, int x, int y)
{
    return (x>=0 && x<rows) && (y>=0 && y <cols);
}
void display(char input[][MAXSIZE], int rows, int cols)
{
    int boundary[8][2] = {{-1,-1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(input[i][j] == '*')
                cout << '*';
            else{
                int mines = 0;
                int m, n;
                for(int k=0; k < 8; k++){
                    m = i+boundary[k][0];
                    n = j+boundary[k][1];
                    if(inrange(rows, cols, m, n) && input[m][n] == '*'){
                        mines += 1;
                    }
                }
                cout << mines;
            }
        }

        cout << endl;
    }

}
int main() {

    int rows, cols;
    while(cin >> rows >> cols) {
        if(!rows && !cols){
            break;
        }
        cout << rows << " " << cols << endl;
        char input[MAXSIZE][MAXSIZE];
        memset(input, 0, sizeof(input));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> input[i][j];
            }
        }
        display(input, rows, cols);
   }
    return 0;
}