/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void enqueue(struct TreeNode** q,int *f,int *r,struct TreeNode* abc){
    if(*r==-1)
        (*f)++;
    (*r)++;
    q[*r]=abc;
}

void dequeue(int *f){
    (*f)++;
}

int** zigzagLevelOrder(struct TreeNode* root, int* rs, int** rcs) {
    struct TreeNode**q=(struct TreeNode**)malloc(2000*sizeof(struct TreeNode*));
    
    int**ret=(int**)malloc(2000*sizeof(int*));
    *rcs=(int*)malloc(2000*sizeof(int));
    *rs=0;
    if(!root)
        return ret;
        
    int f=-1;int r=-1;
    int check=0;
    enqueue(q,&f ,&r,root);
    
    while(f<=r){
        
        int level=r-f+1;
        (*rcs)[check]=level;
        struct TreeNode**levelnodes=(struct TreeNode**)malloc(level*sizeof(struct TreeNode*));
        
        for(int i=0;i<level;i++){
            struct TreeNode *temp=q[f];
            levelnodes[i]=temp;
            if(temp->left){
                enqueue(q,&f,&r,temp->left);
            }
            
            if(temp->right){
                enqueue(q,&f,&r,temp->right);
            }
            dequeue(&f);
        }
        int *a=(int*)malloc(level*sizeof(int));
        
        if(check%2==0){
            for(int i=0;i<level;i++)
                a[i]=levelnodes[i]->val;
        }
        
        else if(check%2==1){
            for(int i=0;i<level;i++)
                a[i]=levelnodes[level-1-i]->val;
        }

        (*rs)++;
        ret[(check)++]=a;

    }
    return ret;
}