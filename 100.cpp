// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     struct TreeNode *left;
//  *     struct TreeNode *right;
//  * };
//  */

//  /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(!p || !q){
//             return !p &&!q;
//         }
//         if(p->val!=q->val)
//             return 0;
//         return isSameTree(p->left,q->left)  && isSameTree(p->right,q->right);
//     }
// };


// bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//     if(p==NULL && q==NULL)
//     return true;
//     else if((p!=NULL && q==NULL) || (q!=NULL && p==NULL) || p->val!=q->val )
//     return false;
//     return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
// }

#include <bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p || !q){
            return !p &&!q;
        }
        if(p->val!=q->val)
            return 0;
        return isSameTree(p->left,q->left)  && isSameTree(p->right,q->right);
    }
};

TreeNode* createsample(vector<int>v){
    TreeNode *root= new TreeNode(v[0]);
    root->left= new TreeNode(v[1]);
    root->right= new TreeNode(v[2]);
    return root;
}

int main(){
    vector <int> v;
    for(int i=0;i<3;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    TreeNode * t1=createsample(v);
    v.clear();
    for(int i=0;i<3;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    TreeNode * t2=createsample(v);

    Solution sol;
    cout<< sol.isSameTree(t1,t2);
    return 1;
}