bool divideArray(int* num, int n) {
    int a[501];
    int y=0;
    for(int i=0;i<n;i++){
        if(a[num[i]]==1){
            y--;
            a[num[i]]=0;
        }
        else{
            y++;
            a[num[i]]=1;
        }
    }
    return !y;
}