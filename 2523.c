/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* closestPrimes(int left, int right, int* rs) {
    int *prime=(int*)calloc(right+1,sizeof(int));

    for(int i=2;i<right+1;i++){
        prime[i]=1;
    }
    for(int i=2;i<=sqrt(right);i++){
        if(prime[i]){
            for(int j=i*i;j<right+1;j+=i){
                prime[j]=0;
            }
        }
    }

    int*ret=(int*)malloc(2*sizeof(int));
    ret[0]=-1;
    ret[1]=-1;
    *rs=2;
    int num1;
    int num2;
    for(int i=left;i<right+1;i++){

        if(prime[i]){
            
            if(ret[1]==-1){

                if(ret[0]==-1){
                    ret[0]=i;
                    num1=i;
                }
                else{
                    ret[1]=i;
                    num2=i;
                }
            }
            else{
                num1=num2;
                num2=i;
                if(ret[1]-ret[0]>num2-num1){
                    ret[0]=num1;
                    ret[1]=num2;
                }
            }
        }

    }
    if(ret[1]==-1)
        ret[0]=-1;
    return ret;
}