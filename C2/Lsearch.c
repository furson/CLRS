#include <stdio.h>
#define ARRLENGTH 11

int linearsearch(int*, int);

int main()
{
    int v, ans;
    int arr[ARRLENGTH] = {0, 1, 2, 3, 4 ,5 ,6, 7, 8, 9, 10};

    scanf("%d", &v);
    if ((ans = linearsearch(arr, v)) != 0)
        printf("v is in array and the location is %d\n", ans);
    else
        printf("v is not in array\n");

    return 0;
}

int linearsearch(int *arr, int v)
{
    int i;

    for(i = 1; i < ARRLENGTH; i++)
        if (arr[i] == v)
            return i;

    return 0;
}
