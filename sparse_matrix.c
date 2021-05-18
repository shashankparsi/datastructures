#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node *prev;
int row;
int col;
int data;
struct node *next;
};

struct node *insertend(struct node *start, int row,int col,int data)
{
struct node *ptr=start;
struct node *temp=malloc(sizeof(struct node));
if(start==NULL)
{
printf("list is empty\n");
return start;
}
temp->prev=NULL;
temp->row=row;
temp->col=col;
temp->data=data;
temp->next=NULL;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=temp;
temp->prev=ptr;
return start;
}

void print_data(struct node *start)
{
struct node *ptr=start;
if(start==NULL)
{
printf("list is empty\n");
}
else
{
printf("\n row\t col\t and data\n");
while(ptr!=NULL)
{
printf("\n %d\t %d\t %d\n",ptr->row,ptr->col,ptr->data);
ptr=ptr->next;
}
}
}

void displaymatrix(struct node *start, int m, int n)
{
int i,j;
struct node *temp=start;
for(i=1;i<m;i++)
{
for(j=1;j<n;j++)
{
if(temp!=NULL && temp->row==i && temp->col==j)
{
printf("%d",temp->data);
temp=temp->next;
}
else
{
printf("0\t");
}
}
printf("\n");
}
}

int main()
{
struct node *head=NULL;
int i,j,m,n,data;
printf("enter the row size of the sparse matrix: ");
scanf("%d", &m);
printf("enter the col size of the sparse matrix :");
scanf("%d",&n);
for(i=1;i<=m;i++)
{
for(j=1;j<=n;j++)
{
printf("enter data:");
scanf("%d",&data);
if(data!=0)
{
head=insertend(head,i,j,data);
}
}
}
print_data(head);
displaymatrix(head,m,n);
return 0;
}

