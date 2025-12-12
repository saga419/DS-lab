#include <stdio.h>
#include <ctype.h> // for isalnum()

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char x) {
    stack[++top] = x;
}

// Pop function
char pop() {
    return stack[top--];
}

// Function to check precedence
int precedence(char x) {
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;
    char ch;

    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s", infix);

    while ((ch = infix[i++]) != '\0') {
        // If operand → directly add to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // Push '(' to stack
        else if (ch == '(') {
            push(ch);
        }
        // If ')' → pop until '(' is found
        else if (ch == ')') {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        }
        // Operator encountered
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }

    // Pop all remaining operators
    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0'; // terminate string

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}