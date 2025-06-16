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

    int maxPathSum(TreeNode* root) {
        int max1=root->val;
        int x= maxpath(root,max1);
        return max1;
    }

    int maxpath(TreeNode*root, int&max1){
        if(!root)
            return 0;
        int x=maxpath(root->left,max1);
        int y=maxpath(root->right,max1);
        int temp=max({root->val,root->val+x,root->val+y,root->val+x+y});
        if(temp>max1)
            max1=temp;
        return max({root->val,root->val+x,root->val+y});
    }
};


int min(int a,int b){
    if(a>b)
        return b;
    return a;
}
 int getsum(struct TreeNode *root,int *total){
    int sum=0;
    if (root==NULL){
        return 0;
    }
    // else if(root->left==NULL && root->right==NULL){
    //     if(*total<root->val)
    //         *total=root->val;
    //     return root->val;
        
    // }
    else {
        int a=getsum(root->right,total);
        int b=getsum(root->left,total);
        if(a>0 && b>0){
            
            sum= root->val+ a+b;
            if(sum>*total)
            *total=sum;
            sum=sum-min(a,b);
            }
        
        else if(a>0 && b<=0){
            sum= root->val+ a;
            if(sum>*total)
            *total=sum;
            }
        
        else if(a<=0 && b>0){
            sum= root->val+ b;
            if(sum>*total)
            *total=sum;
            }
        else{
            sum=root->val;
        if(sum>*total)
            *total=sum;}
        // sum=(sum)- getsum(root->right,total)-getsum(root->left,total);
        // sum=sum +max(getsum(root->right,total),getsum(root->left,total));
    }
    return sum;
}

int maxPathSum(struct TreeNode* root) {
    int total=INT_MIN;
    getsum(root,&total);
    return total;        
}