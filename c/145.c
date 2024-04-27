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
#define Maxsize 100
struct Stack
 {
     struct TreeNode *data;
     int tag;
 }S[Maxsize];
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    typedef struct TreeNode TNode;
    int i=-1;
    TNode *P;
    static int res[Maxsize];
    int k=0;
    if(root==NULL)
    {
        *returnSize=0; //一定要有这句,强烈感觉到LeetCode对底层C语言不太友好：否则当输入是NULL时，报错：runtime error: load of null pointer of type 'int'
        return NULL;
    }
    P=root;
    do{
        while(P)
        {
            ++i;
            S[i].data=P;
            S[i].tag=0;
            P=P->left;
        }
        while(i>=0&&S[i].tag==1)
        {
            P=S[i].data;
            //将val存入数组中
            res[k++]=S[i].data->val;
            --i;
        }
        if(i>=0)
        {
            S[i].tag=1;
            P=S[i].data->right;
        }
    }while(i>=0);
    *returnSize=k;
    return res;
}