#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node *next;
};

// Create a polynomial
struct Node* createPolynomial(int n) {
    struct Node *head = NULL, *newNode, *temp;
    int i;

    for (i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

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

    return head;
}

// Add two polynomials
struct Node* addPolynomial(struct Node *p1, struct Node *p2) {
    struct Node *result = NULL, *newNode, *temp;

    while (p1 != NULL && p2 != NULL) {

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->next = NULL;

        if (p1->exponent == p2->exponent) {
            newNode->coefficient = p1->coefficient + p2->coefficient;
            newNode->exponent = p1->exponent;

            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exponent > p2->exponent) {
            newNode->coefficient = p1->coefficient;
            newNode->exponent = p1->exponent;

            p1 = p1->next;
        }
        else {
            newNode->coefficient = p2->coefficient;
            newNode->exponent = p2->exponent;

            p2 = p2->next;
        }

        if (result == NULL) {
            result = newNode;
        }
        else {
            temp = result;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    // Remaining terms of first polynomial
    while (p1 != NULL) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coefficient = p1->coefficient;
        newNode->exponent = p1->exponent;
        newNode->next = NULL;

        if (result == NULL)
            result = newNode;
        else {
            temp = result;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }

        p1 = p1->next;
    }

    // Remaining terms of second polynomial
    while (p2 != NULL) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coefficient = p2->coefficient;
        newNode->exponent = p2->exponent;
        newNode->next = NULL;

        if (result == NULL)
            result = newNode;
        else {
            temp = result;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }

        p2 = p2->next;
    }

    return result;
}

// Display polynomial
void display(struct Node *head) {
    while (head != NULL) {
        printf("%dx^%d", head->coefficient, head->exponent);

        if (head->next != NULL)
            printf(" + ");

        head = head->next;
    }

    printf("\n");
}

int main() {
    struct Node *p1, *p2, *sum;
    int n1, n2;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);

    printf("\nEnter first polynomial:\n");
    p1 = createPolynomial(n1);

    printf("\nEnter number of terms in second polynomial: ");
    scanf("%d", &n2);

    printf("\nEnter second polynomial:\n");
    p2 = createPolynomial(n2);

    sum = addPolynomial(p1, p2);

    printf("\nFirst Polynomial: ");
    display(p1);

    printf("Second Polynomial: ");
    display(p2);

    printf("Sum: ");
    display(sum);

    return 0;
}