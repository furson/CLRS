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
    int arr[ARRAYLENGTH] = {0, -13, -3, -25, -20,
                            -3, -16, -23, -18, -20,
                            -7, -12, -4, -4, -4, -4, -7};
    struct arrayitem ans;

    ans = maxsubarr(arr, 1, ARRAYLENGTH - 1);
    printf("The maxvalue is %d\n", ans.maxvalue);
    printf("The low index is %d and the high index is %d\n", ans.low, ans.high);

    return 0;
}

struct arrayitem maxsubarr(int *arr, int low, int high)
{
    int mid;
    struct arrayitem defaultans;
    struct arrayitem left, right, crossmid;

    defaultans.low = low;
    defaultans.high = high;
    defaultans.maxvalue = arr[low];

    if (low == high)
        return defaultans;
    else
    {
        mid = (low + high) / 2;
        left = maxsubarr(arr, low, mid);
        right = maxsubarr(arr, mid + 1, high);
        crossmid = maxcrosssubarr(arr, low, mid, high);

        if (left.maxvalue >= right.maxvalue && left.maxvalue >= crossmid.maxvalue)
            return left;
        else if (right.maxvalue >= left.maxvalue && right.maxvalue >= crossmid.maxvalue)
            return right;
        else
            return crossmid;
    }
}

struct arrayitem maxcrosssubarr(int *arr, int low, int mid, int high)
{
    int left_sum, right_sum, sum;
    int i;
    struct arrayitem ans;

    sum = 0;
    left_sum = INT_MIN;
    ans.low = mid;
    for (i = mid; i >= low; --i)
    {
        sum = sum + arr[i];

        if (sum > left_sum)
        {
            left_sum = sum;
            ans.low = i;
        }
    }

    sum = 0;
    right_sum = INT_MIN;
    ans.high = mid;
    for (i = mid + 1; i <= high; ++i)
    {
        sum = sum + arr[i];

        if (sum > right_sum)
        {
            right_sum = sum;
            ans.high = i;
        }
    }
    ans.maxvalue = left_sum + right_sum;

    return ans;
}
