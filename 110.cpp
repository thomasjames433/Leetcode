/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return 1;
        int l= getheight(root->left,0);
        if(l==-1 )
            return 0;
        int r=getheight(root->right,0); 
        if(r==-1)
            return 0;
        if(abs(r-l)>1)
            return 0;
        return true;
    }
    int getheight(TreeNode*root,int curh){
        if(!root){
            return curh;
        }
        int l= getheight(root->left,curh+1);
        if(l==-1 )
            return -1;
        int r=getheight(root->right,curh+1); 
        if(r==-1)
            return -1;
        if(abs(r-l)>1)
            return -1;
        return max(l,r);
        
    }
};