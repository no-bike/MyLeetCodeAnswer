/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
    struct Node* arr[4096];
    struct Node* temp = NULL;
    temp = root;
    if (!root)
        return NULL;
    int front, rear;
    front = 0;
    rear = 0;
    arr[rear++] = root;
    int flag = 1;
    while (rear != front) {
        temp = arr[front++];
        if (temp->left)
            arr[rear++] = temp->left;
        if (temp->right)
            arr[rear++] = temp->right;
        if (front + 1 == pow(2, flag)) {
            ++flag;
            temp->next = NULL;
        } else {
            temp->next = arr[front];
        }
    }
    return root;
}