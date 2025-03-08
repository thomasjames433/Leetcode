int findMaxConsecutiveOnes(int* num, int n) {
    int max=0;
    int c=0;
    for(int i=0;i<n;i++){
        if(num[i]==1){
            c++;
            if(max<c)
                max=c;
        }
        else
            c=0;
    }
    return max;
}