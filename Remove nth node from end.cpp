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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=1;
        ListNode* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
            cnt++;
        }
        temp=head;
        ListNode* prev=nullptr;

        if(!head) return 0;
        if(n>cnt) return head;
        if(n==0) return head;
        if(n==cnt){
            head=temp->next;
            return head;
        }

        int pos=cnt-n;
        cnt=1;
        while(cnt<=pos && temp!=nullptr){
            prev=temp;
            temp=temp->next;
            cnt++;
        }
        prev->next=temp->next;
        
        return head;
    }
};
