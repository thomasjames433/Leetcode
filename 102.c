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

void enqueue(struct TreeNode** q,int *front,int *rear,struct TreeNode*root){
    if(*front==-1 && *rear==-1)
        (*front)++;
    (*rear)++;
    q[*rear]=root;
}

void dequeue(int *front){
    (*front)++;
}

int** levelOrder(struct TreeNode* root, int* returnsize, int** csize) {
    struct TreeNode**q1=(struct TreeNode**)malloc(2005*sizeof(struct TreeNode*));
    int **ret=(int**)malloc(2005*sizeof(int*));
    *returnsize=0;

    if(!root)
        return ret;
    
    *csize=(int*)malloc(2005*sizeof(int));
    int front=-1;int rear=-1;
    enqueue(q1,&front,&rear,root);
    
    while(front<=rear){
        int level=rear-front+1;
        int *integers=(int*)malloc(level*sizeof(int));
    
        for(int i=0;i<level;i++){
            struct TreeNode*temp=q1[front];
            integers[i]=temp->val;
    
            if(temp->left)
                enqueue(q1,&front,&rear,temp->left);
    
            if(temp->right)
                enqueue(q1,&front,&rear,temp->right);
    
            dequeue(&front);
        }
    
        ret[*returnsize]=integers;
        (*csize)[*returnsize]=level;
        (*returnsize)++;
    }
    
    return ret;
}
