/**
 * Note: The returned array must be malloced, assume caller calls free().
 */              
int* productExceptSelf(int* num, int numsize, int* returnsize) {
    int *ret=(int*)malloc(numsize*(sizeof(int)));
    int first=1;
    for(int i=0;i<numsize;i++){
        ret[i]=first;
        first*=num[i];
    }    
    first=num[numsize-1];
    
    for(int i=numsize-2;i>=0;i--){
        ret[i]*=first;
        first*=num[i];
        // printf("%d ",ret[i]);
    }
    *returnsize=numsize;
    return ret;
}