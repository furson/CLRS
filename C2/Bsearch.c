#include <stdio.h>
#define ARRLENGTH 11

int Bsearch(int*, int, int, int);

int main()
{
    int x, ans;
    int arr[ARRLENGTH] = {0, 1, 3, 4, 5, 6, 7, 8, 9, 11, 16};

    scanf("%d", &x);
    if (ans = Bsearch(arr, x, 1, ARRLENGTH - 1))
        printf("The location is %d.\n", ans);
    else
        printf("%d is not in the array.\n", x);

    return 0;
}

int Bsearch(int *arr, int x, int start, int end)
{
    int mid;

    if (start > end)
        return 0;
    mid = (start + end) / 2;
    if (x == arr[mid])
        return mid;
    else if (x > arr[mid])
        return Bsearch(arr, x, mid + 1, end);
    else
        return Bsearch(arr, x, start, mid - 1);
}
