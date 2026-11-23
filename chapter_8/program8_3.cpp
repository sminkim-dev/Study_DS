#include <iostream>
#include <stdlib.h>
#include <memory.h>

using namespace std;

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

//      15
//  4       20
//1     16      25
TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;

// 중위 순회
void inorder(TreeNode *root){
    if(root != NULL){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// 전위 순회
void preorder(TreeNode *root){
    if(root != NULL){
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// 후위 순회
void postorder(TreeNode *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main(){

    cout << "inorder = ";
    inorder(root);
    cout << endl;

    cout << "preorder = ";
    preorder(root);
    cout << endl;

    cout << "postorder = ";
    postorder(root);
    cout << endl;
    return 0;
}
