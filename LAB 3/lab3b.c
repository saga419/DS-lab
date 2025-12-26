#include <stdio.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

void insert() {
    int item;
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }
    printf("Enter element to insert: ");
    scanf("%d", &item);

    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    cq[rear] = item;
}

void delete() {
    if (front == -1) {
        printf("Queue Empty! Cannot delete.\n");
        return;
    }
    printf("Deleted element: %d\n", cq[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
