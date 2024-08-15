/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* createnode(int data){
    struct TreeNode *new=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    new->val=data;
    new->left=NULL;
    new->right=NULL;
    return new;
}

struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    if(root1==NULL && root2==NULL)
    return NULL;
    else if(root1!=NULL && root2==NULL){
        return root1;
    }
    else if(root1==NULL && root2!=NULL){
        struct TreeNode *new=createnode(root2->val);
        new->left=mergeTrees(NULL,root2->left);
        new->right=mergeTrees(NULL,root2->right);
        return new;
    }
    else{
        root1->val+=root2->val;
        root1->left=mergeTrees(root1->left,root2->left);
        root1->right=mergeTrees(root1->right,root2->right);
    }
    return root1;
}

// Other method


struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    if(root1==NULL && root2==NULL)
    return NULL;
    else if(root1==NULL)
    return root2;
    else if(root2==NULL)
    return root1;

    root1->val+=root2->val;
    root1->left=mergeTrees(root1->left,  root2->left);
    root1->right=mergeTrees(root1->right, root2->right);
    return root1;
}