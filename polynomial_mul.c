#include<stdio.h>
#include<stdlib.h>
struct node {
float coffecient;
int exponent;
struct node *link;
};
struct node *new_insert(struct node *head,float coff,int expo); // forward declaration of insert function
struct node *addterm(struct node *res,float coff,int expo); 

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
printf("enter the number of terms for polynomial one :");
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


struct node *create_new(struct node *head1)
{
printf("enter the number of terms for polynomial 2 :");
int terms,i,exponent;
float coff;
scanf("%d",&terms);
for(i=0;i<terms;i++)
{
printf("enter the coffecient for term %d:",i+2);
scanf("%f",&coff);
printf("enter the exponent for term %d:",i+2);
scanf("%d",&exponent);
head1=new_insert(head1,coff,exponent);
}
return head1;
}

struct node *poly_mul(struct node *head , struct node *head1)
{
struct  node *first=NULL,*second=NULL,*res=NULL;
for(first=head;first!=NULL;first=first->link)
{
for(second=head1;second!=NULL;second=second->link)
{
res=addterm(res,first->coffecient * second->coffecient,first->exponent + second->exponent);
}
}
return res;
}

struct node *addterm(struct node *res,float coff, int expo)
{
struct node *temp=NULL,*curr=NULL;
int flag=0;
temp=malloc(sizeof(struct node));
temp->coffecient=coff;
temp->exponent=expo;
temp->link=NULL;
if(res==NULL)
{
return temp;
}
curr=res;
while(curr!=NULL)
{
if(curr->exponent==expo)
{
curr->coffecient=curr->coffecient+coff;
flag=1;
}
curr=curr->link;
}
if(flag==0)
{
curr=res;
while(curr->link!=NULL)
{
curr=curr->link;
}
curr->link=temp;
}
return res;
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
struct node *head=NULL,*head1=NULL,*res=NULL;
printf("enter the polynomial \n");
head=create(head);
head1=create_new(head1);
print_data(head);
print_data(head1);
printf("multiplication of two polynomials is :\n");
res=poly_mul(head,head1);
print_data(res);
return 0;
}

