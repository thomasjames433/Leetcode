/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include <string.h>
int* minOperations(char* box, int* returnSize) {
    int len=0;
    len=strlen(box);
    *returnSize=len;
    int* a=(int*)malloc(len*sizeof(int));
    for(int i=0;i<len;i++)
    *(a+i)=0;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(*(box+j)=='1'){
                *(a+i)+=j-i;
            }
            if(*(box+i)=='1')
            *(a+j)+=j-i;
        }
    }
    return a;
}