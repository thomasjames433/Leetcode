/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

void enqueue(struct Node **q1,int *front,int*rear,struct Node *abc){
    if(*rear==-1)
        (*front)++;
    (*rear)++;
    q1[*rear]=abc;
}

void dequeue(int*front){
    (*front)++;
}

struct Node* connect(struct Node* root) {
    if(!root)
        return NULL;
	struct Node **q1=(struct Node**)malloc(6000*sizeof(struct Node *));
    int front=-1;int rear=-1;
    enqueue(q1,&front,&rear,root);
    while(front<=rear){
        int level=rear-front+1;
        struct Node **levelNodes=(struct Node **)malloc(level*sizeof(struct Node *));
        int f=-1;int r=-1;
        for(int i=0;i<level;i++){
            struct Node *temp=q1[front];
            levelNodes[i]=temp;
            if(temp->left){
                enqueue(q1,&front,&rear,temp->left);
            }
            if(temp->right){
                enqueue(q1,&front,&rear,temp->right);
            }
            dequeue(&front);
        }
        for(int i=0;i<level-1;i++){
            levelNodes[i]->next=levelNodes[i+1];
        }
    }
    return root;
}

Better Method

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

void enqueue(struct Node **q1,int *front,int*rear,struct Node *abc){
    if(*rear==-1)
        (*front)++;
    (*rear)++;
    q1[*rear]=abc;
}

void dequeue(int*front){
    (*front)++;
}

struct Node* connect(struct Node* root) {
    if(!root)
        return NULL;
	struct Node **q1=(struct Node**)malloc(6000*sizeof(struct Node *));
    int front=-1;int rear=-1;
    enqueue(q1,&front,&rear,root);
    while(front<=rear){
        int level=rear-front+1;
        struct Node *prev=NULL;
        for(int i=0;i<level;i++){
            struct Node *temp=q1[front];
            
            if(temp->left){
                if(prev)
                    prev->next=temp->left;
                prev=temp->left;
                enqueue(q1,&front,&rear,temp->left);
                
            }
            if(temp->right){
                if(prev)
                    prev->next=temp->right;
                prev=temp->right;
                enqueue(q1,&front,&rear,temp->right);
            }
            dequeue(&front);
        }
    }
    return root;
}