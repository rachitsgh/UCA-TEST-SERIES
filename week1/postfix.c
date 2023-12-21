#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct {
    int* arr;
    int top;
} Stack;

void create(Stack* stack, int size) {
    stack->arr = (int*)malloc(size * sizeof(int));
    stack->top = -1;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int val) {
    stack->top++;
    stack->arr[stack->top] = val;
}

int pop(Stack* stack) {
    int val = stack->arr[stack->top];
    stack->top--;
    return val;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int performOperation(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            printf("Invalid operator: %c\n", operator);
            exit(EXIT_FAILURE);
    }
}

int evaluate( char* expression) {
    Stack stack;
    create(&stack, 100);

    int i = 0;
    while (expression[i] != '?') {
        if (isdigit((unsigned char)expression[i])) {
            int operand = 0;
            while (isdigit((unsigned char)expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            push(&stack, operand);
        } else if (isOperator(expression[i])) {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result = performOperation(operand1, operand2, expression[i]);
            push(&stack, result);
            i++;
        } else {
            i++;
        }
    }

    return pop(&stack);
}

int main() {
    int testCases;
    scanf("%d", &testCases);

    for (int t = 0; t < testCases; t++) {
        char expression[100];
        scanf(" %[^\n]", expression);

        int result = evaluate(expression);
        printf("%d\n", result);
    }

    return 0;
}

