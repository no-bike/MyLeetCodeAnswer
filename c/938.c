/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int SumBST(struct TreeNode* root, int low, int high){
    if(root == NULL) return 0;
    if(root->val < low) return SumBST(root->right,low,high);
    else if(root->val > high) return SumBST(root->left,low,high);
    else return root->val + SumBST(root->left,low,high) + SumBST(root->right,low,high);
}


int rangeSumBST(struct TreeNode* root, int low, int high) {
    int sum;
    sum = SumBST(root,low,high);
    return sum;
}