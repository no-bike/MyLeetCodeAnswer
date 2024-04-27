/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* replaceValueInTree(struct TreeNode* root) {
   root->val = 0;
   struct TreeNode* quene[100000];
   int front,rear,quenesize,i;
   long levelsum[100000];
   int level = 0;
   front = 0;
   rear = 0;
   struct TreeNode* temp;
   quene[rear++] = root;
   while(rear != front){
       quenesize = rear - front;
       levelsum[level] = 0;
       while(quenesize-- ){
           temp = quene[front++];
           if(temp->left != NULL) quene[rear++] = temp->left;
           if(temp->right != NULL) quene[rear++] = temp->right;
           levelsum[level] += temp->val;
       }
       ++level;
   }

   front = 0;
   rear = 1;
   level = 0;
   while(rear != front){
       quenesize = rear - front;
       while(quenesize-- ){
           temp = quene[front++];
           if(temp->left != NULL && temp->right != NULL){
               rear += 2;
               temp->left->val = levelsum[level+1] - temp->left->val - temp->right->val;
               temp->right->val = temp->left->val;
           }
           if(temp->left != NULL &&temp->right == NULL) {
               ++rear;
               temp->left->val = levelsum[level+1] - temp->left->val;
           }
           if(temp->left == NULL &&temp->right != NULL){
               ++rear;
               temp->right->val = levelsum[level+1] - temp->right->val;
           }
           levelsum[level] += temp->val;
       }
       ++level;
   }
   return root;
   
}