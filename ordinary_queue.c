#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int front=-1,rear=-1;
int queue[SIZE];

void enqueue(int item)
{
if(rear==SIZE-1)
{
printf("the queue is empty\n");
}
else
{
rear=rear+1;
queue[rear]=item;
if(front==-1)
{
front=front+1;
}
}
}

void dequeue()
{
int del;
if(front==-1 || front > rear)
{
printf("queue is empty\n");
}
else
{
del=queue[front];
printf("deleted element is : %d\n",del);
if(front==rear)
{
front=-1;
rear=-1;
}
else {
	front=front+1;
}
}
}

void display()
{
if(front==-1)
{
printf("the queue is empty\n");
}
else
{
printf("\n elements of queue are:\n");
int i;
for(i=front;i<=rear;i++)
{
printf("%d\t", queue[i]);
}
}
}

int main()
{
int item,ch;
for(; ;)
{
printf("\n 1. Insert");
printf("\n 2. Delete");
printf("\n 3. Display");
printf("\n 4. exit");
printf("\n enter your choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1 : printf("\n enter the element to be inserted to the queue :");
	 scanf("%d",&item);
	 enqueue(item);
	 break;
case 2: dequeue();
	break;
case 3 : display();
	break;
default: exit(0);
}
}
return 0;
}
