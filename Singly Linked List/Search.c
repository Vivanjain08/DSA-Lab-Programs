#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int n, i, search, position = 1;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Creating linked list
    for (i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else {
            temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    // Searching
    printf("\nEnter element to search: ");
    scanf("%d", &search);

    temp = head;

    while (temp != NULL) {
        if (temp->data == search) {
            printf("Element found at position %d", position);
            return 0;
        }

        temp = temp->next;
        position++;
    }

    printf("Element not found");

    return 0;
}