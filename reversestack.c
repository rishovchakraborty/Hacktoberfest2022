#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function to create a new stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if a stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to check if a stack is full
int isFull(struct Stack* stack) {
    return (stack->top == stack->capacity - 1);
}

// Function to push an item onto a stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        return; // Stack is full, cannot push
    }
    stack->array[++stack->top] = item;
}

// Function to pop an item from a stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1; // Stack is empty, cannot pop
    }
    return stack->array[stack->top--];
}

// Function to reverse a stack
void reverseStack(struct Stack* sourceStack, struct Stack* auxStack) {
    while (!isEmpty(sourceStack)) {
        int item = pop(sourceStack);
        push(auxStack, item);
    }
}

// Function to print the elements of a stack
void printStack(struct Stack* stack) {
    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }
    printf("\n");
}

int main() {
    struct Stack* stack = createStack(5);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

    printf("Original Stack: ");
    printStack(stack);

    struct Stack* auxStack = createStack(5);
    reverseStack(stack, auxStack);

    printf("Reversed Stack: ");
    printStack(auxStack);

    free(stack->array);
    free(stack);
    free(auxStack->array);
    free(auxStack);

    return 0;
}
