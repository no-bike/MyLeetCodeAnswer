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
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
*returnSize = 0;
 struct TreeNode* stack[100];
    int top = 0;
    struct TreeNode* temp = root;
    int* ans = (int*)malloc(sizeof(int)*100);
    *returnSize = 0;
    while(temp||top > 0 ){
        while(temp){
            stack[top++] = temp;
            temp = temp->left;
        }
            temp = stack[--top];
            ans[(*returnSize)++] = temp->val;
            temp = temp->right;
    }
    return ans;
}