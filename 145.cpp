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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        postorder(root,ret);
        return ret;
    }
    void postorder(TreeNode*root,vector<int>&ret){
        if(!root)
            return;
        postorder(root->left,ret);
        postorder(root->right,ret);
        ret.push_back(root->val);
    }
};

void ps(int *a,struct TreeNode* root, int* rs){
    if(root){
        ps(a,root->left,rs);
        ps(a,root->right,rs);
        a[(*rs)++]=root->val;
    }
    return;
}
int* postorderTraversal(struct TreeNode* root, int* rs) {
    int *a=(int *)malloc(102*sizeof(int));
    *rs=0;
    ps(a,root,rs);
    return a;
}