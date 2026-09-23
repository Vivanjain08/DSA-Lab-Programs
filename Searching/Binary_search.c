#include <stdio.h>

int main()
{
    int a[10], n, i, search;
    int low, high, mid;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in sorted order:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &search);

    low = 0;
    high = n - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(a[mid] == search)
        {
            printf("Element found at position %d", mid + 1);
            return 0;
        }

        if(search < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    printf("Element not found");

    return 0;
}