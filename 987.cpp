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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int,int>,multiset<int>>mpp;
        insertmap(root,mpp,0,0);
        vector<vector<int>>ret;
        
        map<int,vector<int>>indexcols;
        for(auto &[index,ms]:mpp)
            indexcols[index.first].insert(indexcols[index.first].end(),ms.begin(),ms.end());
        
        for(auto&[it,cols]:indexcols){
            ret.push_back(cols);
        }
        return ret;
    }
    void insertmap(TreeNode*root,map<pair<int,int>,multiset<int>>&mpp,int x,int y){
        if(!root)
            return;
        mpp[{x,y}].insert(root->val);
        insertmap(root->left,mpp,x-1,y+1);
        insertmap(root->right,mpp,x+1,y+1);
    }
};