#include <stdio.h>
#define ARRLENGTH 7

//SS means selection sort
void SS(int*);

int main()
{
    int i;
    int arr[ARRLENGTH] = {0, 5, 2, 4, 6, 1, 3};

    SS(arr);
    for (i = 1; i < ARRLENGTH; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void SS(int *arr)
{
    int i, j;
    int min, minpos;
    int temp;

    for (i = 1; i < ARRLENGTH - 1; ++i)
    {
        min = arr[i];
        minpos = i;

        for (j = i + 1; j < ARRLENGTH; ++j)
        {
            if(arr[j] < min)
            {
                min = arr[j];
                minpos = j;
            }
        }

        temp = arr[minpos];
        arr[minpos] = arr[i];
        arr[i] = temp;
    }
}
