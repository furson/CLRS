#include <stdio.h>
#define ADDBIT 8

void addition(int*, int*, int*);

int main()
{
    int add1[ADDBIT] = {0, 1, 1, 0, 1, 1, 0, 1};
    int add2[ADDBIT] = {0, 1, 1, 0, 1, 1, 0, 1};
    int ans[ADDBIT + 1] = {0};
    int i;

    addition(ans, add1, add2);
    for (i = 0; i < ADDBIT + 1; i++)
        printf("%d", ans[i]);   //expected answer is 001101101
    printf("\n");

    return 0;
}

void addition(int *ans, int *add1, int *add2)
{
    int i, flag, tans;
    flag = 0;

    for (i = 0; i < ADDBIT; ++i)
    {
        tans = add1[i] + add2[i];
        if ((tans + flag) >= 2)
        {
            ans[i] = tans + flag - 2;
            flag = 1;
        }
        else
        {
            ans[i] = tans + flag;
            flag = 0;
        }
    }
    if (flag == 1)
        ans[ADDBIT] = 1;
}
