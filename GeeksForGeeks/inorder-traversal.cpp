/*
//  Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int data) {
        data = data;
        left = NULL;
        right = NULL;
    }
};
*/
// MORRIS
class Solution{
    public:
        vector<int>inOrder(Node*root){
            vector<int>ret;
            Node* curr=root;
            while(curr){
                if(curr->left==NULL){
                    ret.push_back(curr->data);
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
                        prev->right=NULL;
                        ret.push_back(curr->data);
                        curr=curr->right;
                    }
                }
            }
            return ret;
        }
};