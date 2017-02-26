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
struct arrayitem maxcrosssubarr(int*, int, int, int);

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
    int i;
    int sum, max, templow, retlow, rethigh;
    struct arrayitem ans;

    max = INT_MIN;
    templow = 1;
    retlow = low;
    rethigh = high;
    sum = 0;
    for (i = 1; i < ARRAYLENGTH; ++i)
    {
        sum += arr[i];
        if (sum > max)
        {
            retlow = templow;
            rethigh = i;
            max = sum;
        }
        if (sum < 0)
        {
            sum = 0;
            templow = i + 1;
        }
    }
    ans.low = retlow;
    ans.high = rethigh;
    ans.maxvalue = max;

    return ans;
}
