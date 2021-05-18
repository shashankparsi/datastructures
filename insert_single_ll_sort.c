/* c program to insert an element on sorted linked list in ascending/decending order */
#include<stdio.h>
#include<stdlib.h>

struct node 
{
int data;
struct node* link;
};

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
printf("data of each node[%d]: %d\n",i,ptr->data);
i++;
ptr=ptr->link;
}
}

struct node *addatbeg(struct node *head,int data)
{
if(head==NULL)
{
printf("linked list is empty\n");
}
struct node *temp;
temp=malloc(sizeof(struct node*));
temp->data=data;
temp->link=NULL;
struct node *ptr=head;
temp->link=ptr;
ptr=temp;
return temp;
}

struct node *insert(struct node *head,int data)
{
if(head==NULL)
{
printf("linked list is empty\n");
}
struct node *temp=NULL;
struct node *newp=malloc(sizeof(struct node));
temp=head;
newp->data=data;
newp->link=NULL;
int key=data;
if(head->link==NULL || key < head->data)
{
newp->link=head;
head=newp;
} 
else
{
temp=head;
while(temp->link!=NULL && temp->link->data < key)
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
head=(struct node *)malloc(sizeof(struct node));
head->data=500;
head->link=NULL;
head=addatbeg(head,400);
head=addatbeg(head,300);
head=addatbeg(head,200);
head=insert(head,325);
print_data(head);

return 0;
}
