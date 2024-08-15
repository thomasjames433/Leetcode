/**
 * Definition for a binary tree Node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *createnode(int val){
    struct TreeNode *new=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    new->val=val;
    new->left=NULL;
    new->right=NULL;
    return new;
}
void maketree(struct TreeNode *root,int in[], int pre[], int *x, int first, int last, int n){
    if((*x)>n || first>last)
    return;
    int cur=first;
    while( cur<=last && in[cur]!=pre[*x])
    cur++;
    if(cur>last)
    return ;

    root->val=pre[*x];
    (*x)++;
    if(cur>first){
        root->left=createnode(-1);
        maketree(root->left,in,pre,x,first,cur-1,n);
    }
    if(cur<last){
        root->right=createnode(-1);
        maketree(root->right,in,pre,x,cur+1,last,n);
    }
}

struct TreeNode* buildTree(int* preorder, int preordersize, int* inorder, int inordersize) {
    struct TreeNode *root=createnode(-1);
    int x=0;
    maketree(root,inorder,preorder,&x,0,preordersize-1,preordersize);
    return root;
}