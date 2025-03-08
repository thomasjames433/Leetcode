int minimumRecolors(char* blocks, int k) {
    int count=0;
    int n=strlen(blocks);
    int min=0;
    for(int i=0;i<k;i++){
        if(blocks[i]=='W'){
            count++;
        }
    }
    min=count;
    for(int i=k;i<n;i++){
        if(blocks[i]=='B' && blocks[i-k]=='W'){
            count--;
            if(min>count)
                min=count;
        }
        else if(blocks[i]=='W' && blocks[i-k]=='B'){
            count++;
        }
    }
    return min;
}