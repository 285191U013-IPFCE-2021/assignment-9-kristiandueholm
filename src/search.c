#include "..\include\search.h"
#include <stdbool.h>

/* Determines if element "x" is in array "a" of length "n" */
bool search(int a[], int n, int x)
{
    if (n == 0)
    {
        return false;
    }
    
    else if ((n > 0) && (a[n-1] == x))
    {
        return true;
    }
    
    else
    {
        search(a, n-1, x);
    }
    
}