#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 반복적인 탐색 함수 
TreeNode * search(TreeNode * node, int key){
    while(node != NULL){
        if(key == node->data) return node;
        else if(key < node->data) node = node->left;
        else node = node->right;
    }
    return NULL; // 탐색에 실패했을 경우 NULL 반환 
}

int main(void) {
    // BST를 만족하는 트리
    TreeNode valid3 = {3, NULL, NULL};
    TreeNode valid7 = {7, NULL, NULL};
    TreeNode valid12 = {12, NULL, NULL};
    TreeNode valid18 = {18, NULL, NULL};
    TreeNode valid5 = {5, &valid3, &valid7};
    TreeNode valid15 = {15, &valid12, &valid18};
    TreeNode validRoot = {10, &valid5, &valid15};
    TreeNode *root_1 = &validRoot;

    // BST를 만족하지 않는 트리
    TreeNode invalid3 = {3, NULL, NULL};
    TreeNode invalid12 = {12, NULL, NULL};
    TreeNode invalid11 = {11, NULL, NULL};
    TreeNode invalid18 = {18, NULL, NULL};
    TreeNode invalid5 = {5, &invalid3, &invalid12};
    TreeNode invalid15 = {15, &invalid11, &invalid18};
    TreeNode invalidRoot = {10, &invalid5, &invalid15};
    TreeNode *root_2 = &invalidRoot;

    int index = 0;
    printf("찾을 index value >> ");
    scanf("%d", &index);
    printf("root_1에서 index : %d를 찾습니다.\n", index);
    TreeNode *target_1 = search(root_1, index);
    printf((target_1 != NULL && target_1->data == index) ? ("%d 를 찾았습니다.\n") : ("index : %d를 root_1에서 찾지 못했습니다.\n"), index);

    printf("root_2에서 index : %d를 찾습니다.\n", index);
    TreeNode *target_2 = search(root_2, index);
    printf((target_2 != NULL && target_2->data == index) ? "%d 를 찾았습니다.\n" : "index : %d를 root_2에서 찾지 못했습니다.\n", index);

    return 0;
}

