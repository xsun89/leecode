// Minesweeper （扫雷）
/*
Input
        The input will consist of an arbitrary number of fields. The first line of each field
contains two integers n and m (0 < n,m ≤ 100) which stand for the number of lines
and columns of the field, respectively. Each of the next n lines contains exactly m
        characters, representing the field.
Safe squares are denoted by “.” and mine squares by “*,” both without the quotes.
The first field line where n = m = 0 represents the end of input and should not be
        processed.
Output
        For each field, print the message Field #x: on a line alone, where x stands for the
        number of the field starting from 1. The next n lines should contain the field with the
“.” characters replaced by the number of mines adjacent to that square. There must
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
// 解题思路很简单，使用字符数组表示给定的地雷图，逐个扫描统计各点周围的地雷总数。在计算地雷总数时，
// 用到了一个小技巧，设置边界数组 bounds，将当前的点顺次加上边界数组的值即可得到当前点周围的 8 个
// 点，注意不要忘记判断点是否在地雷地图范围内。
#include <iostream>

using namespace std;

int main() {

    int rows, cols;
    cin >> rows >> cols;
    cout << rows << " " << cols << endl;
    char input[rows][cols];
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin >> input[i][j];
        }
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            int count = 0;
            if(i == 0){

            }
            cout << input[i][j];
        }
        cout << endl;
    }
    return 0;
}