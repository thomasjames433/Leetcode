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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ret;
        inorder(ret,root);
        return ret;
    }
    void inorder(vector<int>&ret,TreeNode*root){
        if(!root)
            return;
        inorder(ret,root->left);
        ret.push_back(root->val);
        inorder(ret,root->right);
    }
};
void inorder(struct TreeNode *root, int **A,int *returnsize){
    if(root!=NULL){
        inorder(root->left, A,returnsize);
        (*A)[(*returnsize)]=root->val;
        (*returnsize)++;
        inorder(root->right,A,returnsize);
    }
}
int* inorderTraversal(struct TreeNode* root, int* returnsize) {
    int *A=(int*)malloc(100*sizeof(int));
    *returnsize=0;
    inorder(root,&A,returnsize);
    return A;
}