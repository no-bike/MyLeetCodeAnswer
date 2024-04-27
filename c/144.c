/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode* stack[100];
    int* ans = malloc(sizeof(int)*100);
    int top = 0;
    *returnSize = 0;
    stack[top++] = root;
    if(!root) return NULL;
    while(top){
        root = stack[--top];
        ans[(*returnSize)++] = root->val;
        if(root->right) stack[top++] = root->right;
        if(root->left) stack[top++] = root->left;
    }
    return ans;
}