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