#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
    
};

ListNode* createlist(vector<int>nums){
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int num:nums){
        curr->next = new ListNode(num);
        curr = curr->next;
    }
    return dummy->next;
}

class Solution{
    
    public:
        ListNode * add2numbers(ListNode*l1, ListNode*l2){
            ListNode* head=new ListNode(0);
            int x=0;
            ListNode* temp=head;
            while(l1 || l2 || x){
                if (l1){
                    x+=l1->val;
                    l1=l1->next;
                }
                if (l2){
                    x+=l2->val;
                    l2=l2->next;
                }
                temp->next=new ListNode(x%10);
                temp=temp->next;
                x/=10;
            }
            return head->next;
        }
};


int main(){
    char x;
    vector<int>v;
    while(cin.get(x) && x!='\n'){
        if (isdigit(x))
            v.push_back(x-'0'); 
        
    }
    ListNode*l1=createlist(v);
    v={};
    while(cin.get(x) && x!='\n'){
        if (isdigit(x))
            v.push_back(x-'0'); 
        
    }
    ListNode*l2=createlist(v);
    
    Solution sol;
    ListNode * result=sol.add2numbers(l1,l2);

    while(result!=nullptr){
        cout<<result->val<<" ";
        result=result->next;
    };
    cout<<"\n";
    return 0;

}