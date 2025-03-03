/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* transformArray(int* num, int n, int* rs) {
    int odd=0;
    int even=0;
    for(int i=0;i<n;i++){
        if(num[i]%2)
            odd++;
        else
            even++;
    }
    for(int i=0;i<even;i++)
            num[i]=0;
    for(int i=even;i<n;i++)
            num[i]=1;
    *rs=n;
    return num;
}