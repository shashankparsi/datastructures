#include<stdio.h>
#include<stdlib.h>
struct node 
{
struct node *prev;
int data;
struct node *next;
};

struct node *addtoempty(int data)
{
struct node *temp=(struct node *)malloc(sizeof(struct node));
temp->prev=temp;
temp->data=data;
temp->next=temp;
return temp;
}

struct node *addatbeg(struct node *tail,int data)
{
struct node *newp=addtoempty(data);
if(tail==NULL)
{
return newp;
}
else
{
struct node *temp=tail->next;
newp->prev=tail;
newp->next=temp;
temp->prev=newp;
temp->next=newp;
return tail;
}
}

void print(struct node *tail)
{

if(tail==NULL)
{
printf("there are no nodes in the list..\n");
}
else
{
struct node *temp=tail->next;
do
{
printf("%d ",temp->data);
temp=temp->next;
}while(temp!=tail->next);
}
printf("\n");
}

struct node *addatend(struct node *tail,int data)
{
struct node *newp=addtoempty(data);
if(tail==NULL)
{
return newp;
}
else
{
struct node *temp=tail->next;
newp->next=temp;
newp->prev=tail;
tail->next=newp;
temp->prev=newp;
tail=newp;
return tail;
}
}

struct node *addatpos(struct node *tail,int data,int pos)
{
struct node *newp=addtoempty(data);
if(tail==NULL)
{
return newp;
}
struct node *temp=tail->next;
if(pos>1)
{
temp=temp->next;
pos--;
}
newp->prev=temp;
newp->next=temp->next;
temp->next->prev=newp;
temp->next=newp;
if(temp==tail)
{
tail=tail->next;
}
return tail;
}

struct node *delfirst(struct node *tail)
{
if(tail==NULL)
{
return tail;
}
struct node *temp=tail->next;
if(temp==tail)
{
free(temp);
temp=NULL;
return tail;
}
tail->next=temp->next;
temp->next->prev=tail;
return tail;
}

struct node *dellast(struct node *tail)
{
struct node *temp;
if(tail==NULL)
{
return tail;
}
if(tail==temp)
{
free(tail);
tail=NULL;
return tail;
}
//struct node *temp;
temp=tail->prev;
temp->next=tail->next;
tail->next->prev=temp;
free(tail);
tail=temp;
return tail;
}

int main()
{
struct node *tail=NULL;
tail=addtoempty(2);
tail=addatbeg(tail,1);
tail=addatend(tail,3);
tail=addatpos(tail,4,2);
tail=delfirst(tail);
tail=dellast(tail);
print(tail);
return 0;
}


