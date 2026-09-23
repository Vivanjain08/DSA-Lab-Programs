#include <stdio.h>

int main() {
    int a[100], n, i, pos, value;

    // Input array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Traversal
    printf("Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    // Insertion
    printf("\nEnter position and value to insert: ");
    scanf("%d %d", &pos, &value);

    for(i = n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = value;
    n++;

    printf("After insertion: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    // Deletion
    printf("\nEnter position to delete: ");
    scanf("%d", &pos);

    for(i = pos - 1; i < n - 1; i++)
        a[i] = a[i + 1];

    n--;

    printf("After deletion: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}