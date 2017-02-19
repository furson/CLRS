#include <stdio.h>
#define ARRLENGTH 7

void ISbydec(int*);

int main()
{
    int i;
    int arr[7] = {0, 5 ,2, 4, 6, 1, 3};

    ISbydec(arr);
    for (i = 1; i < ARRLENGTH; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void ISbydec(int* arr)
{
    int i, j;
    int key;

    for (j = 2; j < ARRLENGTH; ++j)
    {
        key = arr[j];

        for (i = j - 1; i > 0 && arr[i] <= key; arr[i + 1] = arr[i], i--)
            ;
            //printf("arr[%d] is %d\n", i, arr[i]);
        arr[i + 1] = key;
    }
}
