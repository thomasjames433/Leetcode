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

 struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0),left(nullptr),right(nullptr){}

 };
 

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        auto it=stt.find(root->val);
        if (it!=stt.end())
            return true;
        stt.insert(k-root->val);
        return findTarget(root->left,k) || findTarget(root->right,k);
    }
private:
    unordered_set<int>stt;
};