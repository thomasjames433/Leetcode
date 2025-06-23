/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
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
    bool isSymmetric(TreeNode* root) {
        return issame(root->left,root->right);
    }
    bool issame(TreeNode*p,TreeNode*q){
        if (!p || !q)
            return !p && !q;
        if(p->val!=q->val)
            return 0;
        return issame(p->left,q->right) && issame(p->right,q->left);
    }
};

bool compare(struct TreeNode* a,struct TreeNode* b){
    if(a==NULL && b==NULL)
    return true;
    else if(a==NULL || b==NULL)
    return false;
    else if(a->val!=b->val)
    return false;
    return compare(a->left,b->right) && compare(a->right,b->left);
}
bool isSymmetric(struct TreeNode* root) {
    return compare(root->left,root->right);
}