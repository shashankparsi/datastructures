#include<stdio.h>
#include<stdlib.h>

struct node {
struct node *prev;
int data;
struct node *next;
};

void print_data(struct node *head)
{
struct node *ptr=head;
if(ptr==NULL)
{
printf("list is empty\n");
}
else
{
printf("list contents are:\n");
while(ptr!=NULL)
{
printf("%d\n",ptr->data);
ptr=ptr->next;
}
}
}

struct node *insertatbeg(struct node *head,int data)
{
struct node *temp=malloc(sizeof(struct node ));
temp->prev=NULL;
temp->data=data;
temp->next=NULL;
if(head==NULL)
{
printf("list is empty\n");
return temp;
}
temp->next=head;
head->prev=temp;
return temp;
}

struct node *insertatend(struct node *head,int data)
{
struct node *temp=malloc(sizeof(struct node ));
struct node *ptr=NULL;
ptr=head;
temp->prev=NULL;
temp->data=data;
temp->next=NULL;
if(head==NULL)
{
printf("list is empty\n");
return temp;
}
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=temp;
temp->prev=ptr;
return ptr;
}

struct node *delatbeg(struct node *head)
{
struct node *ptr=head,*temp=NULL;
if(ptr==NULL)
{
printf("list is empty\n");
return NULL;
}
temp=head;
ptr=ptr->next;
ptr->prev=NULL;
printf("node deleted is : %d\n",temp->data);
free(temp);
return ptr;
}

struct node *delatend(struct node *head)
{
struct node *ptr=head,*temp;
if(ptr==NULL)
{
printf("list is empty\n");
return NULL;
}
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
temp=ptr->prev;
temp->next=NULL;
printf("node deleted is : %d\n",ptr->data);
free(ptr);
return head;
}



int main()
{
struct node *head;
head=insertatbeg(head,10);
head=insertatend(head,20);
print_data(head);
head=delatbeg(head);
//print_data(head);
//head=delatend(head);
print_data(head);
return 0;
}
