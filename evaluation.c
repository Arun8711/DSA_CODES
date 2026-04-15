#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int id;
    struct node *left;
    struct node *right;
}*node;
node create();
node insert(node root);
node delete_(node root,int data);
void inorder(node root);
void postorder(node root);
int main()
{
    node root=NULL;
    int choice,data;
    while(1)
    {
        printf("enter the choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:exit(0);
            break;
            case 1:root=insert(root);
            break;
            case 2:printf("enter the data :\n");
            scanf("%d",&data);
            root=delete_(root,data);
            break;
            case 3:inorder(root);
            break;
            case 4:postorder(root);
            break;
            default:printf("invalid choice:\n");
            break;
        }
    }
    return 0;

}
node create()
{
    node newnode=(node)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("memory allocation is failed:\n");
        return NULL;
    }
    printf("enter the data:\n");
    scanf("%d",&newnode->id);
    newnode->left=newnode->right=NULL;
    return newnode;
}
node insert(node root)
{
    node newnode=create();
    if(root==NULL)
    {
        root=newnode;
    }
    else{
        node cur=root,parent=NULL;
        while(cur!=NULL)
        {

            parent=cur;
            if(newnode->id<cur->id)
            {
                cur=cur->left;
            }
            else{
                cur=cur->right;
            }
        }
        if(newnode->id<parent->id)
        {
            parent->left=newnode;
        }
        else{
            parent->right=newnode;
        }
    }
    return root;
}
node delete_(node root,int data)
{
    if(root==NULL)
    {
        printf("tree is empty:\n ");
        return root;
    }
    else{
        node cur=root,parent=NULL;
        while(cur!=NULL&&data!=cur->id)
        {
            parent=cur;
            if(data<cur->id)
            {
                cur=cur->left;
            }
            else{
                cur=cur->right;
            }
        }
        if(cur==NULL)
        {
            printf("the data is not found:\n");
            return root;
        }
        if(cur->left!=NULL&&cur->right!=NULL)
        {
            node c=cur->right;
            node cp=c;
            while(c->left!=NULL)
            {
                cp=c;
                c=c->left;
            }
            cur->id=c->id;
            cur=c;
            parent=cp;
        }
        node child;
        if(cur->left!=NULL)
        {
            child=cur->left;
        }
        else{
            child=cur->right;
        }
        if(parent==NULL)
        {
            free(cur);
            return child;
        }
        if(parent->left==cur)
        {
            parent->left=child;
        }
        else{
            parent->right=child;
        }
        free(cur);
    }
    return root;
}
void inorder(node root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->id);
        inorder(root->right);
    }
}
void postorder(node root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->id);
    }
}
