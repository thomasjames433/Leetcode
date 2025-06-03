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
        vector<vector<int>> levelOrder(TreeNode* root) {
            queue<TreeNode*>q;
            vector <vector<int>>v;
            if (!root)
                return v;
            q.push(root);
            vector<int>v1={};
    
            while (1){
                v1={};
                int size=q.size();
                while (size--){
                    TreeNode *x= q.front();
                    v1.push_back(x->val);
                    if(x->left){
                        q.push(x->left);
                    }
                    if(x->right){
                        q.push(x->right);
                    }
                    q.pop();
                }
                if(v1.empty())
                    return v;
                else 
                    v.push_back(v1);
    
            }
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
