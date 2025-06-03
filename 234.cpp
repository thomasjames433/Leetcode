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
        bool isPalindrome(ListNode* head) {
            stack<int> st;
            ListNode *slow,*fast;
            int c=0;
    
            slow=head;
            fast=head;
            st.push(slow->val);
            while(fast){
                if(fast->next){
                    fast=fast->next->next;
                    slow=slow->next;
                    st.push(slow->val);
                }
    
                if(! fast){
                    st.pop();
                    break;
                }
                if( !fast->next ){
                    st.pop();
                    slow=slow->next;
                    break;
                }
    
            }
            while(slow){
                int s=st.top();
                if (slow->val!=s)
                    return false;
                st.pop();
                slow=slow->next;
            }
    
            return true;
        }
    };