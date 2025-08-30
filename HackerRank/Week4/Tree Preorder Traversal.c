#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

void preOrder(struct node* root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
