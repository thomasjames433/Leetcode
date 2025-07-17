MERGE SORT

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

    ListNode* merge(ListNode* tempa,ListNode*tempb){
        ListNode*head=nullptr;
        ListNode*headtemp=nullptr;
        while(tempa!=nullptr && tempb!=nullptr){
            if(tempa->val<tempb->val){
                if(!head){
                    head=tempa;
                    headtemp=head;
                }
                else{
                    headtemp->next=tempa;
                    headtemp=headtemp->next;
                
                }
                tempa=tempa->next;
            }
            else{
                if(!head){
                    head=tempb;
                    headtemp=head;
                }
                else{
                    headtemp->next=tempb;
                    headtemp=headtemp->next;
                
                }
                tempb=tempb->next;
            }
        }
        while(tempa!=nullptr){
            if(!head){
                head=tempa;
                headtemp=tempa;
            }
            else{
                headtemp->next=tempa;
                headtemp=headtemp->next;
            }
            tempa=tempa->next;
        }
        while(tempb!=nullptr){
            if(!head){
                head=tempb;
                headtemp=tempb;
            }
            else{
                headtemp->next=tempb;
                headtemp=headtemp->next;
            }
            tempb=tempb->next;
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len=lists.size();
        if(len==0)
            return nullptr;
        while(len>1){
            vector<ListNode*>temp;
            len=lists.size();
            if(len%2==1)
                temp.push_back(lists[len-1]);
            for(int i=0;i<len/2;i++){
                temp.push_back(merge(lists[2*i],lists[2*i+1]));
            }
            lists=temp;
        }
        return lists[0];
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** list, int n) {
    struct ListNode*head,*temp;
    head=NULL;

    if(n==0)
        return NULL;
    
    while(1){
        int min=0;
        while(!list[min]){
            min++;
            if(min>=n)
                return head;
        }
        for(int i=0;i<n;i++){
            if(list[i]){
                if(list[i]->val<list[min]->val)
                    min=i;
            }
        }
        if(!head){
            head=list[min];
            list[min]=list[min]->next;
            temp=head;
        }
        else{
            temp->next=list[min];
            list[min]=list[min]->next;
            temp=temp->next;
        }
    }
    return head;
}