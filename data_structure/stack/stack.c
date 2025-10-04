#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

#define MAX_SIZE 100







typedef struct 
{
    int item[MAX_SIZE];
    int top;
    
}Stack;

void init_Stack(Stack* stack){
    stack->top = -1;
}

bool isFull(Stack* stack){return (stack->top == MAX_SIZE-1);}
bool isEmpty(Stack* stack){return (stack->top == -1);}

int Push(Stack* stack,int num){
    if(isFull(stack)){
        printf("The stack is full");
        return -1;
    }
    printf("Push the %d, to the stack.\n",num);
    stack->item[++stack->top] = num;
}

int Pop(Stack* stack){
    if(isEmpty(stack)){
        printf("The stack is empty");
        return -1;
    }
    printf("Pop the %d from the stack.\n",stack->item[stack->top]);
    --stack->top;
}

void Peek(Stack* stack){
    printf("The top of the stack is:%d\n",stack->item[stack->top]);
}



int main()
{
    Stack* stack = (Stack*)malloc(sizeof(stack));
    init_Stack(stack);
    Push(stack,10);
    Push(stack,20);
    Push(stack,30);
    Peek(stack);
    Pop(stack);
    Peek(stack);
    for(int i=0;i<stack->top+1;i++){
        if(i==0){
        printf("The element on the stack is:");
        }
        printf("%d ",stack->item[stack->top-i]);
    }
    return 0;
}

