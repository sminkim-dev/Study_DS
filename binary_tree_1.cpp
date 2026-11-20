#include <iostream>
//#include <queue>
#include <stdlib.h>
#include <cstring>
#include <climits>
//#include <algorithm>

using namespace std;

typedef struct NodeType {
    int data;
    struct NodeType *left;
    struct NodeType *right;
} NodeType;

NodeType *new_nodeType(int data) {
    NodeType * n = (NodeType *)malloc(sizeof(NodeType));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

NodeType *input(int *data, int cur, int max_index) {
    if(cur > max_index) return NULL;
    if(data[cur] == INT_MIN) return NULL;

    NodeType * node = new_nodeType(data[cur]);
    node->left = input(data, cur * 2, max_index);
    node->right = input(data, cur * 2 + 1, max_index);

    return node;
}

void inorder(NodeType * root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";

    inorder(root->right);
}

void valid(NodeType * root, int *result, int & index){
    if(root == NULL) return;

    valid(root -> left, result, index);
    result[index++] = root->data;
    cout << root->data << " ";
    valid(root -> right, result, index);
}

bool valid_2(NodeType * root, int min, int max){
    if(root == NULL) return true;
    if(root->data < min || root->data > max) return false;
    return valid_2(root->left, min, root->data) 
        && valid_2(root->right, root->data, max); 
}

void check(int & index, int *result, bool & bst){
    for(int i = 1; i < index; i++){
        if(result[i] < result[i - 1]){
            bst = false;  
            break;
        }
    }
    if(bst) cout << "BST" << endl; else cout << "Not a BST" << endl;
}

int main() {
    int a[] = {0, 3, 1, 5, INT_MIN, INT_MIN, 4, 6};
    //int a_size = 7;
    int a_size = sizeof(a) / sizeof(a[0]);

    int b[] = {0, 3, 9, 20, INT_MIN, INT_MIN, 15, 7};
    int b_size = sizeof(b) / sizeof(b[0]);

    NodeType * tree1 = input(a, 1, a_size);
    inorder(tree1);
    
    cout << endl;
    NodeType * tree2 = input(b, 1, b_size);
    inorder(tree2); 
    cout << endl;

    cout << endl;
    int result[100];
    int index;
    bool bst = true;

    index = 0;
    valid(tree1, result, index);
    check(index, result, bst);

    index = 0;
    valid(tree2, result, index);
    bst = true;
    check(index, result, bst);

    cout << "--------------------------------------------" << endl;
    
    if(valid_2(tree1, INT_MIN, INT_MAX)) cout << "BST" << endl; else cout << "Not a BST" << endl;
    if(valid_2(tree2, INT_MIN, INT_MAX)) cout << "BST" << endl; else cout << "Not a BST" << endl;

    return 0;
}