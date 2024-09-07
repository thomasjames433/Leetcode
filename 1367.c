/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isp(struct ListNode* head, struct TreeNode* root){
    if(!head)
        return 1;
    if(!root)
        return 0;
    if(head->val!=root->val)
        return 0;
    else{
        bool a;
        a=isp(head->next,root->left);
        if(a)
            return a;
        a=isp(head->next,root->right);
        if(a)
            return a;
    }
    return 0;
}

bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    if(!head)
        return 1;
    if(!root)
        return 0;
    bool a=isp(head,root);
    if(a)
        return a;
    return isSubPath(head,root->left) || isSubPath(head,root->right);
}
