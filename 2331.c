/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void val(struct TreeNode*root){
    if(root->left->val==2 || root->left->val==3) 
        val(root->left);
    if(root->right->val==2 || root->right->val==3)
        val(root->right);
        
    if((root->left->val==0 || root->left->val==1) && (root->right->val==0 || root->right->val==1)){
        if(root->val==2){
            root->val=(root->left->val||root->right->val);

        }
        else{
            root->val=(root->left->val&&root->right->val);
            
        }
    }
    
    

}
bool evaluateTree(struct TreeNode* root) {
    if(root->val==0 || root->val==1)
    return root->val;
    val(root);
    return root->val;
}
