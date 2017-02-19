#define NDEBUG
#include <assert.h>
#include <stdio.h>

void InsertionSortbyAscending(int*);

int main()
{
    int i;
    int arr[7] = {0, 5, 2, 4, 6, 1, 3}; //0 is not gonna be used

    InsertionSortbyAscending(arr);
    for (i = 1; i < (sizeof(arr) / sizeof(int)); ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void InsertionSortbyAscending(int* arr)
{
    int i, j, key;

    for (j = 2; j < 7; ++j)
    {
        assert(j == 1);
        key = arr[j];
        for (i = j - 1; i > 0 && arr[i] > key; arr[i + 1] = arr[i], --i)
        {
            printf("arr[%d] is %d\n", i, arr[i]);
        }
        arr[i + 1] = key;
    }
}
