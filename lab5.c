#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void create() {
    int n, x;
    struct node *newnode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &x);

        newnode = malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        if (head == NULL)
            head = temp = newnode;
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void delete_first() {
    if (head == NULL) {
        printf("List Empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}

void delete_last() {
    if (head == NULL) {
        printf("List Empty\n");
        return;
    }

    struct node *temp = head, *prev = NULL;

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void delete_specific() {
    int x;
    printf("Enter element to delete: ");
    scanf("%d", &x);

    struct node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == x) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List Empty\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int ch;

    while (1) {
        printf("\n1. Create\n2. Delete First\n3. Delete Specific\n4. Delete Last\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: create(); break;
            case 2: delete_first(); break;
            case 3: delete_specific(); break;
            case 4: delete_last(); break;
            case 5: display(); break;
            case 6: return 0;
            default: printf("Invalid choice\n");
        }
    }
}