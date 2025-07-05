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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        int h= get_height(root,diameter);
        return diameter;
    }
    int get_height(TreeNode*root,int &diameter){
        if(!root)
            return 0;
        int x= get_height(root->left,diameter);
        int y= get_height(root->right,diameter);

        diameter=max(diameter,x+y);
        return max(x+1,y+1);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a,int b){
    if(a>b)
    return a;
    return b;
}

int height(struct TreeNode *root,int *diameter){
    if(root==NULL)
    return 0;

    else{
        int lh=height(root->left,diameter);
        int rh=height(root->right,diameter);
        *diameter=max(*diameter,lh+rh);    // if we put 1+lh+rh
        return 1+ max(lh,rh);
    }
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter=0;
    height(root,&diameter);
    return diameter;                    // we return diameter -1
}