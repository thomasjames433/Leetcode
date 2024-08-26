/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void po(struct Node* root,int *a,int* rs){
    if(root){
        for(int i=0;i<root->numChildren;i++)
            po(root->children[i],a,rs);
        a[(*rs)++]=root->val;
    }
}

int* postorder(struct Node* root, int* rs) {
    int *a=(int *)malloc(10005*sizeof(int));
    *rs=0;
    po(root,a,rs);
    return a;
}