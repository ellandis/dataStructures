#include <stdio.h>
#include "bst.h"
#include "bstque.h"
#include <stdlib.h>

struct BST{
    bst* left;
    bst* right;
    int data;
};
bst* Create_BSTreeNode(){
    bst* node = malloc(sizeof(bst*));
    node->data = -1;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void Insert_Node(bst** root, int data){
    if((*root) == NULL){
        bst* newnode = Create_BSTreeNode();
        if(newnode == NULL){
            printf("Memory Error\n");
        }
        else{
            newnode->data = data;
            (*root) = newnode;
        }
    }
    else{
        if(data < (*root)->data){
            Insert_Node(&(*root)->left,data);
        }
        else if(data > (*root)->data){
            Insert_Node(&(*root)->right,data);
        }
    }
    //return (*root);
}
bst* Find_Max(bst* root){
    if(root == NULL){
        return NULL;
    }
    else if(root->right == NULL){
        return root;
    }
    else
        return Find_Max(root->right);
}
bst* Find_Min(bst* root){
    if(root == NULL){
        return NULL;
    }
    else if(root->left == NULL){
        return root;
    }
    else
        return Find_Min(root->left);
}
bst* Find_Node(bst* root,int data){
    if(root == NULL){
        return root;
    }
    if(data < root->data){
        return Find_Node(root->left,data);
    }
    else if(data > root->data){
        return Find_Node(root->right,data);
    }
    return root;
}
void Display_LevelOrder(bst* root){
    if(root == NULL){
        printf("Empty Tree\n");
        return;
    }
    bstque* q = Create_BstQue();
    bst* temp;
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
    Delete_BstQue(q);
}
bst* Delete_Node(bst* root, int data){
    bst* temp;
    if(root == NULL){
        printf("Element Not in Tree\n");
    }
    else if(data < root->data){
        root->left = Delete_Node(root->left,data);
    }
    else if(data > root->data){
        root->right = Delete_Node(root->right,data);
    }
    else{
        //if Node is found
        //replace with largest in left subtree
        if(root->left && root->right){
            temp = Find_Max(root->left);
            root->data = temp->data;
            root->left = Delete_Node(root->left,root->data);
        }
        else{
            //one child only
            temp = root;
            if(root->left == NULL){
                root = root->right;
            }
            if(root->right == NULL){
                root = root->left;
            }
            free(temp);
        }
    }
    return root;
}
bst* Find_Kth(bst* root, int kth, int count){
    //Looking for the kth smallest in the tree
    if(!root){
        return NULL;
    }
    bst* left = Find_Kth(root->left,kth,count);
    if(left){
        return left;
    }
    if(++count == kth){
        return root;
    }
    printf("%d ",root->data);
    return Find_Kth(root->right,kth,count);
}