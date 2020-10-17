#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
#include "avlque.h"


struct AVL{
    avl* left;
    avl* right;
    int data;
    int height;
};
avl* Create_Avlnode(){
    avl* node = malloc(sizeof(avl*));
    node->data = -1;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    return node;
}
int Height(avl* root){
    if(root == NULL)
        return -1;
    else
        return root->height;
}
avl* Single_Rotate_Left(avl* x){
    avl* w = x->left;
    x->left = w->right;
    w->right = x;
    x->height = max(Height(x->left),Height(x->right)) + 1;
    w->height = max(Height(w->left),x->height) + 1;
    return w;
}
avl* Single_Rotate_Right(avl* w){
    avl* x = w->right;
    w->right = x->left;
    x->left = w;
    w->height = max(Height(w->right),Height(w->left)) + 1;
    x->height = max(Height(x->right),w->height) + 1;
    return x;
}
avl* Double_Rotate_Left(avl* z){
    z->left = Single_Rotate_Right(z->left);
    return Single_Rotate_Left(z);
}
avl* Double_Rotate_Right(avl* z){
    z->right = Single_Rotate_Left(z->right);
    return Single_Rotate_Right(z);
}
//insertion is same as BST just check balance each time
avl* Insert_Node(avl* root, avl* parent, int data){
    parent = root;
    if(root == NULL){
        root = Create_Avlnode();
        if(root == NULL){
            printf("Memory Error\n");
        }
        else{
            root->data = data;
        }
    }
    else if(data < root->data){
        root->left = Insert_Node(root->left,parent,data);
        if((Height(root->left) - Height(root->right)) == 2){
            if(data < root->left->data){
                root = Single_Rotate_Left(root);
            }
            else{
                root = Double_Rotate_Left(root);
            }
        }
    }
    else if(data > root->data){
        root->right = Insert_Node(root->right,parent,data);
        if((Height(root->right) - Height(root->left)) == 2){
            if(data > root->right->data){
                root = Single_Rotate_Right(root);
            }
            else{
                root = Double_Rotate_Right(root);
            }
        }
    }
    int x = Height(root->left);
    int y = Height(root->right);
    root->height = max(x,y) + 1;
    return root;
}
int max(int x, int y){
    return x > y ? x:y;
}
void Display_LevelOrder(avl* root){
    if(root == NULL){
        printf("Empty Tree\n");
        return;
    }
    avlque* q = Create_AvlQue();
    avl* temp;
    int level;
    Enqueue(q,root);
    while(!Is_Empty(q)){
        level = Que_Size(q);
        while(level > 0){
            temp = Dequeue(q);
            printf("%d ", temp->data);
            if(temp->left){
                Enqueue(q,temp->left);
            }
            if(temp->right){
                Enqueue(q,temp->right);
            }
            level--;
        }
        printf("\n");
    }
    Delete_AvlQue(q);
}