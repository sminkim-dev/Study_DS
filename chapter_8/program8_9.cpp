#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <iostream>

using namespace std;

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
} TreeNode;
const int ARRAY_CAPACITY = 100;
int sort_arr[ARRAY_CAPACITY];

bool state = false;

// 순환적인 탐색 함수
TreeNode * search(TreeNode * node, int key){
    if(node == NULL) return NULL;
    if(key == node->data) return node;
    else if(key < node->data) return search(node->left, key);
    else return search(node->right, key);
}

// 재귀 호출 결과를 반환하는 탐색 함수
TreeNode * search_2(TreeNode * node, int key){
    if(node == NULL) return NULL;
    if(key == node->data) return node;
    if(key < node->data) return search_2(node->left, key);
    return search_2(node->right, key);
}

void inorder(TreeNode *root, int &index){
    if(root != NULL){
        inorder(root->left, index);
        printf("[%d]", root->data);
        if(index >= ARRAY_CAPACITY){
            throw std::out_of_range("중위 순회 배열의 크기를 초과했습니다.");
        }
        sort_arr[index++] = root->data;
        inorder(root->right, index);
    }
}

// 포인터에서는 배열 길이를 알 수 없으므로 실제 원소 수를 전달한다.
void sort(int *arr, int count){
    for(int end = count - 1; end > 0; end--){
        for(int i = 0; i < end; i++){
            if(arr[i] > arr[i + 1]){
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

// 중위 순회 결과가 엄격한 오름차순이면 중복 키가 없는 BST이다.
bool is_bst(const int *arr, int count){
    for(int i = 1; i < count; i++){
        if(arr[i - 1] >= arr[i]) return false;
    }
    return true;
}

// 정렬된 값을 중위 순회 순서로 넣어 트리 구조를 유지한다.
void update_tree(TreeNode *node, const int *arr, int &index){
    if(node == NULL) return;
    update_tree(node->left, arr, index);
    node->data = arr[index++];
    update_tree(node->right, arr, index);
}

TreeNode n1 = {12, NULL, NULL};
TreeNode n2 = {10, NULL, NULL};
TreeNode n3 = {9, &n1, &n2};
TreeNode n4 = {14, NULL, NULL};
TreeNode n5 = {15, NULL, NULL};
TreeNode n6 = {16, &n4, &n5};
TreeNode n7 = {18, &n3, &n6};
TreeNode *root = &n7;

int main(){
    int index = 0;

    printf("BST 확인 : ");
    inorder(root, index);
    cout << endl;
    printf("%s", is_bst(sort_arr, index) ? "Is BST" : "Isn't BST");
    printf("\n");

    for(int i = 0; i < 10; i++)printf("---");
    printf("\n");
    
    const int count = index;
    sort(sort_arr, count);
    index = 0;
    update_tree(root, sort_arr, index);
    index = 0;
    printf("BST 확인 : ");
    inorder(root, index);
    cout << endl;
    printf("%s", is_bst(sort_arr, index) ? "Is BST" : "Isn't BST");
    printf("\n");

    int target_index = 12;
    TreeNode * target = search_2(root, target_index);
    if(target != NULL) printf("찾는 값 : %d | 검색 결과 : %d", target_index, target->data);
    else printf("찾는 값 : %d | 검색 결과 : 존재하지 않습니다.", target_index);

    return 0;
}
