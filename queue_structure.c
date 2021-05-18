#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct queue
{
int front,rear;
int queue[SIZE];
};

void enqueue(struct queue *q,int item)
{
if(q->rear==SIZE-1)
{
//q->rear=(q->rear+1)%SIZE;
printf("\n queue is full\n");
}
else
{
q->rear=q->rear+1;
q->queue[q->rear]=item;
if(q->front==-1)
{
q->front=q->front+1;
}
}
}

void dequeue(struct queue *q)
{
if(q->front==-1)
{
printf("\n queue is empty\n");
}
else
{
int del;
del=q->queue[q->front];
printf("deleted element is : %d\n",del);
if(q->front==q->rear)
{
q->front=-1;
q->rear=-1;
}
q->front=q->front+1;
}
}

void display(struct queue *q)
{
if(q->front==-1)
{
printf("\n queue is empty\n");
}
else
{
int i;
printf("elements of queue :");
for(i=q->front;i<=q->rear;i++)
{
printf("%d\t",q->queue[i]);
}
}
}
int main()
{
struct queue q;;
q.front=-1;
q.rear=-1;
int choice,item;
for(; ; )
{
printf("\n 1.Insert\n");
printf(" 2. Delete \n");
printf(" 3. Display\n");
printf("4. Exit\n");
printf("enter your choice :");
scanf("%d",&choice);
switch(choice)
{
case 1 : printf(" enter element to be inserted : ");
	scanf("%d",&item);	
	enqueue(&q,item);
	break;
case 2 : dequeue(&q);
	break;
case 3: display(&q);
	break;
default : exit(0);
}
}
return 0;
}


