// 이진트리의 3가지 순회방법

void inorder(TreeNode *root){
    if(root != NULL){
        inorder(root->left); //왼쪽서브트리 순회
        cout << root->data << " "; // 노브 방문
        inorder(root->right); //오른쪽서브트리 순회
    }
}

void preorder(TreeNode *root){
    if(root != NULL){
        cout << root->data << " "; // 노드 방문
        preorder(root->left); // 왼쪽서브트리 순회
        preorder(root->right); // 오른쪽 서브트리 순회
    }
}

void postorder(TreeNode *root){
    if(root != NULL){
        postorder(root->left); // 왼쪽 서브트리 방문
        postorder(root->right); // 오른쪽 서브트리 방문
        cout << root->data << " "; // 노드 방문 
    }
}

