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
    bool isValidBST(TreeNode* root) {
            return checkval(root,LONG_MIN,LONG_MAX);
    }
    bool checkval(TreeNode * root,long min,long max){
        if(!root)
            return 1;
        if(root->val<=min || root->val>=max)
            return 0;
        return checkval(root->right,root->val,max) & checkval(root->left,min,root->val);
    }
};

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
    
        bool check(TreeNode*root, long int min, long int max){
            if(!root)
                return 1;
            if(root->val <= min || root->val >=max)
                return 0;
            return check(root->left, min, root->val) && check(root->right, root->val, max);
        }
        bool isValidBST(TreeNode* root) {
            return check(root,LONG_MIN, LONG_MAX);      
        }
    };