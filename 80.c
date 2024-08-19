
int removeDuplicates(int* num, int numsize) {
    int x=0;int i=0;int y=1;
    while(i<numsize-1){
        if(num[i]==num[i+1]){
            x++;
            if(x<2){
            num[y]=num[i+1];
            y++;
        }
        }
        
        
        if(num[i]!=num[i+1]){
            x=0;
            num[y]=num[i+1];
            y++;
        }
        i++;
    }
    return y;
}    