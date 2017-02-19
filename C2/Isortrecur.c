#include <stdio.h>
#define ARRLENGTH 7

void Isortrecur(int*, int);

int main()
{
    int i;
    int arr[ARRLENGTH] = {0, 5, 2, 4, 6, 1, 3}; //0 means not use

    Isortrecur(arr, 2);
    for (i = 1; i < ARRLENGTH; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void Isortrecur(int *arr, int loc)
{
    int i, key;

    if (loc < ARRLENGTH)
    {
        key = arr[loc];

        for (i = loc - 1; i >= 1 && arr[i] > key; arr[i + 1] = arr[i], --i)
            ;
        arr[i + 1] = key;
        Isortrecur(arr, loc + 1);
    }
}
