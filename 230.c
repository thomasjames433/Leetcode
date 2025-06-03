/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int inorder(struct TreeNode* root, int *k){
    if(!root)
    return -1;
    int a=inorder(root->left,k);
    if(*k==0)
        return a;
    (*k)--;
    if(*k==0)
        return root->val;
    return inorder(root->right,k);

}

int kthSmallest(struct TreeNode* root, int k) {
    int x=k;
    return inorder(root,&x);
}

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
        void inorder(TreeNode*root, int *k, int *fin){
            if(!root || *k<=0hj)
                return;
            inorder(root->left,k,fin);
            (*k)--;
            if(*k==0)
                *fin=root->val;
            inorder(root->right,k,fin);
            return ;
        }
        int kthSmallest(TreeNode* root, int k) {
            int x= k;int fin;
            inorder(root,&x,&fin);
            return fin;
        }
    };