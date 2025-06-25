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
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode * right;
    TreeNode(int x): val(x),left(nullptr), right(nullptr){}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makebst(nums,0,nums.size()-1);
    }
    TreeNode* makebst(vector<int>&nums,int l, int r){
        if(r<l)
            return NULL;
        int mid=(l+r)/2;
        TreeNode *temp=new TreeNode(nums[mid]);
        temp->left=makebst(nums,l,mid-1);
        temp->right=makebst(nums,mid+1,r);
        return temp;
    }
};

void inorder(TreeNode*root){
    if(!root)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main(){
    vector <int> v;
    int x;
    cin >>x;
    while(x!=-1){
        v.push_back(x);
        cin>>x;
    }
    sort(v.begin(),v.end());
    Solution sol;
    TreeNode* root=sol.sortedArrayToBST(v);
    inorder(root);
}