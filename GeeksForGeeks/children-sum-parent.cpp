/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to check whether all nodes of a tree have the dataue
    // equal to the sum of their child nodes.
    int isSumProperty(Node *root) {
        
        if(!root->left && !root->right)
            return 1;
        int l=checksum(root->left);
        int r=checksum(root->right);
        if(l==-1 || r==-1)
            return 0;
        if(root->data != r+l)
            return 0;
        return 1;
    }
    int checksum(Node *root) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return root->data;
        int l=checksum(root->left);
        int r=checksum(root->right);
        if(l==-1 || r==-1)
            return -1;
        
        if(root->data != r+l)
            return -1;
        return root->data;
    }
};