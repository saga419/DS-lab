#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* insert_end(struct node *start, int value) {
    struct node *temp, *p;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    if (start == NULL)
        return temp;

    p = start;
    while (p->next != NULL)
        p = p->next;
    p->next = temp;

    return start;
}

void display(struct node *start) {
    struct node *p = start;
    if (p == NULL) {
        printf("List is empty\n");
        return;
    }
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// ******** SORT LINKED LIST ********
void sort(struct node *start) {
    struct node *i, *j;
    int temp;

    for (i = start; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// ******** REVERSE LINKED LIST ********
struct node* reverse(struct node *start) {
    struct node *prev = NULL, *curr = start, *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev; // new head
}

// ******** CONCATENATE TWO LINKED LISTS ********
struct node* concatenate(struct node *l1, struct node *l2) {
    struct node *p;

    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    p = l1;
    while (p->next != NULL)
        p = p->next;

    p->next = l2;
    return l1;
}

// ******** MAIN FUNCTION ********
int main() {
    struct node *list1 = NULL, *list2 = NULL;
    int choice, value;

    while (1) {
        printf("\n1.Insert in List1\n2.Insert in List2\n3.Sort List1\n4.Reverse List1\n5.Concatenate List1 & List2\n6.Display List1\n7.Display List2\n8.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            list1 = insert_end(list1, value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            list2 = insert_end(list2, value);
            break;

        case 3:
            sort(list1);
            printf("List1 Sorted.\n");
            break;

        case 4:
            list1 = reverse(list1);
            printf("List1 Reversed.\n");
            break;

        case 5:
            list1 = concatenate(list1, list2);
            printf("Concatenation Done.\n");
            break;

        case 6:
            printf("List1: ");
            display(list1);
            break;

        case 7:
            printf("List2: ");
            display(list2);
            break;

        case 8:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
