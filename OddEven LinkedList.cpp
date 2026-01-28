class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode *Dummy=new ListNode();
        Dummy->next=head;
        ListNode *odd=nullptr;
        ListNode *even=nullptr;
        ListNode *Connection=nullptr;
        ListNode *temp=head;
        int cnt=1;
        while(temp!=nullptr){
            //ListNode *nextnode=temp->next;
            if(cnt%2!=0){
                if(odd==nullptr){
                    odd=temp;
                }
                else{
                    odd->next=temp;
                    odd=odd->next;
                }
            }
            else{
                if(even==nullptr){
                    even=temp;
                    Connection=temp;
                }
                else{
                    even->next=temp;
                    even=even->next;
                }
            }
            cnt++;
            temp=temp->next;
        }
        odd->next=Connection;
        even->next=nullptr;
        return Dummy->next;

    }
};
