#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *link;
};


void count_nodes(struct node *head)
{
int count=0;
if(head==NULL)
{
printf("linked list is empty\n");
}
struct node *ptr=NULL;
ptr=head;
while(ptr!=NULL)
{
count++;
ptr=ptr->link;
}
printf("number of nodes=%d\n",count);
}

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

void addatend(struct node *head,int data)
{
if(head==NULL)
{
printf("linked list is empty\n");
}
struct node *temp=NULL;
temp=malloc(sizeof(struct node*));
temp->data=data;
temp->link=NULL;
struct node *ptr=head;
while(ptr->link!=NULL)
{
ptr=ptr->link;
}
ptr->link=temp;
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

void addatpos(struct node *head,int data,int pos)
{
if(head==NULL)
{
printf("linked list is empty\n");
}
struct node *temp=NULL;
temp=malloc(sizeof(struct node*));
temp->data=data;
temp->link=NULL;
struct node *ptr=head;
pos--;
while(pos!=1)
{
ptr=ptr->link;
pos--;
}
temp->link=ptr->link;
ptr->link=temp;
}


void sort(struct node *head)
{
if(head==NULL)
{
printf("linked list is empty\n");
}
int temp;
struct node *ptr=head;
struct node *ptr1=head->link;
while(ptr->link!=NULL)
{
if(ptr->data > ptr1->data)
{
ptr->data^=ptr1->data^=ptr->data^=ptr1->data;
}
ptr1=ptr1->link;
ptr=ptr->link;
printf("%d",ptr->data);
ptr=ptr->link;
}
}

struct node *delfirstnode(struct node *head)
{
if(head==NULL)
{
printf("linked list is empty\n");
}
struct node *ptr=NULL;
ptr=head;
head=head->link;
free(ptr);
return head;
}

struct node *dellast(struct node *head)
{
if(head==NULL)
{
printf("linked list is empty\n");
}
else if (head->link==NULL)
{
free(head);
return head;
head=NULL;
}
else
{
struct node *temp=head;
struct node *temp2=head;
while(temp->link!=NULL)
{
temp2=temp;
temp=temp->link;
}
temp2->link=NULL;
free(temp);
temp=NULL;
}
return head;
}

void del_last_node_using_single_pointer(struct node *head)
{
if(head==NULL)
{
printf("linked list is empty\n");
}
else if (head->link==NULL)
{
free(head);
return head;
head=NULL;
}
else
{
struct node *temp=NULL;
temp=head;
while(temp->link!=NULL)
{
temp=temp->link;
}
free(temp->link);
temp->link=NULL;
}
}

void delatpos(struct node **head,int position)
{
struct node *previous=*head;
struct node *current=*head;
if(*head==NULL)
{
printf("linked list is empty\n");
}
else if(position==1)
{
*head=current->link;
free(current);
current=NULL;
}
else
{
while(position!=1)
{
previous=current;
current=current->link;
position--;
}
previous->link=current->link;
free(current);
current=NULL;
}
}
struct node *dellist(struct node *head)
{
struct node *temp=head;
while(temp!=NULL)
{
temp=temp->link;
free(head);
head=temp;
}
return head;
if(head==NULL)
{
printf("linked list deleted successfully\n");
return 0;
}
}

struct node *reverse(struct node *head)
{
struct node *prev=NULL;
struct node *next=NULL;
while(head!=NULL)
{
next=head->link;
head->link=prev;
prev=head;
head=next;
}
head=prev;
return head;
}

int main()
{
struct node *head=NULL;
head=(struct node *)malloc(sizeof(struct node));
head->data=100000;
head->link=NULL;
struct node *current=(struct node*)malloc(sizeof(struct node*));
current->data=200;
current->link=NULL;
head->link=current;
addatend(head,300);
head=addatbeg(head,50);
addatpos(head,1000,2);
//sort(head);
count_nodes(head);
print_data(head);
//printf("data after sorting:\n");
//sort(head);
//print_data(head);
head=delfirstnode(head);
printf("after deleting first node:\n");
count_nodes(head);
print_data(head);
head=dellast(head);
printf("after deleting last node:\n");
count_nodes(head);
print_data(head);
//printf("deleting last node using single pointer\n");
//del_last_node_using_single_pointer(head);
//count_nodes(head);
//print_data(head);
delatpos(&head,2);
count_nodes(head);
print_data(head);
printf("deleting complete list:\n");
//head=dellist(head);
//count_nodes(head);
//print_data(head);
head=reverse(head);
count_nodes(head);
print_data(head);
return 0;

}
