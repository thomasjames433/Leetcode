int longestSubarray(int* num, int numsize) {
    int max=0; int c=1;int k=1;
    for(int i=1;i<numsize;i++){
        if(num[max]==num[i]){
            c++;
            if(k<c)
                k=c;
        }
        else if(num[max]<num[i]){
            max=i;
            c=1;
            k=1;
        }
        else{
            c=0;
        }
    }
    return k;
}