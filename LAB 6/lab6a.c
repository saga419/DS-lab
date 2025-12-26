#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL, *head2 = NULL;


struct node* create(struct node *head) {
    int n, i, item;
    struct node *temp, *newnode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &item);
        newnode->data = item;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
    return head;
}


void display(struct node *head) {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void sort(struct node *head) {
    struct node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}


struct node* reverse(struct node *head) {
    struct node *prev = NULL, *curr = head, *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


struct node* concatenate(struct node *head1, struct node *head2) {
    struct node *temp;
    if (head1 == NULL)
        return head2;

    temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}

int main() {
    int choice;

    while (1) {
        printf("\n1.Create List1\n2.Create List2\n3.Sort List1\n4.Reverse List1\n5.Concatenate\n6.Display List1\n7.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: head1 = create(head1); break;
            case 2: head2 = create(head2); break;
            case 3: sort(head1); break;
            case 4: head1 = reverse(head1); break;
            case 5: head1 = concatenate(head1, head2); break;
            case 6: display(head1); break;
            case 7: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
