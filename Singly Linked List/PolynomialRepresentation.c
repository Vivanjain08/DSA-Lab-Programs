#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    // Creating polynomial
    for (i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter coefficient: ");
        scanf("%d", &newNode->coefficient);

        printf("Enter exponent: ");
        scanf("%d", &newNode->exponent);

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

    // Display polynomial
    printf("\nPolynomial: ");

    temp = head;

    while (temp != NULL) {
        printf("%dx^%d", temp->coefficient, temp->exponent);

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}
