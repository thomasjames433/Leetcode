/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void getsub(int**retarray,int*nums,int size,int i,int **rcs,int *sub,int len,int *counter){
    if(i==size || (*counter)==pow(2,size)-2)
        return;
    // printf("%d ",i);
    
    int *subnext=(int*)malloc((len+1)*sizeof(int));
    for(int j=0;j<len;j++)
        subnext[j]=sub[j];
    subnext[len]=nums[i];
    retarray[*counter]=subnext;
    for(int x=0;x<len+1;x++)
        printf("%d ",retarray[*counter][x]);
    printf("\n");
    (*rcs)[(*counter)++]=len+1;
    // if(i==size-1 || *counter==pow(2,size)-1){
    //     printf("HEY");
    //     return;
    // }
    getsub(retarray,nums,size,i+1,rcs,subnext,len+1,counter);
    getsub(retarray,nums,size,i+1,rcs,sub,len,counter);
    return;
}

int** subsets(int* nums, int size, int* rs, int** rcs) {
    *rs=pow(2,size);
    int **retarray=(int **)malloc((*rs)*sizeof(int*));
    *(rcs) = (int*)calloc((*rs) , sizeof(int));
    int i=0;
    int len=0;
    int counter=0;
    getsub(retarray,nums,size,i,rcs,NULL,len,&counter);
    (*rcs)[*rs-2]=1;
    retarray[*rs-2]=(int*)malloc(1*sizeof(int));
    retarray[*rs-2][0]=nums[size-1];
    return retarray;
}