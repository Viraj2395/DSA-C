#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

void preOrder(struct node* root){
    if(root != NULL){
        printf("%d  ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = 1;
    p->left = NULL;
    p->right = NULL;
    
    struct node* p1;
    p1 = (struct node*)malloc(sizeof(struct node));
    p1->data = 8;
    p1->left = NULL;
    p1->right = NULL;

    struct node* p2;
    p2 = (struct node*)malloc(sizeof(struct node));
    p2->data = 7;
    p2->left = NULL;
    p2->right = NULL;

    struct node* p3;
    p3 = (struct node*)malloc(sizeof(struct node));
    p3->data = 5;
    p3->left = NULL;
    p3->right = NULL;

    struct node* p4;
    p4 = (struct node*)malloc(sizeof(struct node));
    p4->data = 2;
    p4->left = NULL;
    p4->right = NULL;

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    preOrder(p);

    return 0;
}