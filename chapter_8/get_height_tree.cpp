#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode n1 = {10, NULL, NULL};
TreeNode n2 = {11, NULL, NULL};
TreeNode n3 = {12, NULL, NULL};
TreeNode n4 = {13, NULL, NULL};
TreeNode n5 = {14, &n4, &n3};
TreeNode n6 = {15, &n1, &n2};
TreeNode n7 = {16, &n5, &n6};
TreeNode *root = &n7;

int get_node_count(TreeNode *root){
    int count = 0;
    if(root == NULL) return 0;
    count = 1 + get_node_count(root->left) + get_node_count(root->right);
    return count;
}

int get_leaf_count(TreeNode *root){
    int count = 0;
    if(root->left == NULL && root->right == NULL) return 1;
    else {
        count = get_leaf_count(root->left) + get_leaf_count(root->right);
    }
    return count;
}

int max(int a, int b){
    return (a > b) ? a : b;
}
int get_height(TreeNode *root){
    int height = 0;
    if(root == NULL) return 0;
    height = 1 + max(get_height(root->left), get_height(root->right));
    return height;
}
int main(){
    printf("node count : %d\n" , get_node_count(root));
    printf("leaf count : %d\n" , get_leaf_count(root));
    printf("tree height : %d\n" , get_height(root));

    return 0;
}
