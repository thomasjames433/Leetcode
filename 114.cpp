/**
 * Definition for a binary tree TreeNode.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
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
    void flatten(TreeNode* root) {
        if(!root)   
            return ;
        flatten(root->left);
        flatten(root->right);
        TreeNode*temp=root->right;
        root->right=root->left;
        root->left=NULL;
        TreeNode * a=root;
        while(a->right)
            a=a->right;
        a->right=temp;
        return ;
    }
};
void flatten(struct TreeNode* root) {
    if(!root)
        return;
    flatten(root->left);
    flatten(root->right);

    struct TreeNode *temp=root->right;
    root->right=root->left;
    root->left=NULL;
    struct TreeNode *a=root;
    while(a->right)
        a=a->right;
    a->right=temp;

}