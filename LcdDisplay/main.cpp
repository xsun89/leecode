#include <iostream>
#include <cstring>
#include <iostream>
#include <cstring>

using namespace std;

#define MAXLENGTH 8

void lcd_display (long size, long number)
{
    // 将number拆分为单个的数字。
    int digits[MAXLENGTH];

    memset (digits, -1, sizeof (digits));
    if (number == 0)
        digits[MAXLENGTH - 1] = 0;
    else
    {
        for (int i = MAXLENGTH - 1; number > 0; i--)
        {
            digits[i] = number % 10;
            number /= 10;
        }
    }

    // 定义每个数字的关键笔划。
    string outline[5][10] = {
            " - ", "   ", " - ", " - ", "   ", " - ", " - ", " - ", " - ", " - ",
            "| |", "  |", "  |", "  |", "| |", "|  ", "|  ", "  |", "| |", "| |",
            "   ", "   ", " - ", " - ", " - ", " - ", " - ", "   ", " - ", " - ",
            "| |", "  |", "|  ", "  |", "  |", "  |", "| |", "  |", "| |", "  |",
            " - ", "   ", " - ", " - ", "   ", " - ", " - ", "   ", " - ", " - "
    };

    // 根据指定size将关键笔划扩大显示，实际上就是将关键笔划重复size次。
    for (int row = 1; row <= (2 * size + 3); row++)
    {
        for (int i = 0; i < MAXLENGTH; i++)
            if (digits[i] != -1)
            {
                string line;
                if (row == 1)
                    line = outline[0][digits[i]];
                if (2 <= row && row < (size + 2))
                    line = outline[1][digits[i]];
                if (row == (size + 2))
                    line = outline[2][digits[i]];
                if ((size + 3) <= row && row <= (2 * size + 2))
                    line = outline[3][digits[i]];
                if (row == (2 * size + 3))
                    line = outline[4][digits[i]];

                // 输出关键笔划。
                cout << line[0];
                for (int j = 0; j < size; j++)
                    cout << line[1];
                cout << line[2];

                // 在两个数字间要有一列空行。
                if (i < (MAXLENGTH - 1))
                    cout << " ";
            }
        cout << '\n';
    }
}

int main (int ac, char *av[])
{
    long size, number;

    while ((cin >> size >> number, size || number))
    {
        lcd_display (size, number);
        cout << endl;
    }

    return 0;
}