/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** spiralMatrix(int m, int n, struct ListNode* head, int* rs, int** rcs) {
    int** ret=(int**)malloc(m*sizeof(int*));
    *rs=m;
    *rcs=(int*)malloc(m*sizeof(int));
    for(int i=0;i<m;i++){
        (*rcs)[i]=n;
        int *col=(int *)malloc(n*sizeof(int));
        for(int j=0;j<n;j++)
            col[j]=-1;
        ret[i]=col;
    }
    int i=0;
    int j=0;
    while(head){
        while(j<n && ret[i][j]==-1){
            ret[i][j]=head->val;
            head=head->next;
            j++;
            if(!head)
                return ret;
        }j--;i++;

        while(i<m && ret[i][j]==-1){
            ret[i][j]=head->val;
            head=head->next;
            i++;
            if(!head)
                return ret;
        }i--;j--;

        while(j>-1 && ret[i][j]==-1){
            ret[i][j]=head->val;
            head=head->next;
            j--;
            if(!head)
                return ret;
        }
        j++;i--;

        while(ret[i][j]==-1){
            ret[i][j]=head->val;
            head=head->next;
            i--;
            if(!head)
                return ret;
        }
        j++;i++;

    }
    return ret;
}