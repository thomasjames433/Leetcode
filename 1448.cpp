#include <bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(): val(0),left(nullptr),right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode * left, TreeNode * right): val(x), left(left), right (right) {}
};

TreeNode *createTree(vector<int>nums){
    TreeNode*root=new TreeNode(nums[0]);
    int len=nums.size();
    queue<TreeNode*>q;
    q.push(root);
    for(int i=1;i<len;i++){
        auto cur=q.front();
        q.pop();
        cur->left=new TreeNode(nums[i]);
        q.push(cur->left);
        i++;
        if(i==len)
            break;
        cur->right= new TreeNode(nums[i]);
        q.push(cur->right);

    }
    return root;
}

class Solution {
// public:
private:
    void isgoodNode(TreeNode*root, int& count,int maxno){
        if(root==nullptr)
            return;
        if(root->val>=maxno)
            count++;
        isgoodNode(root->left,count,max(root->val,maxno));
        isgoodNode(root->right,count,max(root->val,maxno));
        return;
    }
public:
    int goodNodes(TreeNode* root) {
        
        int count=0;
        int &temp=count;
        int *ptr=&count;
        isgoodNode(root,count,root->val);
        return count;
    }
};

int main(){
    string line;
    getline(cin>>ws,line);
    stringstream ss(line);
    vector<int>nums;
    int val;
    while(ss>>val)
        nums.push_back(val);
    
    TreeNode *tree=createTree(nums);
    Solution s;
    cout<< s.goodNodes(tree);
    cout<<"\n";
    return 0;
}