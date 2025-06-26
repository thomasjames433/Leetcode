/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*>ret={nullptr,nullptr};
        find(root,ret[0],ret[1],key);
        return ret;
        
    }
    void find(Node*root,Node* &pre,Node*& suc, int key){
        if(!root)
            return;
        if(key<root->data){
            suc=root;
            find(root->left,pre,suc,key);
        }
        else if(key>root->data){
            pre=root;
            find(root->right,pre,suc,key);
        }
        else{
            Node *temp =root->left;
            if (temp){
                while(temp->right)
                    temp=temp->right;
                pre=temp;
            }
            temp=root->right;
            if (temp){
                while(temp->left)
                    temp=temp->left;
                suc=temp;
            }
        }
        return;
    }
};