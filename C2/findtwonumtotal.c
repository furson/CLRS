#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define ARRLENGTH 101

int findtotalx(int*, int);
int Bsearch(int*, int, int, int);
void merge(int*, int, int, int);
void mergesort(int*, int, int);

int main()
{
    int i, x;
    int arr[ARRLENGTH];

    //0 means not use
    for (i = 0; i <= 100; ++i)
        arr[i] = i;

    scanf("%d", &x);
    if (!findtotalx(arr, x))
        printf("Not found!\n");
    else
        printf("Yes, we find it in galaxy!\n");

    return 0;
}

int findtotalx(int* arr, int x)
{
    int i, loc;

    mergesort(arr, 1, ARRLENGTH - 1);
    for (i = 1; i < ARRLENGTH; ++i)
    {
        //printf("The %dth circulation.\n", i);
        if(loc = Bsearch(arr, x - arr[i], 1, ARRLENGTH))
        {
            //printf("loc is %d\n", loc);
            if (arr[loc] != arr[i])
                return 1;
        }
    }

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

void merge(int* arr, int p, int q, int r)
{
    int i, j, k;
    //printf("q - p + 1 + 1 is %d\n", q - p + 1 + 1);
    //printf("r - p + 1 is %d\n", r - p + 1);

    int *L = (int*) malloc(sizeof(int) * (q - p + 1 + 1));
    int *R = (int*) malloc(sizeof(int) * (r - q + 1));

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
    L[q - p + 1] = INT_MAX;
    R[r - q] = INT_MAX;

    for (k = p; k <= r; ++k)
    {
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
