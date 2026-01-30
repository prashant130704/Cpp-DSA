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
    ListNode* Reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode *curr=head;
        while(curr!=nullptr){
            ListNode* nextnode = curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1=Reverse(l1);
        ListNode* head2=Reverse(l2);
        int sum=0;
        int carry=0;
        ListNode* head=nullptr;
        ListNode* tail=nullptr;
        while(head1!=nullptr || head2!=nullptr || carry!=0){
            if(head1!=nullptr && head2!=nullptr){
                sum=head1->val+head2->val+carry;
                carry=sum/10;
                sum=sum%10;
                head1=head1->next;
                head2=head2->next;
            }
            else if(head1==nullptr && head2!=nullptr){
                sum=head2->val+carry;
                carry=sum/10;
                sum=sum%10;
                head2=head2->next;
            }
            else if(head2==nullptr && head1!=nullptr){
                sum=head1->val+carry;
                carry=sum/10;
                sum=sum%10;
                head1=head1->next;
            }
            else{
                sum=carry;
                carry=0;
            }

            ListNode* newnode = new ListNode(sum);
            newnode->next=nullptr;
            if(head==nullptr){
                head=newnode;
                tail=newnode;
            }
            else{
                tail->next=newnode;
                tail=newnode;
            }
        }
        ListNode* result=Reverse(head);
        return result;
    }
};
