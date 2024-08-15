/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digit, int digitsize, int* returnsize) {
    for(int i=digitsize-1;i>=0;i--){
        if(digit[i]!=9){
            digit[i]++;
            break;
        }
        else{
            digit[i]=0;
            if(i==0){
                *returnsize=digitsize+1;
                int *digit=(int *)malloc(*returnsize*sizeof(int));
                digit[0]=1;
                int j=1;
                while(j<*returnsize){
                    *(digit+j)=0;
                    j++;
                }
                return digit;
            }
        }
    }
    *returnsize=digitsize;
    return digit;
}