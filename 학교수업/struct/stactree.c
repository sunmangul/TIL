#include<stdio.h>
#define SIZE 100
typedef struct TreeNode {
    int data;
    struct TreeNode* left, *right;
}TreeNode;
TreeNode* stack[SIZE];
int top = -1;

void push(TreeNode* p) {
    if (top < SIZE - 1)
        stack[++top] = p;
}
TreeNode* pop() {
    TreeNode *p = NULL;
    if (top >= 0)
        p = stack[top--];
    return p;
}
void order(TreeNode* root) {    
    while (1) {  // 중위순회
        for (; root; root=root->left)
            push(root);
        root = pop();
        if (!root) break;
        printf("%d ", root->data);
        root = root->right;
    }
}

TreeNode n1 = { 1,NULL, NULL };
TreeNode n2 = { 4,&n1,NULL };
TreeNode n3 = { 16, NULL,NULL };
TreeNode n4 = { 25,NULL, NULL };
TreeNode n5 = { 20,&n3,&n4 };
TreeNode n6 = { 15,&n2,&n5 };
TreeNode* root = &n6;

int main() {
    printf("inorder : ");
    order(root);
    printf("\n");
    return 0;
}