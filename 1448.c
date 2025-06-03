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
        void getcount(TreeNode*root, int max, int *x){
            if (!root)
                return ;
            
            if(root->val>=max){
                (*x)++;
                max= root->val;
            }
            getcount(root->left,max,x);
            getcount(root->right,max,x);
        }
    
        int goodNodes(TreeNode* root) {
            int x=0;
            getcount(root,root->val,&x);
            return x;
        }
    };