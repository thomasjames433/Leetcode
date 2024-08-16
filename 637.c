/**
 * Definition for a binary tree TreeNode.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void enqueue(struct TreeNode **q1,int *front,int *rear,struct TreeNode *root){
    if(*front==-1)
        (*front)++;
    (*rear)++;
    q1[*rear]=root;
}

void dequeue(int *front){
    (*front)++;
}

double* averageOfLevels(struct TreeNode* root, int* returnsize) {
    struct TreeNode**q1=(struct TreeNode**)malloc(10005*sizeof(struct TreeNode *));
    double *list=(double*)malloc(10005*sizeof(double));
    *returnsize=0;
    if(root==NULL)    
        return list;
    
    list[*returnsize]=root->val;
        *returnsize=1;
    int front=-1;int rear=-1;
    enqueue(q1,&front,&rear,root);
    
    while(front<=rear){
        int level=rear-front+1;
        int x=0;
        double a=0;
        
        for(int i=0;i<level;i++){
            struct TreeNode *temp=q1[front];
            if(temp->left){
                a+=temp->left->val;
                enqueue(q1,&front,&rear,temp->left);
                x++;
            }
            if(temp->right){
                a+=temp->right->val;
                x++;
                enqueue(q1,&front,&rear,temp->right);
            }
            dequeue(&front);
        }
        list[*returnsize]=a/x;
        (*returnsize)++;
    }
    (*returnsize)--;
    return list;
}