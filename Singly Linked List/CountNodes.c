#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int n, i, count = 0;

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

    // Counting nodes
    temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("\nTotal number of nodes = %d", count);

    return 0;
}