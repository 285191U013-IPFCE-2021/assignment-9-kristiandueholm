#include "..\include\sum.h"

/* Sums int array with length n */
int sum(int a[], int n)
{
    // Base case
    if (n == 0)
    {
        return 0;
    }
    
    // Recursive case
    int x = a[n-1] + sum(a, n-1);

    return x;
}