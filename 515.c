/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void enq(struct TreeNode**q,int *r,struct TreeNode* root){
    q[++(*r)]=root;
}

void deq(int *f){
    (*f)++;
}

int* largestValues(struct TreeNode* root, int* rs) {
    *rs=0;
    if (!root)
        return NULL;
    struct TreeNode**q=(struct TreeNode**)malloc(10000*sizeof(struct TreeNode*));
    int f=0;int r=-1;
    int *a=(int *)calloc(1,sizeof(int));
    enq(q,&r,root);
    
    while(f<=r){
        int level=r-f+1;
        int max=q[f]->val;
        (*rs)++;
        a=(int*)realloc(a,(*rs)*sizeof(int));
        
        for(int i=0;i<level;i++){
            struct TreeNode*temp=q[f];
            if(max<temp->val)
                max=temp->val;
            if (temp->right){
                enq(q,&r,temp->right);
            }
            
            if (temp->left){
                enq(q,&r,temp->left);
            }
            f++;
        }
        a[(*rs)-1]=max;
    }
    return a;
}