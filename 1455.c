int isPrefixOfWord(char* sentence, char* word) {
    int n=strlen(sentence);
    int m=strlen(word);
    int w=0;
    for(int i=0;i<n;i++){
        w++;
        if(sentence[i]==word[0]){
            i++;
            int j;
            for(j=1;j<m;j++){
                if(i==n)
                    return -1;
                if(sentence[i]!=word[j])
                    break;
                i++;
            }
            if(j==m)
                return w;
        }
        while(sentence[i]!=' '){
            i++;
            if(i==n)
                return -1;
        }
    }
    return -1;
}