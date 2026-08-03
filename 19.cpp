struct ListNode{
    int val;
    ListNode * next;
    ListNode(): val(0),next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}

};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur =head;
        int count=0;
        while(cur!=nullptr){
            cur=cur->next;
            count++;
        }
        count-=n;
        cur=head;
        ListNode* prev=nullptr;
        for(int i=0;i<count;i++){
            prev=cur;
            cur=cur->next;
        }
        if (prev!=nullptr){
            if(cur!=nullptr)
                prev->next= cur->next;
            else
                prev->next=nullptr;
        }
        else{
            head=head->next;
        }
        return head;
    }
};