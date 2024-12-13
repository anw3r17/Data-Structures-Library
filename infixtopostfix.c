#include <stdio.h>
#include <ctype.h>
#include <string.h>

int priority(char k) {
    if (k == '-' || k == '+')
        return 1;
    if (k == '*' || k == '/')
        return 2;
    return 0;
}

int main() {
    char infix[20], postfix[20], stack[20];
    int i, j = -1, top = -1;

    printf("Enter the infix expression:");
    scanf("%s", infix);

    for (i = 0; i < strlen(infix); i++) {
        if (isalpha(infix[i]))
            postfix[++j] = infix[i];
             else if (infix[i] == '(')
            stack[++top] = infix[i];
        else if (infix[i] == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[++j] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(')
                top--;
        }
        else if (top == -1 || priority(infix[i]) > priority(stack[top])) {
            stack[++top] = infix[i];
        } else if (priority(infix[i]) <= priority(stack[top])) {
            postfix[++j] = stack[top];
            top--;
            i--;
        }
    }

    while (top >= 0) {
        postfix[++j] = stack[top--];
    }

    postfix[++j] = '\0';
    printf("\nThe postfix form is: %s\n", postfix);

    return 0;
}
