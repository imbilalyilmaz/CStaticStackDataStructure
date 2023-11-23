#include <stdio.h>
#include <malloc.h>

struct Stack{
    int* array;
    int top;
    int capacity;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack*));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity*sizeof(int*));
    return stack;
}

int isFull(struct Stack* stack) {
    if(stack->top == stack->capacity-1) return 1;
    else return 0;
}
int isEmpty(struct Stack* stack) {
    if(stack->top == -1) return 1;
    else return 0;
}

void push(struct Stack* stack,int data) {
    if(isFull(stack)) {
        printf("Stack is full");
        return;
    }
    stack->array[++stack->top] = data;
}

int pop(struct Stack* stack) {
    if(isEmpty(stack)) {
        printf("Stack is empty");
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

void writeStack(struct Stack *stack){
    int i;
    if(stack==NULL) {
        printf("This stack is not defined\n");
        return;
    }
    printf("Stack capacity: %4d\n",stack->capacity);
    printf("Number of elements :%4d\n",stack->top+1);
    for(i=stack->top; i>=0; i--){
        printf("%4d ",stack->array[i]);
    }
    printf("\n");
}


void destroyStack(struct Stack** stack) {
    free((*stack)->array);
    free(*stack);
    *stack = NULL;
}

int main() {
    struct Stack* stack = createStack(5);
    push(stack,10);
    push(stack,23);
    push(stack,123);
    push(stack,56);
    push(stack,12);
    writeStack(stack);
    pop(stack);
    writeStack(stack);
    destroyStack(&stack);
    writeStack(stack);





    return 0;
}
