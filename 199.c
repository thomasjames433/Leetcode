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
void enqueue(struct TreeNode**root,int*front,int*rear,struct TreeNode*abc){
    if(*front==-1 && *rear==-1)
        (*front)++;
    (*rear)++;
    root[*rear]=abc;
}

void dequeue(int *front){
    (*front)++;
}

int* rightSideView(struct TreeNode* root, int* returnsize) {
    int *list=(int *)malloc(102*sizeof(int));
    if(root==NULL){
        *returnsize=0;
        return list;
    }
    struct TreeNode **q1=(struct TreeNode **)malloc(102*sizeof(struct TreeNode*));
    int front=-1;int rear=-1;
    list[0]=root->val;
    *returnsize=1;
    enqueue(q1,&front,&rear,root);
    while(front<=rear){
        
        int level=rear-front+1;
        for(int i=0;i<level;i++){
            struct TreeNode *temp=q1[front];
            if(temp->left)
                enqueue(q1,&front,&rear,temp->left);
            if(temp->right)
                enqueue(q1,&front,&rear,temp->right);
            dequeue(&front);
        }
        if(front<=rear){
            list[*returnsize]=q1[rear]->val;
            (*returnsize)++;
        }

    }
    return list;
}