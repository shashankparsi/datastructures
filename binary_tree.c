#include<stdio.h>
#include<stdlib.h>
struct node 
{
struct node *left;
int data;
struct node *right;
};

/*pre order method:
1. visit the root node
2. recursively visit the left subtree in pre-order
3. recursively visit the right subtree in pre-order
i,e root->left->right
*/
 
void preorder(struct node *root)
{
if(root!=NULL)
{
printf("\n %d\t",root->data);
preorder(root->left);
preorder(root->right);
}
}

/*in-order method :
1. recursively visit the left sub tree
2. visit the root node
3. recursively visit the right sub tree
i,e left->root->right */

void inorder(struct node *root)
{
if(root!=NULL)
{
inorder(root->left);
printf("\n %d\t",root->data);
inorder(root->right);
}
}
/* post order method:
1. recursively visit the left subtree
2. recursively visit the right sub tree
3. visit root node 
i,e right->left->root */

void postorder(struct node *root)
{
if(root!=NULL)
{
postorder(root->left);
postorder(root->right);
printf("\n %d\t",root->data);
}
}


struct node *create()
{
int data;
struct node *ptr=NULL;
printf("enter data (enter -1 for no data):");
scanf("%d",&data);
if(data==-1)
{
return NULL;
}
else
{
ptr=malloc(sizeof(struct node));
ptr->data=data;
printf("\n enter left child of %d :",data);
ptr->left=create();
printf("\n enter right child of %d :",data);
ptr->right=create();
}
return ptr;
} 


 struct node *createbst(struct node *root,int data)
{
struct node *cur,*prev,*temp;
temp=malloc(sizeof(struct node));
temp->data=data;
temp->left=NULL;
temp->right=NULL;
if(root==NULL)
{
return temp;
}
cur=root;
while(cur!=NULL)
{
prev=cur;
if(data < cur->data)
{
cur=cur->left;
}
else
{
cur=cur->right;
}
if(prev->data > data)
{
prev->left=temp;
}
else
{
prev->right=temp;
}
}
return root;
} 



int main()
{
struct node *head=NULL;
head=createbst(head,5);
head=createbst(head,4);
head=createbst(head,3);
head=createbst(head,2);
head=createbst(head,100);
printf("\n the pre-order traversal is :");
preorder(head);
printf("\n the in-order traversal is :");
inorder(head);
printf("\n the post-order traversal is :");
postorder(head);
return 0;
}
