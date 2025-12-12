#include <stdio.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

void insert() {
    int x;

    // Overflow condition
    if ((front == 0 && rear == MAX - 1) || (rear + 1 == front)) {
        printf("Circular Queue Overflow!\n");
    } else {
        printf("Enter element to insert: ");
        scanf("%d", &x);

        if (front == -1) { // first element
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }

        cq[rear] = x;
        printf("%d inserted.\n", x);
    }
}

void delete() {
    if (front == -1) {
        printf("Circular Queue Empty!\n");
    } else {
        printf("%d deleted.\n", cq[front]);

        if (front == rear) {
            front = rear = -1; // queue becomes empty
        } else {
            front = (front + 1) % MAX;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Circular Queue Empty!\n");
    } else {
        printf("Circular Queue: ");

        int i = front;
        while (1) {
            printf("%d ", cq[i]);
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    int ch;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}