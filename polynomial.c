#include<stdio.h>
#include<stdlib.h>
struct node {
float coffecient;
int exponent;
struct node *link;
};
struct node *new_insert(struct node *head,float coff,int expo);

void print_data(struct node *head)
{
if(head==NULL)
{
printf("linked list is empty\n");
}
struct node *ptr=NULL;
ptr=head;
int i=0;
while(ptr!=NULL)
{
//printf("coffecient of each node [%d]: %0.2f and exponent of each node [%d]: %d\n",i,ptr->coffecient,i,ptr->exponent);
printf("(%0.1f * x^%d)",ptr->coffecient,ptr->exponent);
i++;
ptr=ptr->link;
if(ptr!=NULL)
{
printf(" + ");
}
else
{
printf("\n");
}
}
}

struct node *create(struct node *head)
{
printf("enter the number of terms :");
int terms,i,exponent;
float coff;
scanf("%d",&terms);
for(i=0;i<terms;i++)
{
printf("enter the coffecient for term %d:",i+1);
scanf("%f",&coff);
printf("enter the exponent for term %d:",i+1);
scanf("%d",&exponent);
head=new_insert(head,coff,exponent);
}
return head;
}

struct node *new_insert(struct node *head,float coff,int expo)
{
struct node *newp=NULL;
newp=malloc(sizeof(struct node));
struct node *temp=NULL;
temp=head;
newp->coffecient=coff;
newp->exponent=expo;
newp->link=NULL;

if(head==NULL || expo > head->exponent)
{
newp->link=head;
head=newp;
}
else
{
temp=head;
while(temp->link!=NULL && temp->link->exponent > expo)
{
temp=temp->link;
}
newp->link=temp->link;
temp->link=newp;
}
return head;
}
 





int main()
{
struct node *head=NULL;
printf("enter the polynomial \n");
head=create(head);

print_data(head);
return 0;
}

