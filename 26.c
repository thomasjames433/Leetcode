int removeDuplicates(int* num, int numsize) {
    int x=1;
    int i=0;
    while(i<numsize-1){
        if(num[i]!=num[i+1]){
            num[x++]=num[i+1];
        }
        i++;
    }
    return x;
}