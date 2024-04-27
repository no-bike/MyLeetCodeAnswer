/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNodes(struct ListNode* head) {
    struct ListNode* stcak[100000];
    int i = 0;
    struct ListNode* temp;
    temp = head;
    while(temp != NULL){
        if(i == 0){
            stcak[i] = temp;
            ++i;
        }
        if(i != 0 ){
            while( temp->val > stcak[i-1]->val){
                --i;
                if(i == 0) break;
            }
            stcak[i] = temp;
            ++i;
            temp = temp->next;            
        }
    }
    head = stcak[0];
    for(int j = 1;j<i;++j){
        stcak[j-1]->next = stcak[j];
    }
    return head;

}