#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
    struct node *prev;
};

/* Create DLL */
struct node *createDLL(struct node *start) {
    struct node *temp, *p;
    int data;

    start = NULL;

    while (1) {
        printf("Enter element (-1 to stop): ");
        scanf("%d", &data);

        if (data == -1)
            break;

        p = (struct node *)malloc(sizeof(struct node));
        p->info = data;
        p->next = NULL;
        p->prev = NULL;

        if (start == NULL) {
            start = p;
        } else {
            temp = start;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = p;
            p->prev = temp;
        }
    }
    return start;
}


/* Insert new node to the left of a given value */
struct node *insertLeft(struct node *start, int key, int item) {
    struct node *temp, *p;

    if (start == NULL) {
        printf("List is empty\n");
        return start;
    }

    temp = start;

    while (temp != NULL && temp->info != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found\n", key);
        return start;
    }

    p = (struct node *)malloc(sizeof(struct node));
    p->info = item;

    p->next = temp;
    p->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = p;
    else
        start = p;

    temp->prev = p;

    return start;
}

/* Delete node based on value */
struct node *deleteNode(struct node *start, int item) {
    struct node *temp;

    if (start == NULL) {
        printf("List is empty\n");
        return start;
    }

    temp = start;

    while (temp != NULL && temp->info != item)
        temp = temp->next;

    if (temp == NULL) {
        printf("Element not found\n");
        return start;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        start = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node deleted\n");

    return start;
}

/* Display DLL */
void display(struct node *start) {
    struct node *temp = start;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("DLL elements: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Main Function */
int main() {
    struct node *start = NULL;
    int choice, n, key, item;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Create DLL\n");
        printf("2. Insert to left of a node\n");
        printf("3. Delete a node\n");
        printf("4. Display DLL\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                start = createDLL(start);
                break;

            case 2:
                printf("Enter value of node (key): ");
                scanf("%d", &key);
                printf("Enter new value to insert: ");
                scanf("%d", &item);
                start = insertLeft(start, key, item);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &item);
                start = deleteNode(start, item);
                break;

            case 4:
                display(start);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
