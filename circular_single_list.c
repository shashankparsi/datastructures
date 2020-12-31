#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
struct node 
{
int data;
struct node *next;
};

struct node* circular_list(int data)
{
struct node *tmp;
tmp=(struct node*)malloc(sizeof(struct node));
tmp->data=data;
tmp->next=tmp;
return tmp;
}

struct node* addatbeg(struct node *tail,int data)
{
struct node *newp=(struct node*)malloc(sizeof(struct node));
newp->data=data;
newp->next=tail->next;
tail->next=newp;
return tail;
}
void print(struct node *tail)
{
if(tail==NULL)
{
printf("there are no nodes in the list... good bye\n");
}
else
{
struct node *p;
p=tail->next;
do
{
printf("%d",p->data);
p=p->next;
printf("\n");
}while(p!=tail->next);
}
}
struct node *addatend(struct node *tail,int data)
{
struct node *p=(struct node *)malloc(sizeof(struct node));
p->data=data;
p->next=NULL;
p->next=tail->next;
tail->next=p;
tail=tail->next;
return tail;
}
struct node *addafterpos(struct node *tail,int data,int pos)
{
struct node *p;
p=tail->next;
while(pos>1)
{
p=p->next;
pos--;
}
struct node *newp=(struct node *) malloc(sizeof(struct node));
newp->data=data;
newp->next=NULL;
newp->next=p->next;
p->next=newp;
if(p==tail)
{
tail=tail->next;
}
return tail;
}

struct node *create_list(struct node *tail)
{
int data,i,n;
printf("enter the number of nodes in the list:");
scanf("%d",&n);
if(n==0)
{
return tail;
}
printf("enter the data of node1:");
scanf("%d",&data);

tail=circular_list(data);

for(i=1;i<n;i++)
{
printf("enter the data of node %d : ", i+1);
scanf("%d",&data);
tail=addatend(tail,data);
}
return tail;
}

struct node *delfirst(struct node *tail)
{
if(tail==NULL)
{
return tail;
}
if(tail->next==tail)
{
free(tail);
tail=NULL;
return tail;
}

struct  node *temp;
temp=tail->next;
tail->next=temp->next;
free(temp);
temp=NULL;
return tail;
}

struct node *dellast(struct node *tail)
{
if(tail==NULL)
{
return tail;
}
if(tail->next==tail)
{
free(tail);
tail=NULL;
return tail;
}
struct node *tmp;
tmp=tail->next;
while(tmp->next!=tail)
{
tmp=tmp->next;
}
tmp->next=tail->next;
free(tail);
tail=tmp;
return tail;
}

struct node *delinter(struct node *tail,int pos)
{
if(tail==NULL)
{
return tail;
}
struct node *temp=tail->next;
if(tail->next==tail)
{
free(tail);
tail=NULL;
return tail;
}
//struct node *temp;
//temp=tail->next;
while(pos>2)
{
temp=temp->next;
pos--;
}

struct node *temp2=temp->next;
temp->next=temp2->next;
if(temp2==tail)
{
tail=temp;
}
free(temp2);
temp2=NULL;
return tail;
}

void count_elements(struct node *tail)
{
int count=0;
struct node *temp=tail->next;
while(temp!=tail)
{
count++;
temp=temp->next;
}
count++;
printf("number of elements are: %d\n",count);
}


int main()
{
struct node *tail;
/*int data=33;
struct node *tail;
tail=circular_list(data);
printf("data: %d\n",tail->data);

//tail=addatbeg(tail,data);
printf("enter the data to be inserted at node1: ");
scanf("%d", &data);
tail=addatbeg(tail,data);
printf("data inserted at begginning of list: %d\n",tail->data);

printf("enter data to be inserted at end of list:");
scanf("%d",&data);
tail=addatend(tail,data);
printf("data inserted at end of list is: %d\n",tail->data);
tail=addafterpos(tail,100,2);

printf("elements in list are : ");
print(tail);*/
tail=create_list(tail);
print(tail);
printf("deleting first element from the list\n");
tail=delfirst(tail);
printf("elements after deleting first element\n");
print(tail);
printf("deleting last element in list \n");
tail=dellast(tail);
printf("elements after deleting last element\n");
print(tail);
int pos;
printf("enter the position u want to del the node:");
scanf("%d",&pos);
//int posi=4;
tail=delinter(tail,pos);
printf("elements after del the node %d are \n:",pos);
print(tail);
count_elements(tail);
return 0;
}


