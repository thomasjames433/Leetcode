/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    public:
    
        Node* newfunc(Node* head, Node * parent, Node* parentnext){
            head->prev=parent;
            Node*temp=head;
            while (temp->next){
                if(temp->child){
                    Node*t= temp->child;
                    temp->child=NULL;
                    temp->next=newfunc(t, temp, temp->next);
                }
                temp=temp->next;
            }
            temp->next=parentnext;
            if (parentnext){
                
                parentnext->prev=temp;
            }
            return head;
        }
    
        Node* flatten(Node* head) {
            Node *temp=head;
            while (temp){
                if (temp->child){
                    Node* t=temp->child;
                    temp->child=NULL;
                    temp->next=newfunc(t,temp, temp->next);
                }      
                temp=temp->next;
            }
            return head;
        }
    };