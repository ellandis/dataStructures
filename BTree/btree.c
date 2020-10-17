#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "btree.h"
#include "dqueue.h"

struct BTree{
    int data;
    bt *left;
    bt *right;
};
bt* Create_BTreenode(){
    bt* root = malloc(sizeof(bt));
    root->data = -1;
    root->left = NULL;
    root->right = NULL;
    return root;
}

/* this is for a BST but can be used on a BT
bt* Insert_Node(bt* root,int data){
    if(root == NULL){
        bt* newnode = Create_BTreenode();
        if(newnode == NULL){
            printf("Memory Error\n");
        }
        else{
            newnode->data = data;
            root = newnode;
        }
    }
    else{
        if(data < root->data){
            root->left = Insert_Node(root->left,data);
        }
        else if(data > root->data){
            root->right = Insert_Node(root->right,data);
        }
    }
    return root;
}*/
void Insert_Node(bt** root, int data){
    dque* q = Create_DQueue();
    bt* temp, *newnode = Create_BTreenode();
    newnode->data = data;
    if(!newnode){
        printf("Memory Error\n");
        return;
    }
    if(!(*root)){
        (*root) = newnode;
        return;
    }
    Enqueue(q,(*root));
    while (!Is_Empty(q))
    {
        temp = Dequeue(q);
        if(temp->left)
            Enqueue(q,temp->left);
        else{
            temp->left = newnode;
            Delete_DQueue(q);
            return;
        }
        if(temp->right)
            Enqueue(q,temp->right);
        else{
            temp->right = newnode;
            Delete_DQueue(q);
            return;
        }
    }
    Delete_DQueue(q);
} 
int Find_Node(bt* tree, int data){
    int temp;
    if(tree == NULL){
        return 0;
    }
    else{
        if(data == tree->data){
            return 1;
        }
        else{
            temp = Find_Node(tree->left,data);
            if(temp != 0)
                return temp;
            else{
                return (Find_Node(tree->right,data));
            }
        }
        return 0;
    }
    
}
void Display_LevelOrder(bt* root){
    dque *q = Create_DQueue();
    bt* temp = root; bt* tempr = root;
    int level;
    Enqueue(q,root);
    while(!Is_Empty(q)){
        level = Que_Size(q);
        while (level > 0)
        {
            temp = Dequeue(q);
            printf("%d ",temp->data);
            if(temp->left != NULL){
                Enqueue(q,temp->left);
            }
            if(temp->right != NULL){
                Enqueue(q,temp->right);
            }
            level--;
        }
        printf("\n");
    }
    Delete_DQueue(q);
}
void Display_PreOrder(bt* root){
    if(root){
        printf("%d ",root->data);
        Display_PreOrder(root->left);
        Display_PreOrder(root->right);
    }
}
void Display_InOrder(bt* root){
    if(root){
        Display_InOrder(root->left);
        printf("%d ",root->data);
        Display_InOrder(root->right);
    }
}
void Display_PostOrder(bt* root){
    if(root){
        Display_PostOrder(root->left);
        Display_PostOrder(root->right);
        printf("%d ",root->data);
    }
}
void Delete_Tree(bt* tree){
    if(tree == NULL){
        return;
    }
    Delete_Tree(tree->left);
    Delete_Tree(tree->right);
    free(tree);
}
int Find_Max(bt* root){
    bt* temp;
    int max = -1;
    dque* q = Create_DQueue();
    Enqueue(q,root);
    while (!Is_Empty(q)){
        temp = Dequeue(q);
        if(max < temp->data){
            max = temp->data;
        }
        if(temp->left){
            Enqueue(q,temp->left);
        }
        if(temp->right){
            Enqueue(q,temp->right);
        }
    }
    Delete_DQueue(q);
    return max;   
}
int Find_Height(bt* root){
    int height = 0;
    dque* q = Create_DQueue();
    if(root == NULL)return 0;
    Enqueue(q,root);
    Enqueue(q,NULL);
    while(!Is_Empty(q))
    {
        root = Dequeue(q);
        if(root == NULL){
            if(!Is_Empty(q))
                Enqueue(q,NULL);
            height++;
        }
        else
        {
            if(root->left)
                Enqueue(q,root->left);
            if(root->right)
                Enqueue(q,root->right);
        }
    }
    return height;
}
bt* Deepest_Node(bt* root){
    dque* q = Create_DQueue();
    bt* temp;
    if(!root)return NULL;
    Enqueue(q,root);
    while(!Is_Empty(q)){
        temp = Dequeue(q);
        if(temp->left)
            Enqueue(q,temp->left);
        if(temp->right)
            Enqueue(q,temp->right);
    }
    Delete_DQueue(q);
    printf("Deepest Node in the Tree is: %d\n",temp->data);
    return temp;
}
int Add(bt* root){
    if(root == NULL){
        return 0;
    }
    else{
        return (root->data + Add(root->left) + Add(root->right));
    }
}