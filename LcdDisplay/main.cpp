#include <iostream>
#include <cstring>
#include <iostream>
#include <cstring>

using namespace std;

#define MAXLENGTH 8

void lcd_display (long size, long number)
{
    // ��number���Ϊ���������֡�
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

    // ����ÿ�����ֵĹؼ��ʻ���
    string outline[5][10] = {
            " - ", "   ", " - ", " - ", "   ", " - ", " - ", " - ", " - ", " - ",
            "| |", "  |", "  |", "  |", "| |", "|  ", "|  ", "  |", "| |", "| |",
            "   ", "   ", " - ", " - ", " - ", " - ", " - ", "   ", " - ", " - ",
            "| |", "  |", "|  ", "  |", "  |", "  |", "| |", "  |", "| |", "  |",
            " - ", "   ", " - ", " - ", "   ", " - ", " - ", "   ", " - ", " - "
    };

    // ����ָ��size���ؼ��ʻ�������ʾ��ʵ���Ͼ��ǽ��ؼ��ʻ��ظ�size�Ρ�
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

                // ����ؼ��ʻ���
                cout << line[0];
                for (int j = 0; j < size; j++)
                    cout << line[1];
                cout << line[2];

                // ���������ּ�Ҫ��һ�п��С�
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