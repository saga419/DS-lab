#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;    
struct node *front = NULL;    
struct node *rear = NULL;


void stack_push() {
    int item;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter element: ");
    scanf("%d", &item);

    newnode->data = item;
    newnode->next = top;
    top = newnode;
}

void stack_pop() {
    struct node *temp;
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    temp = top;
    printf("Popped element: %d\n", temp->data);
    top = top->next;
    free(temp);
}

void stack_display() {
    struct node *temp = top;
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void queue_insert() {
    int item;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter element: ");
    scanf("%d", &item);

    newnode->data = item;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void queue_delete() {
    struct node *temp;
    if (front == NULL) {
        printf("Queue Empty\n");
        return;
    }
    temp = front;
    printf("Deleted element: %d\n", temp->data);
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

void queue_display() {
    struct node *temp = front;
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    int choice;

    while (1) {
        printf("\n1.Stack Push\n2.Stack Pop\n3.Stack Display\n");
        printf("4.Queue Insert\n5.Queue Delete\n6.Queue Display\n7.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: stack_push(); break;
            case 2: stack_pop(); break;
            case 3: stack_display(); break;
            case 4: queue_insert(); break;
            case 5: queue_delete(); break;
            case 6: queue_display(); break;
            case 7: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
