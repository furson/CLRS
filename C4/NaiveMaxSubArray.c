#include <stdio.h>
#include <limits.h>

#define ARRAYLENGTH 17

struct arrayitem
{
    int low;
    int high;
    int maxvalue;
};

struct arrayitem maxsubarr(int*, int, int);

int main()
{
    int arr[ARRAYLENGTH] = {0, 13, -3, -25, 20,
                            -3, -16, -23, 18, 20,
                            -7, 12, -5, -22, 15, -4, 7};
    struct arrayitem ans;

    ans = maxsubarr(arr, 1, ARRAYLENGTH - 1);
    printf("The maxvalue is %d\n", ans.maxvalue);
    printf("The low index is %d and the high index is %d\n", ans.low, ans.high);

    return 0;
}

struct arrayitem maxsubarr(int *arr, int low, int high)
{
    int i, j;
    int sum, maxsum, retlow, rethigh;
    struct arrayitem ans;

    maxsum = INT_MIN;
    for (i = low; i <= high; ++i)
    {
        sum = arr[i];
        if (sum > maxsum)
        {
            maxsum = sum;
            rethigh = retlow = i;
        }

        for (j = i + 1; j <= high; ++j)
        {
            sum = sum + arr[j];
            if (sum > maxsum)
            {
                maxsum = sum;
                retlow = i;
                rethigh = j;
            }
        }

    }

    ans.low = retlow;
    ans.high = rethigh;
    ans.maxvalue = maxsum;

    return ans;
}
