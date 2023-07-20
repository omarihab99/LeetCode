/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newHead = new ListNode(0,nullptr);
        ListNode* newTemp = new ListNode(0);
        newTemp->next = newHead;
        int sum=0;
        while(head){
            if(head->val == 0 && sum!=0){
                ListNode* node = new ListNode(sum, nullptr);
                newTemp->next->next = node;
                newTemp->next = node;
                sum=0;
            }
            else{
                sum+=head->val;
            }
            head = head->next;
            // cout<<head->val;
        }
        return newHead->next;
    }
};