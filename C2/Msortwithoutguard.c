#include <stdio.h>
#include <stdlib.h>
//#include <limits.h>
#define ARRLENGTH 9

void merge(int*, int, int, int);
void mergesort(int*, int, int);

int main()
{
    int i;
    int arr[ARRLENGTH] = {0, 2, 4, 5, 7, 1, 2, 3, 6};

    mergesort(arr, 1, ARRLENGTH - 1);

    for (i = 1; i < ARRLENGTH; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void merge(int* arr, int p, int q, int r)
{
    int i, j, k;
    //printf("q - p + 1 is %d\n", q - p + 1);
    //printf("r - p is %d\n", r - p);

    int *L = (int*) malloc(sizeof(int) * (q - p + 1));
    int *R = (int*) malloc(sizeof(int) * (r - q));

    //printf("size of L is %d\n", (int)(sizeof(L) / sizeof(int)));
    //printf("size of R is %d\n", (int)(sizeof(R) / sizeof(int)));

    for (i = p; i <= q; i++)
    {
        L[i - p] = arr[i];
        //printf("L[%d] is %d\n", i - p, L[i - p]);
    }
    for (j = q + 1; j <= r; j++)
    {
        R[j - q - 1] = arr[j];
        //printf("R[%d] is %d\n", j - q - 1, R[j - q - 1]);
    }

    i = j = 0;
    //L[q - p + 1] = INT_MAX;
    //R[r - q] = INT_MAX;

    for (k = p; k <= r; ++k)
    {
        if (i >= q - p + 1 || j >= r - q)
            break;

        if (L[i] < R[j])
        {
            arr[k] = L[i];
            //printf("arr[%d] is %d\n", k, arr[k]);
            i++;
        }
        else
        {
            arr[k] = R[j];
            //printf("arr[%d] is %d\n", k, arr[k]);
            j++;
        }
    }
    while (i < q - p + 1)
    {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < r - q)
    {
        arr[k] = R[j];
        ++j;
        ++k;
    }

    free(L);
    free(R);
}

void mergesort(int* arr, int p, int r)
{
    int q;

    if (p < r)
    {
    q = (p + r) / 2;
    mergesort(arr, p, q);
    mergesort(arr, q + 1, r);
    merge(arr, p, q, r);
    }
}
