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
    int widthOfBinaryTree(TreeNode* root) {
        int maxwidth=1;
        queue<pair<TreeNode*,long long int>>q;
        q.push({root,1});
        while(!q.empty()){
            int levelsize=q.size();
            int start=q.front().second;
            int end=q.back().second;
            maxwidth=max(maxwidth,(end-start+1));
            for(int i=0;i<levelsize;i++){
                auto temp=q.front().first;
                auto pos=q.front().second-start;
                q.pop();
                if(temp->left)
                    q.push({temp->left,2*pos});
                if(temp->right)
                    q.push({temp->right,2*pos+1});
            }
        }
        return maxwidth;
    }
};