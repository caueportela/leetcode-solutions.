#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    struct TreeNode* novo_no = malloc(sizeof(struct TreeNode));
    novo_no->val = val;
    novo_no->left = NULL;
    novo_no->right = NULL;

    if (root == NULL)
        return novo_no;

    struct TreeNode* temp = root;
    struct TreeNode* prev = NULL;

    while (temp != NULL) {
        prev = temp;
        if (val < temp->val)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if (val < prev->val)
        prev->left = novo_no;
    else
        prev->right = novo_no;

    return root;
}

void inorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void freeTree(struct TreeNode* root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int arr[] = {6, 3, 9, 1, 4, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct TreeNode* root = NULL;

    for (int i = 0; i < n; i++) {
        root = insertIntoBST(root, arr[i]);
    }

    printf(" ");
    inorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
