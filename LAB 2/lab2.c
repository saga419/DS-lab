#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int main() {
    char infix[50], postfix[50];
    int i, k = 0;
    char ch;

    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        // Operand
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        // Opening parenthesis
        else if (ch == '(') {
            push(ch);
        }
        // Operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            push(ch);
        }
        // Closing parenthesis
        else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop(); // Remove '('
        }
    }

    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
