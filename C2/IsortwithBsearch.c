#include <stdio.h>

void InsertionSortbyAscending(int*);
int BSearch(int*, int, int, int);

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
    int i, j, k, key;

    for (j = 2; j < 7; ++j)
    {
        key = arr[j];

        i = j - 1;
        k = BSearch(arr, key, 1, i);
        //printf("k is %d\n", k);
        for (; i >= k; arr[i + 1] = arr[i], i--)
            ;
        arr[k] = key;
    }
}

//return the location in which the number is the smallest number bigger than x
int BSearch(int* arr, int x, int begin, int end)
{
    int mid = (begin + end) / 2;

    while (begin < end)
    {
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            begin = mid + 1;
        else
            end = mid - 1;
        mid = (begin + end) / 2;
    }
    //special point
    //if x is the biggest number in the sorted part
    //the location should be the end(or begin) + 1
    if (x > arr[begin])
        return begin + 1;
    else
        return begin;

}
