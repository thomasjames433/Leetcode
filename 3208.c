int numberOfAlternatingGroups(int* color, int n, int k) {
    int x=1;
    int count=0;
    for(int i=1;i<n;i++){
        if(color[i]!=color[i-1]){
            x++;
        }
        else{
            x=1;
        }
        if(x==k){
            count++;
            x--;
        }
    }
    if(color[0]!=color[n-1]){
        x++;
        if(x==k){
            count++;
            x--;
        }
        for(int i=1;i<k-1;i++){
            if(color[i]!=color[i-1]){
                x++;
            }
            else{
                break;
            }
            if(x==k){
                count++;
                x--;
                printf("%d ",i);
            }           
        }
    }
    return count;
}