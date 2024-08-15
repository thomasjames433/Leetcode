int missingNumber(int* num, int numsize) {
    int sum=0;
    for(int i=1;i<=numsize;i++)
    sum= sum+num[i-1]-i;
    return -sum;
}
/*
    int sum=(numsize+1)*(numsize)/2;
    for(int i=0;i<numsize;i++)
    sum-=num[i];
    return sum;
*/