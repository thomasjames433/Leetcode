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
private:
    int getHeight(TreeNode*root, int &maxheight){
        if(root==nullptr)
            return 0;
        int x= getHeight(root->left,maxheight);
        int y= getHeight(root->right,maxheight);
        if(x+y>maxheight)
            maxheight=x+y;
        return 1+max(x,y);

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxheight=0;
        getHeight(root,maxheight);
        return maxheight;
    }
};