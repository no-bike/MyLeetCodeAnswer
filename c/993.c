/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isCousins(struct TreeNode* root, int x, int y) {
    int flag,front,rear,centnum;
    //层序遍历
    struct TreeNode* quene[100];
    struct TreeNode* temp;
    front = 0;
    rear = 0;
    quene[rear++] = root;
    while(rear != front){
        flag = 0;
        centnum = rear - front;
        while(centnum){
            temp = quene[front++];
            if(temp->left != NULL){
                quene[rear++] = temp->left;
            }
            if(temp->right != NULL){
                quene[rear++] = temp->right;
            }
            if(temp->val == x||temp->val == y){
                ++flag;
            }
            if(flag == 2) return true;
            if(temp->left != NULL && temp->right != NULL){
                if((temp->left->val == x && temp->right->val == y)||(temp->left->val == y)&&(temp->right->val == x)){
                    return false;
                }
            }
            --centnum;
        }
    }
    return false;
}