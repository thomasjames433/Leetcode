// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    vector<int> preOrder(Node* root) {
        // code here
        vector<int>ret;
        Node*curr=root;
        while(curr){
            ret.push_back(curr->data);
            if(curr->left==NULL){
                curr=curr->right;
            }
            else{
                Node*prev=curr->left;
                while(prev->right && prev->right!=curr)
                    prev=prev->right;
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    ret.pop_back();
                    curr=curr->right;
                    prev->right=NULL;
                }
            }
        }
        return ret;
        
    }
};