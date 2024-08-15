/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* num, int numsize, int target, int* returnsize) {
    *returnsize=0;
    int i=0;
    numsize--;
    
    while(i<numsize){

        if(num[i]+num[numsize]==target){
            int *A=(int*)malloc(2*sizeof(int));
            A[0]=i+1;
            A[1]=numsize+1;
            *returnsize=2;
            return A;
        }
        else if(num[i]+num[numsize]>target)
        numsize--;
        else
        i++;

    }
    return 0;
    
}