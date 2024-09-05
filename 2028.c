/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* missingRolls(int* roll, int m, int mean, int n, int* rs) {
    int sum=0;
    for(int i=0;i<m;i++)
        sum+=roll[i];
    int tot=mean*(m+n);
    tot-=sum;

    if(tot/n>6 || ((tot/n)==6 && tot%n !=0) || n>tot){
        *rs=0;
        int *ret=(int*)malloc(sizeof(int));
        return ret;
    }
    
    int *ret=(int*)malloc(n*sizeof(int));
    *rs=n;

    for(int i=1;i<=6;i++){
        if(n*i<tot){

        }
        else if(n*i==tot){
            for(int j=0;j<n;j++){
                ret[j]=i;
            }
            return ret;
        }
        else if(n*i>tot){
            int x=n*i-tot;
            printf("%d",x);
            for(int j=0;j<n;j++)
                ret[j]=i;
            int j=0;
            while(x!=0){
                ret[j]--;
                j++;x--;
            }
            return ret;
        }
    }
    return ret;
}