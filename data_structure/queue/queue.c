#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

#define MAX_SIZE 100


struct queue{

int items[MAX_SIZE];
int front;
int rear;

};

typedef struct queue Queue;

void Init_Queue(Queue* q){
    q->front = -1;
    q->rear = 0;
}

bool Empty_Queue(Queue* q){return((q->front)==(q->rear-1));}

bool Full_Queqe(Queue* q){return(q->rear == MAX_SIZE);}

void De_Queue(Queue* q){
    if(Empty_Queue(q)){
        printf("The queue is empty!!!");
    }
    printf("The dequeue operator remove the data:%d",q->items[q->front+1]);
    q-> front+=1;
}

void En_Queue(Queue* q,int val){
    if(Full_Queqe(q)){
        printf("The queue is full!!!");
    }
    q->items[q->rear] = val; 
    q->rear+=1;
}


void Peek_Queue(Queue* q){
    if(Empty_Queue(q)){
        printf("The queue is empty!!!");
    }
    printf("Show the peek of queue:%d",q->items[q->rear-1]);
}

void Show_Queue(Queue* q){
        if(Empty_Queue(q)){
        printf("The queue is empty!!!");
    }
    printf("The all item of queue is:");
    for(int i=q->front+1;i<q->rear;i++){
        printf("%d ",q->items[i]);
    }
    printf("\n");

}

int main()
{
    Queue *q=(Queue*)malloc(sizeof(Queue));
    Init_Queue(q);
    En_Queue(q,10);
    En_Queue(q,20);
    En_Queue(q,30);
    Show_Queue(q);
    De_Queue(q);
    Show_Queue(q);
    Peek_Queue(q);
    free(q);
    return 0;
}




